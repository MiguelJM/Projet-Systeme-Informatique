%{
	#include <stdio.h>	
	#include <string.h>
	#include <stdbool.h>

	#include "symtab.h"
	#include "stack.h"

	int yylex(void);
	void yyerror(char *);

	char *address_Concat( char * );
	void insert_Instruction( char *, char *, char *, char *, char *, int );

	FILE *fp;	



#define instSIZE 8000 

	struct labelTable
	{
		char instruct[16];
		char  param1[16];		//@1
		char  param2[16];		//@2
		char  param3[16];		//@3
		char  comments[16];		//Comments of the line
	};

	struct errorTable
	{
		char error[128];
		int line;
	};

	;
	struct errorTable errTab[instSIZE];		//Stores found errors
	int ce = 0; //error counter

	struct labelTable labTab[instSIZE];		//Stores ASM instructions
	int cp = 0; //instruction counter
	int cp_Offset = 0; //Offset of the instruction counter

  	int tempCounter = 1; //Counter to determine if 0temp1 and 0temp2 are used

	struct stack if_stack;		//Keeps count of if statements to create labels
	struct stack else_stack;		//Keeps count of else statements to create labels
  	int if_lbl_count = 0; 		//Counter to determine the if labels to use

	char snum[5];		//To convert numbers to strings
	char auxString[32];	
	char auxString2[32];

	char last_if_type[8]; //Returns the last type of if retrieved	

	int auxNum;	

	char retrievedString[64]; //Used to store user input in the printf instructions.
	char stringPrinter[4]; 	//Used to create the printf instructions.
%}

%union {
	int nb;
	char * variable;
}

%start TestStart
%token tINT 
%token tMIN
%token tMAY  
%token tMINEQU
%token tMAYEQU
%token tEQU 
%token tDIF
%token tOR
%token tAND
%token tPO
%token tPF
%token tCO
%token tCF
%token tWHILE
%token tPV
%token tPLUS
%token <variable> tVAR tSTRING 
%token tE
%token tMAIN
%token tSOU
%token tMUL
%token tDIV
%token tPRINT
%token <nb> tNUM tIF
%token tV
%token tCONST
%token tGUILLEMETS
%token tELSE 

%type <variable> Cond CompareToken
%type <nb> Expr If Val

%right tE
%left tPLUS tSOU
%left tMUL tDIV


%%


TestStart	:	TestMessage
			;

TestMessage	: 	If		{printf("\n Succesful test");}
			;

Fonction	: 	tINT tVAR tPO Param tPF tCO Body tCF 	{printf("\n Fonction trouvee");}
			;
	
Param 		:	tINT tVAR tV Param 		{printf("\n Parametre trouve with ,");}
				| tINT tVAR				{printf("\n Parametre trouve without ,");}
			;
				
Body		:	Declar						
			|	If							
			|	While						
			|	Print							
			| 	Assign						
			|	Body Body							
			;

Assign 		:	tVAR tE tVAR tPV	{
										if( lookupType($1) != -1 && lookupType($3) != -1 ) //Both variables exist
										{									
										    fprintf(fp, "mov [%s], [%s]\n", $1, $3); 	//a = b
										    insert_Instruction( "mov", "eax", address_Concat($3), "", "", cp );
										    cp++;	
										    insert_Instruction( "mov", address_Concat($1), "eax", "", "", cp );
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant.\n" );
											errTab[ce].line = ce;
											ce++;
										}	
									}
			|	tVAR tE tNUM tPV	{
										if( lookupType($1) != -1 ) 	
										{									
										    fprintf(fp, "mov [%s], %d\n", $1, $3); 	//a = 4
										    
										    //convert num to string			
											sprintf(snum ,"%d" , $3);

										    insert_Instruction( "mov", "eax", snum, "", "", cp );
										    cp++;	
										    insert_Instruction( "mov", address_Concat($1), "eax", "", "", cp );
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant.\n" );
											errTab[ce].line = ce;
											ce++;
										}	
									}
			|	tVAR tE Expr tPV	{
										if(lookupType($1) != -1)	
										{									
										    fprintf(fp, "mov [%d], eax\n", lookup($1)); 	//a = Resultado

										    insert_Instruction( "mov", address_Concat($1), "eax", "", "", cp );
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant.\n" );
											errTab[ce].line = ce;
											ce++;
										}
									}
			;

If			:	If 			{
								//Erease the JMP else steps to build the else statement
								else_stack = push(if_lbl_count-1, else_stack);	//Insert else label value to 
								cp--;											//Erease the JMP ignore_else to write it later
							}
				Else 		
			| 	tIF tPO Cond tPF	{
									 	$1 = cp;		//If is inserted the execution of the body but its instruction is inserted here
										cp++;    		//Jx	
										cp++;			//JMP instruction goes here (used in case if statement is not approved)	
										cp++;			//If label goes here (used in case if statement is approved)

										if_stack = push(if_lbl_count, if_stack);		//Insert if label value to 	
										else_stack = push(if_lbl_count, else_stack);	//Insert else label value to 									
										if_lbl_count++;				
								}
				tCO Body tCF	{
									//convert num to string		

									auxNum = if_stack.stk[if_stack.top];	//take if label value from the stack	
									if_stack = pop(if_stack);					//pop the value	
									else_stack = pop(else_stack);				//pop the value	

									//create string if_lbl_n for Jx						//Assign the correct Jx: Je, Jg, etc... ************************
									strcpy( auxString, "if_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									insert_Instruction( last_if_type, auxString, "", "", "", $1 );		//Jx To ($1 stores the pointer before if began)

									//create string else_lbl_n for JMP
									strcpy( auxString, "else_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									insert_Instruction( "JMP", auxString, "", "", "", $1+1 );	//JMP TO		

									//create string if_lbl_n for if lbl
									strcpy( auxString, "if_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, ":" );
									insert_Instruction( auxString, "", "", "", "", $1+2 );	//If label	

									//Put a JMP to jump the else statement after if Body 			**********
									strcpy( auxString, "else_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, "_ignr" );
									insert_Instruction( "JMP", auxString, "", "", "", cp );	//Ignore else label	
									cp++;

									//create string else_lbl_n	for else lbl
									strcpy( auxString, "else_lbl_" );									
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, ":" );		//Else label
									insert_Instruction( auxString, "", "", "", "", cp );	//insert else label at the end of the if
									cp++;	

									//Put a JMP label at the end of the else body
									strcpy( auxString, "else_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, "_ignr:" );
									insert_Instruction( auxString, "", "", "", "", cp );	//Ignore else label	
									cp++;		
								}
			;

Else		: tELSE tCO Body tCF {		
									auxNum = else_stack.stk[else_stack.top];	//take if label value from the stack	
									else_stack = pop(else_stack);				//pop the value	

									//Put a JMP label at the end of the else body
									strcpy( auxString, "else_lbl_" );										
									sprintf(snum , "%d", auxNum);	
									strcat( auxString, snum );
									strcat( auxString, "_ignr:" );
									insert_Instruction( auxString, "", "", "", "", cp );	//If label	
									cp++;	
								}
			;

//TODO: conditions must be like: ((cond)||(cond))  or  ((cond)||((cond)||(cond)))

Cond		:	CondValueEAX CompareToken CondValueEBX 		{									
																insert_Instruction( "CMP", "eax", "ebx", "", "", cp );	//COMPARISSON	
																cp++;
																strcpy (last_if_type, $2);
															}
				|  tPO Cond tPF tOR  	{
												/**If true jump to if body**/

												//create string if_lbl_n for if lbl
												strcpy( auxString, "if_lbl_" );										
												sprintf(snum , "%d", if_lbl_count);	
												strcat( auxString, snum );		
												insert_Instruction( last_if_type, auxString, "", "", "", cp );	//IF	
												cp++;
										}
				 tPO Cond tPF 		{
				 						/**If true jump to if body**/

										//create string if_lbl_n for if lbl
										strcpy( auxString, "if_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( last_if_type, auxString, "", "", "", cp );	//IF	
										cp++;

										//jmp to else body 				
				 						
										//create string if_lbl_n for if lbl
										strcpy( auxString, "else_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( "JMP", auxString, "", "", "", cp );	//IF	
										cp++;

										$$=last_if_type;	//return last if 
									}
				| tPO Cond tPF tAND {
										/**If true jump to next if**/

										//create string if_lbl_n for if lbl
										strcpy( auxString, "$+4" );			
										insert_Instruction( last_if_type, auxString, "", "", "", cp );	//IF	
										cp++;

										//jmp to else body 				
				 						
										//create string if_lbl_n for if lbl
										strcpy( auxString, "else_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( "JMP", auxString, "", "", "", cp );	//IF	
										cp++;
									}
				tPO Cond tPF		{
										/**If true jump to if body**/

										//create string if_lbl_n for if lbl
										strcpy( auxString, "if_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( last_if_type, auxString, "", "", "", cp );	//IF	
										cp++;

										//jmp to else body 				
				 						
										//create string if_lbl_n for if lbl
										strcpy( auxString, "else_lbl_" );										
										sprintf(snum , "%d", if_lbl_count);	
										strcat( auxString, snum );		
										insert_Instruction( "JMP", auxString, "", "", "", cp );	//IF	
										cp++;

										$$=last_if_type;	//return last if 
									}
			;

CompareToken :	tMIN 	{
							$<variable>$="JL";
						}
			|	tMAY 	{
							$<variable>$="JG";
						}	
			|	tEQU 	{
							$<variable>$="JE";
						}	
			|	tDIF 	{
							$<variable>$="JNE";
						}		
			|	tMAYEQU 	{
							$<variable>$="JGE";
						}	
			|	tMINEQU 	{
							$<variable>$="JLE";
						}	
			 ;

CondValueEAX 	:	tVAR 	{		
								if(lookup($1) != -1)
								{		
									insert_Instruction( "MOV", "eax", address_Concat($1), "", "", cp );	 //mov eax, [var] 	
									cp++;			
								}
								else
								{
									strcpy( errTab[ce].error, "The variable " );
									strcat( errTab[ce].error, $1 );
									strcat( errTab[ce].error, " does not exist.\n" );		
									errTab[ce].line = ce;
									ce++;
								}		
							}
				|	tNUM	{		
								sprintf(snum, "%d", $1);
								insert_Instruction( "MOV", "eax", snum, "", "", cp );	 //mov eax, num	
								cp++;
							}
				;


CondValueEBX :	tVAR 	{						
								insert_Instruction( "MOV", "ebx", address_Concat($1), "", "", cp );	 //mov eax, [var] 	
								cp++;
							}
				|	tNUM	{		
								sprintf(snum, "%d", $1);
								insert_Instruction( "MOV", "ebx", snum, "", "", cp );	 //mov eax, num	
								cp++;
							}
				;

While		:	tWHILE tPO Cond tPF tCO Body tCF	{printf("\n While trouve");}
				;

Print 		:	tPRINT tPO PrintCont tPF tPV		{printf("\n Print trouve");}				
			;

PrintCont	:	PrintCont tPLUS PrintCont		{printf("\n Contenu du Print trouve");}
				| tGUILLEMETS tSTRING tGUILLEMETS	{	
														//TODO: Add \n management
														int mod;

														strcpy( retrievedString, $2 ); 
														strcpy( stringPrinter, "'" ); 	
														int count = 0, count2 = 0;

														sprintf(snum, "%d", (int) strlen(retrievedString));
														strcpy( auxString, snum );
														insert_Instruction( "MOV", "edx", auxString, "", "Message length", cp );	//Message length
														cp++;

														while( retrievedString[count] != '\0')
														{
															stringPrinter[count2] = retrievedString[count];  

															if( count2 == 3 )		//Print every 4 characters to respect dword size
															{
																//Create string with printf_MSG+count+1
    															strcpy( auxString, "printf_MSG+" );
																sprintf(snum, "%d", count-count2);	
    															strcat( auxString, snum );

																//Create string with dword stringPrinter[0]+[1]+[2]+[3]
    															strcpy( auxString2, "dword " );
    															stringPrinter[count2+1] = '\0';
    															strcat( auxString2, stringPrinter );

																insert_Instruction( "MOV", address_Concat(auxString), auxString2, "", "New message", cp );	//Message[0,1,2,3]
																cp++;	
																count2 = 0;
															}
															else{
																count2 ++;	
															}														

															count ++;
														}

														if( count2 > 0 )
														{
															/*if( retrievedString[count] == '\' && retrievedString[count+1] == 'n' )  //New line detected
															{
																count++;
																auxString
																insert_Instruction( "MOV", address_Concat("printf_MSG+count+1"), "dword + stringPrinter", "", "New message", cp );	//add new line
																	cp++;
															}*/

															//Create string with printf_MSG+count+1
    														strcpy( auxString, "printf_MSG+" );
															sprintf(snum, "%d", count-count2);		
    														strcat( auxString, snum );

															//Create string with dword stringPrinter[0]+[1]+[2]+[3]
    														strcpy( auxString2, "dword " );
    														stringPrinter[count2] = '\0';
    														strcat( auxString2, stringPrinter );

															insert_Instruction( "MOV", address_Concat(auxString), auxString2, "", "New message", cp );	//Message[0,1,2,3]
															cp++;													

															count ++;
															count2 ++;
														}

														insert_Instruction( "MOV", "ecx", "printf_MSG", "", "Message to write", cp );	
														cp++;	
														insert_Instruction( "MOV", "ebx", "1", "", "file descriptor (stdout)", cp );	
														cp++;	
														insert_Instruction( "MOV", "eax", "4", "", "Message to write", cp );
														cp++;	
														insert_Instruction( "INT", "80h", "", "", "System call (Call Kernel)", cp );	//Call Kernel
														cp++;	
		
													}  //TODO: Programar los demas tipos de printf
				| tVAR							{printf("\n Contenu du Print trouve");}
			;


Declar		: 	Declar tPV 				{printf("\n Declaration trouvee");}
				| Declar tV Declar 		{printf("\n Declaration trouvee");}
				| tINT tVAR tE Expr 	{				
											if(lookup($2) == -1)
											{
												insert($2, 0);
											}else
											{												
												strcpy( errTab[ce].error, "Variable %s already exists.\n" );
												errTab[ce].line = ce;
												ce++;
											}
										}
				| tINT tVAR				{
											if(lookup($2) == -1)
											{
												insert($2, 0);
											}else
											{												
												strcpy( errTab[ce].error, "Variable already exists.\n" );
												errTab[ce].line = ce;
												ce++;
											}
										}
				| tCONST tINT tVAR tE Expr	{
												if(lookup($3) == -1)
												{
													insert($3, 1);
												}else
												{												
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
				| tCONST tINT tVAR			{
												if(lookup($3) == -1)
												{
													insert($3, 1);
												}else
												{												
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
				| tINT tCONST tVAR tE Expr	{
												if(lookup($3) == -1)
												{
													insert($3, 1);
												}else
												{												
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
				| tINT tCONST tVAR			{
												if(lookup($3) == -1)
												{
													insert($3, 1);
												}else
												{												
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
			;

Main		: 	tMAIN tPO tPF	{												
									 insert_Instruction( "section", ".text", "", "", "", cp );
									 cp++;										
									 insert_Instruction( "global", "_start", "", "", "", cp );
									 cp++;									
									 insert_Instruction( "_start:", "", "", "", "", cp );
									 cp++;		
								}
				tCO Body tCF	{printf("Main Trouvee");}
			;

Val			:	tNUM		{
								if( tempCounter == 1 )
								{
									tempCounter = 2;
									$$=lookup("0temp1");	
								}		
								else
								{
									tempCounter = 1;
									$$=lookup("0temp2");	
								}
							}
				| tVAR		{	
								if(lookup($1) != -1)
								{
									$$=lookup($1);			
								}
								else
								{
									strcpy( errTab[ce].error, "The variable " );
									strcat( errTab[ce].error, $1 );
									strcat( errTab[ce].error, " does not exist.\n" );		
									errTab[ce].line = ce;
									ce++;
								}
							 }
			;

Expr			:	Expr tPLUS Expr	{ 	
										fprintf(fp, "mov eax, [%d]\n", $1); //eax = [a/0temp1]
										 insert_Instruction( "mov", "eax", address_Concat(lookupName($1)), "", "", cp );
										 cp++;			
									    fprintf(fp, "mov ebx, [%d]\n", $3); //ebx = [b/0temp2]
										 insert_Instruction( "mov", "ebx", address_Concat(lookupName($3)), "", "", cp );
									     cp++;

									    fprintf(fp, "add eax, ebx\n"); 		//eax = eax + ebx
										 insert_Instruction( "add", "eax", "ebx", "", "", cp );
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en 0temp2
										printf("\n Somme trouvee");
									}
				|	Expr tSOU Expr	{	
										fprintf(fp, "mov eax, [%d]\n", $1); //eax = [a/0temp1]
										 insert_Instruction( "mov", "eax", address_Concat(lookupName($1)), "", "", cp );
										 cp++;			
									    fprintf(fp, "mov ebx, [%d]\n", $3); //ebx = [b/0temp2]
										 insert_Instruction( "mov", "ebx", address_Concat(lookupName($3)), "", "", cp );
									     cp++;

									    fprintf(fp, "sub eax, ebx\n"); 		//eax - ebx
										 insert_Instruction( "sub", "eax", "ebx", "", "", cp );
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en temp2 
										printf("\n Substraction trouvee");
									}
				|	Expr tMUL Expr	{	
										fprintf(fp, "mov ax, [%d]\n", $1); //ax = [a/0temp1]
										 insert_Instruction( "mov", "eax", address_Concat(lookupName($1)), "", "", cp );
										 cp++;			
									    fprintf(fp, "mov bx, [%d]\n", $3); //bx = [b/0temp2]
										 insert_Instruction( "mov", "ebx", address_Concat(lookupName($3)), "", "", cp );
									     cp++;

									    fprintf(fp, "mul bx\n"); 			//ax * bx
										 insert_Instruction( "mul", "bx", "", "", "", cp );
									     cp++;

										tempCounter = 2;					//Como se evaluaron dos expresiones, se coloca en temp2 
										printf("\n Multiplication trouvee");
									}
				|	Expr tDIV Expr	{ 
											fprintf(fp, "\nFirst number : \n"); 
									}
				|	tPO Expr tPF
				|	Val
			;







%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

/*Error management*/
void print_Error_Table()
{
	if( ce > 0 )
		fprintf(fp, "\nErrors found : \n");
	for (int i = 0 ; i < ce; i++)
		fprintf(fp, "Error found in line: %d \n %s \n", errTab[i].line+1, errTab[i].error );

}
/*End of error management*/




/*Label Table Management*/
void print_Label_Table()
{
  	fprintf(fp,"\nLabel Table :\n----------------------------------------------------- \n");
	fprintf(fp, " Instruction | param1 | param2 | param 3 | comments |\n");
  	fprintf(fp,"----------------------------------------------------- \n");
	for (int i = 0 ; i < cp; i++)
	{
		fprintf(fp, " %-14s %-12s %-12s %-12s ;%-s \n", labTab[i].instruct, labTab[i].param1, labTab[i].param2, labTab[i].param3, labTab[i].comments );
	}
}

char* address_Concat( char *varName ) //concatenates [] with the address: the result is similar to: [a]
{
	char *result = malloc(16 * sizeof(char));
	strcat(result, "[");
	strcat(result, varName);
	strcat(result, "]");

	return result;	
}

void insert_Instruction( char *inst, char *p1, char *p2, char *p3, char *comment, int counter  )	//inserts all values to the table
{
	strcpy( labTab[counter].instruct, inst );
	strcpy( labTab[counter].param1, p1 );	  
	strcpy( labTab[counter].param2, p2 );	  
	strcpy( labTab[counter].param3, p3 );	  
	strcpy( labTab[counter].comments, comment );
}
/*End of label Table Management*/






int main(void) {


	//Instruction (label) table
	int **lableTable = malloc(instSIZE * 4 * sizeof(int));

	//Initialization of the label table
	int i;
	for(i = 0; i < instSIZE; i++)
	    lableTable[i] = malloc(4 * sizeof(int));


	printf("\nParser V2.0\n\n");

	fp = fopen("assOutput.out","w");


	insert("0temp1", 0);	//Temp variables inserted with number before to avoid conflict with user create variables	
	insert("0temp2", 0);




	/*insertSymbol("a", 1, 10);
	insertSymbol("a", 0, 10);
	assignValue("a", 11);*/


	//lookup("a");
	insert("a", 0);
	insert("b", 0);
	/*lookup("a");
	insert("a", 0);
	lookupType("a");
	insert("b", 0);
	insert("c", 1);
	insert("d", 0);
	insert("e", 1);
	insert("g", 1);
	insert("arnold", 0);
	insert("arnoldo", 0);
	lookup("arnold");
	lookup("e");*/


	yyparse();
	symtab_print(fp);
	print_Label_Table();
	print_Error_Table();
	fprintf(fp, "Number of lines : %d\n", cp+1); 
	fclose(fp);
	return 0;
}




/*TODO: Users can't name a variable 0temp1 nor 0temp2*/