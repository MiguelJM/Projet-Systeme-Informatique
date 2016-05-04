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

	struct stack if_iter_stack;			//Keep count of number of ifs to correct
	struct stack if_stack;				//Allows to assign if begin code lines to jump instructions
	struct stack else_iter_stack;		//Keep count of number of else to correct
	struct stack else_stack;			//Allows to assign else begin code lines to jump instructions
  	int if_begin_count = 0; 			//Counter to determine the if labels to use
  	int else_begin_count = 0; 			//Counter to determine the else labels to use

  	int if_lbl_count = 0; 				//Counter to determine the if labels to use

	struct stack while_last_cond;		//Stores the position after comparissons of the while (to add the last comparisson)

	struct stack while_begin_iter_stack;			//Keep count of number of while begin lines to add
	struct stack while_begin_stack;						//Allows to assign while begin code lines to jump instructions
	struct stack while_end_iter_stack;				//Keep count of number of while end lines to correct
	struct stack while_end_stack;							//Allows to assign while end code lines to jump instructions
  	int while_begin_count = 0; 						//Counter to determine the while begin labels to use
  	int while_end_count = 0; 						//Counter to determine the while end labels to use

	struct stack while_stack;		//Keeps count of while statements to create labels
  	int while_lbl_count = 0; 		//Counter to determine the while labels to use

  	bool pointer_value_flag = false;	//Used to verify if pointer value was initialized or was true
  	bool pointer_value_flag2 = false;	//turns pointer value to false (because a = b + a OR a = &var + &var2 where a,b are pointers is not permited)
  	bool pointer_value = false;			//Used to verify if a val i used for a pointer assignation

  	bool temp1_flag = false;		//Used to indicate if temp1 is beinf used (in that case, use temp2)

	char snum[5];		//To convert numbers to strings
	char snum2[5];		//To convert numbers to strings
	char auxString[32];	
	char auxString2[32];
	
	char last_while_type[8]; //Returns the last type of while retrieved

	int auxNum;	

	char retrievedString[64]; //Used to store user input in the printf instructions.
	char stringPrinter[4]; 	//Used to create the printf instructions.
%}

%union {
	int nb;
	char * variable;
}

%start TestStart
%token tAMPERSAND
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
%token tPV
%token tPLUS
%token <variable> tVAR tSTRING 
%token tE
%token tMAIN
%token tSOU
%token tMUL
%token tDIV
%token tPRINT
%token <nb> tNUM tIF tWHILE tELSE 
%token tV
%token tCONST
%token tGUILLEMETS

%type <variable> Cond CondWhile CompareToken CondValue
%type <nb> If Val Expr Condition 

%right tE
%left tPLUS tSOU
%left tMUL tDIV


%%


TestStart	:	TestMessage
			;

TestMessage	: 	While		{printf("\n Succesful test");}
			;

Fonction	: 	tINT tVAR tPO Param tPF tCO Body tCF 	{printf("\n Fonction trouvee");}
			;
	
Param 		:	tINT tVAR tV Param 		
				| tINT tVAR				
			;
				
Body		:	Declar						
			|	If							
			|	While						
			|	Print							
			| 	Assign						
			|	Body Body							
			;

Assign 		:	tVAR tE tVAR tPV	{
										if( lookupType($1) == 0 && lookupType($3) == 0 ) //Both variables exist and are integers
										{		
											sprintf(snum, "%d", lookup($1));
											sprintf(snum2, "%d", lookup($3));
											setValueByName($1, getValueByName($3)); 	//Sets the value
											insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
										    cp++;			
										}
										else
										{
											if( lookupType($1) == 2 && lookupType($3) == 2 ) //Both variables exist and are pointers
											{	
												sprintf(snum, "%d", lookup($1));
												sprintf(snum2, "%d", lookup($3));
												setValueByName($1, getValueByName($3)); 	//Sets the value
												insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
											    cp++;
											}
											else
											{
												strcpy( errTab[ce].error, "Invalid assignation.\n" );
												errTab[ce].line = ce;
												ce++;
											}
										}
									}
			|	tVAR tE tNUM tPV	{
										if( lookupType($1) == 0 ) 	//Variable exists and is integer
										{			
											sprintf(snum, "%d", lookup($1));
											sprintf(snum2, "%d", $3);
											setValueByName($1, $3); 	//Sets the value
										    insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result constant 
										    cp++;			
										}
										else
										{
											strcpy( errTab[ce].error, "Trying to assign value to a constant, pointer or variable that doesn't exist.\n" );
											errTab[ce].line = ce;
											ce++;
										}	
									}
			|	tVAR tE Expr tPV	{
										if(lookupType($1) == 0 && !pointer_value)	//Variable exists and is integer and the expression is not for pointer
										{				
											sprintf(snum, "%d", lookup($1));
											sprintf(snum2, "%d", lookup("0temp1"));
											setValueByName($1, getValueByName("0temp1")); 	//Sets the value
											insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
										    cp++;			
										}
										else
										{
											if(lookupType($1) == 2) //Variable exists and is pointer
											{
												if(	pointer_value ) //The expression is correct for the pointer
												{
													sprintf(snum, "%d", lookup($1));
													sprintf(snum2, "%d", lookup("0temp1"));
													setValueByName($1, getValueByName("0temp1")); 	//Sets the value
													insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
												    cp++;	
												}
												else
												{
													strcpy( errTab[ce].error, "Invalid pointer convertion.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
											else
											{
												strcpy( errTab[ce].error, "Trying to assign number value to a constant or variable that doesn't exist.\n" );
												errTab[ce].line = ce;
												ce++;
											}
										}
										pointer_value_flag = false; //reset variable
										pointer_value_flag2 = false; //reset variable
									}
			|	tVAR tE tMUL tVAR tPV 		{
												if(lookupType($1) != 2 && lookupType($1) != -1 && lookupType($4) == 2)	//Variables exist, first variable is not a pointer, and second var is a pointer
												{	
													if( lookupAddress(getValueByName($4)) != -1 ) //Pointed address is valid
													{
														sprintf(snum, "%d", lookup($1));
														sprintf(snum2, "%d", lookup($4));	
														setValueByName($1, getValueByName(lookupName(getValueByName($4)))); 	//Sets the value	
														insert_Instruction( "D", snum, snum2, "", "", cp ); //PCOP @result @operand1 copies the value stored at @operand1.value to @result
													    cp++;		
													}
													else
													{
														strcpy( errTab[ce].error, "The pointer '" );
														strcat( errTab[ce].error, $4 );
														strcat( errTab[ce].error, "' points to an invalid address.\n" );		
														errTab[ce].line = ce;
														ce++;
													}
												}
												else
												{
													strcpy( errTab[ce].error, "Invalid pointer assignment.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
			|	tMUL tVAR tE tVAR tPV 		{
												if(lookupType($2) == 2 && lookupType($4) != -1 && lookupType($4) != 2)	//Variables exist, first variable is a pointer, and second var is not pointer
												{														
													if( lookupAddress(getValueByName($2)) != -1 ) //Pointed address is valid
													{
														sprintf(snum, "%d", lookup($2));		
														sprintf(snum2, "%d", lookup($4));	
														setValueByName(lookupName(getValueByName($2)), getValueByName($4)); 	//Sets the value	
														insert_Instruction( "E", snum, snum2, "", "", cp ); //IPCOP @result @operand1 copies the value stored at @operand1 to @result.value
													    cp++;		
													}
													else
													{
														strcpy( errTab[ce].error, "The pointer '" );
														strcat( errTab[ce].error, $2 );
														strcat( errTab[ce].error, "' points to an invalid address.\n" );		
														errTab[ce].line = ce;
														ce++;
													}
												}
												else
												{
													strcpy( errTab[ce].error, "Invalid pointer assignment.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
			|	tMUL tVAR tE tNUM tPV 		{
												if(lookupType($2) == 2 )	//Variable exists and is pointer
												{			
													if( lookupAddress(getValueByName($2)) != -1 ) //Pointed address is valid
													{
														sprintf(snum, "%d", lookup("0temp1"));
														sprintf(snum2, "%d", $4);	
														setValueByName("0temp1", $4); 	//Sets the value	
														insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num 
													    cp++;	

														sprintf(snum, "%d", lookup($2));		
														sprintf(snum2, "%d", lookup("0temp1"));
														setValueByName(lookupName(getValueByName($2)), getValueByName("0temp1")); 	//Sets the value
														insert_Instruction( "E", snum, snum2, "", "", cp ); //IPCOP @result @operand1 copies the value stored at @operand1 to @result.value
													    cp++;		
													}
													else
													{
														strcpy( errTab[ce].error, "The pointer '" );
														strcat( errTab[ce].error, $2 );
														strcat( errTab[ce].error, "' points to an invalid address.\n" );		
														errTab[ce].line = ce;
														ce++;
													}
												}
												else
												{
													strcpy( errTab[ce].error, "The pointer doesn't exist.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
			|	tVAR tE tAMPERSAND tVAR tPV {
												if(lookupType($1) == 2 && lookupType($4) != -1 && lookupType($4) != 2)	//Both variable exist, the first is pointer, and the second is not pointer
												{						
													sprintf(snum, "%d", lookup("0temp1"));
													sprintf(snum2, "%d", lookup($4));	
													setValueByName("0temp1", lookup($4)); 	//Sets the value	
													insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num Copy address to result
												    cp++;	

													sprintf(snum, "%d", lookup($1));
													sprintf(snum2, "%d", lookup("0temp1"));
													setValueByName($1, getValueByName("0temp1")); 										//Sets the value of the pointer		
													insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
												    cp++;	
												}
												else
												{
													strcpy( errTab[ce].error, "The pointer doesn't exist.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
			;

Condition 	: 	tPO Cond tPF	{
									$$ = cp;
									cp++;
									if_iter_stack = push(if_begin_count, if_iter_stack);	//store if begin iterations to later assign if begin line
									if_begin_count = 0;

									else_iter_stack = push(else_begin_count, else_iter_stack);	//store else begin iterations to later assign if begin line
									else_begin_count = 0;
								}
			;

If			:	If tELSE tCO Body tCF			{
													sprintf(snum , "%d", cp);									//Obtain else body end
													insert_Instruction( "JMP", snum, "", "", "", $1-1 );		//If ended, jump to else body end
												}
			| 	tIF Condition tCO Body tCF		{
													sprintf(snum , "%d", cp+1);												//next instruction to ignore else jmp
													insert_Instruction( "JMF", "@X", snum, "", "", $2 );				//If statement is false jump to else body

													sprintf(snum , "%d", cp+1);									//Obtain if end
													insert_Instruction( "JMP", snum, "", "", "", cp );			//If ended, jump to else body end (If there is an else instruction, will be overwritten)
													cp++;		
													$$ = cp; 													//Obtain else body end	

													if(if_iter_stack.top != -1)	//If there is one jmp to if begin
													{
														auxNum = if_iter_stack.stk[if_iter_stack.top];	//take if label value from the stack	
														if_iter_stack = pop(if_iter_stack);						//pop the value		
														for(int i=0  ; i<auxNum ; i++)	
														{ 										
															sprintf(snum , "%d", $2+1);									//If begin	
															strcpy( labTab[if_stack.stk[if_stack.top]].param1, snum );	//put if begin on second parameter of jmp instruct
															if_stack = pop(if_stack);				
														}
													}													

													if(else_iter_stack.top != -1)	//If there is one jmp to else begin
													{
														auxNum = else_iter_stack.stk[else_iter_stack.top];	//take if label value from the stack	
														else_iter_stack = pop(else_iter_stack);							//pop the value		
														for(int i=0  ; i<auxNum ; i++)	
														{ 										
															sprintf(snum , "%d", cp);										//Else begin	
															strcpy( labTab[else_stack.stk[else_stack.top]].param2, snum );	//put if begin on second parameter of jmp instruct
															else_stack = pop(else_stack);				
														}
													}
												}
			;

Cond		:	CondValue CompareToken CondValue 		{					
															sprintf(snum, "%d", lookup("0temp1"));
															sprintf(snum2, "%d", lookup("0temp2"));	
															insert_Instruction( $2, "@X", snum, snum2, "", cp );			//COMPARISSON
															cp++;
														}
				|  	tPO Cond tPF tOR  	{									
											sprintf(snum , "%d", cp+2);	
											insert_Instruction( "JMF", "@X", snum, "", "", cp );					//If statement is false jump to the next statement
											cp++;

											if_begin_count++;
											if_stack = push(cp, if_stack);												//Remember this line to later add the if begin line
											insert_Instruction( "JMP", "IF BEGIN", "", "", "", cp );					//If statement is true jump to the last if and return true value
											cp++;
										}
					tPO Cond tPF 		{
											sprintf(snum , "%d", cp+2);	
					 						insert_Instruction( "JMF", "@X", snum, "", "", cp );					//If statement is false jump to the next statement
											cp++;	

											if_begin_count++;
											if_stack = push(cp, if_stack);												//Remember this line to later add the if begin line
											insert_Instruction( "JMP", "IF BEGIN", "", "", "", cp );					//If statement is true jump to the last if and return true value
											cp++;
										}
				| tPO Cond tPF tAND 	{
											else_begin_count++;
											else_stack = push(cp, else_stack);											//Remember this line to later add the else begin line
											insert_Instruction( "JMF", "@X", "ELSE BEGIN", "", "", cp );			//If statement is false jump to the else body
											cp++;
										}
					tPO Cond tPF		{
											else_begin_count++;
											else_stack = push(cp, else_stack);											//Remember this line to later add the else begin line
											insert_Instruction( "JMF", "@X", "ELSE BEGIN", "", "", cp );			//If statement is false jump to the else body
											cp++;											
										}
			;


//TODO: conditions must be like: ((cond)||(cond))  or  ((cond)||((cond)||(cond)))

CondWhile		:	CondValue CompareToken CondValue 	{					
															sprintf(snum, "%d", lookup("0temp1"));
															sprintf(snum2, "%d", lookup("0temp2"));	
															insert_Instruction( $2, "@X", snum, snum2, "", cp );			//COMPARISSON
															cp++;
														}
				|  tPO CondWhile tPF tOR  	{											
												sprintf(snum , "%d", cp+2);										
												insert_Instruction( "JMF", "@X", snum, "", "", cp );				//If statement is false, jump to next condition
												cp++;	

												while_begin_count++;
												while_begin_stack = push(cp, while_begin_stack);					//Remember this line to later add the while begin line
												insert_Instruction( "JMP", "WHILE BEGIN", "", "", "", cp );			//Jump to the begining of the while
												cp++;
											}
				 tPO CondWhile tPF 			{											
												sprintf(snum , "%d", cp+2);										
												insert_Instruction( "JMF", "@X", snum, "", "", cp );				//If statement is false, jump to next condition
												cp++;	

												while_begin_count++;
												while_begin_stack = push(cp, while_begin_stack);					//Remember this line to later add the while begin line
												insert_Instruction( "JMP", "WHILE BEGIN", "", "", "", cp );			//Jump to the begining of the while
												cp++;
											}
				| tPO CondWhile tPF tAND 	{		
												while_end_count++;
												while_end_stack = push(cp, while_end_stack);						//Remember this line to later add the while end line				
												insert_Instruction( "JMF", "@X", "WHILE END", "", "", cp );			//If statement is false, jump to the end of the while
												cp++;	
											}
				tPO CondWhile tPF			{			
												while_end_count++;
												while_end_stack = push(cp, while_end_stack);						//Remember this line to later add the while end line			
												insert_Instruction( "JMF", "@X", "WHILE END", "", "", cp );			//If statement is false, jump to the end of the while
												cp++;	
											}
			;




CompareToken :	tMIN 	{
							$<variable>$="9";	//INF
						}
			|	tMAY 	{
							$<variable>$="A";	//SUP
						}	
			|	tEQU 	{
							$<variable>$="B";	//EQU
						}		
			 ;


CondValue 	 :	tVAR 		{			
								if( lookup($1) != -1 && lookupType($1) != 2	)		//var exists and is not pointer
								{	
									if( !temp1_flag )
									{
										temp1_flag = true;
										strcpy( auxString, "0temp1" );
									}
									else{
										temp1_flag = false;		
										strcpy( auxString, "0temp2" );
									}

									sprintf(snum, "%d", lookup(auxString));
									sprintf(snum2, "%d", lookup($1));		
									setValueByName(auxString, getValueByName($1)); 	//Sets the value	
									insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
									cp++;
		
									sprintf(snum, "%d", lookup(auxString));
									$$=snum;
								}
								else
								{
									strcpy( errTab[ce].error, "The variable '" );
									strcat( errTab[ce].error, $1 );
									strcat( errTab[ce].error, "' does not exist or is invalid.\n" );		
									errTab[ce].line = ce;
									ce++;
								}	
							}
				|	tMUL tVAR	{			
									if(lookup($2) != -1 && lookup($2) == 2	)		//var exists and is a pointer
									{	
										if( lookupAddress(getValueByName($2)) != -1 ) //Pointed address is valid
										{
											if( !temp1_flag )
											{
												temp1_flag = true;
												strcpy( auxString, "0temp1" );
											}
											else{
												temp1_flag = false;		
												strcpy( auxString, "0temp2" );
											}

											sprintf(snum, "%d", lookup(auxString));
											sprintf(snum2, "%d", lookup($2));	
											setValueByName(auxString, getValueByName(lookupName(getValueByName($2)))); 	//Sets the value	
											insert_Instruction( "D", snum, snum2, "", "", cp ); //PCOP @result @operand1 copies the value stored at @operand1.value to @result 
											cp++;
				
											sprintf(snum, "%d", lookup(auxString));
											$$=snum;			
										}
										else
										{
											strcpy( errTab[ce].error, "The pointer '" );
											strcat( errTab[ce].error, $2 );
											strcat( errTab[ce].error, "' points to an invalid address.\n" );		
											errTab[ce].line = ce;
											ce++;
										}										
									}
									else
									{
										strcpy( errTab[ce].error, "The variable " );
										strcat( errTab[ce].error, $2 );
										strcat( errTab[ce].error, " does not exist.\n" );		
										errTab[ce].line = ce;
										ce++;
									}	
								}
				|	tNUM	{	
								if( !temp1_flag )
								{
									temp1_flag = true;
									strcpy( auxString, "0temp1" );
								}
								else{
									temp1_flag = false;		
									strcpy( auxString, "0temp2" );
								}

								sprintf(snum, "%d", lookup(auxString));
								sprintf(snum2, "%d", $1);	
								setValueByName(auxString, $1); 	//Sets the value	
								insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num 
								cp++;
	
								sprintf(snum, "%d", lookup(auxString));
								$$=snum;
							}
				;

ConditionWhile 	: 	tPO CondWhile tPF	{											
											while_last_cond = push(cp, while_last_cond);	//Store while begin
											cp++;	

											while_begin_iter_stack = push(while_begin_count, while_begin_iter_stack);	//store while begin iterations to later assign while begin line
											while_begin_count = 0;

											while_end_iter_stack = push(while_end_count, while_end_iter_stack);			//store while end iterations to later assign while end line
											while_end_count = 0;	
										}
				;

While		:	tWHILE 								{	
														$1=cp;										//Save while begin
			
													}
				ConditionWhile tCO Body tCF			{				
														int whileBegin = while_last_cond.stk[while_last_cond.top];
														while_last_cond = pop(while_last_cond);							//pop the value		

														sprintf(snum , "%d", cp+1);										
														insert_Instruction( "JMF", "@X", snum, "", "",  whileBegin);	//Jump to while end in case condition is not met

														sprintf(snum , "%d", $1);												
														insert_Instruction( "JMP", snum, "", "", "", cp );	//JMP to while begin
														cp++;

														if(while_begin_iter_stack.top != -1)	//If there is one jmp to if begin
														{
															auxNum = while_begin_iter_stack.stk[while_begin_iter_stack.top];	//take if label value from the stack	
															while_begin_iter_stack = pop(while_begin_iter_stack);						//pop the value		
															for(int i=0  ; i<auxNum ; i++)	
															{ 										
																sprintf(snum , "%d", whileBegin);									//while begin	
																strcpy( labTab[while_begin_stack.stk[while_begin_stack.top]].param1, snum );	//put while begin on second parameter of jmp instruct
																while_begin_stack = pop(while_begin_stack);				
															}
														}													

														if(while_end_iter_stack.top != -1)	//If there is one jmp to else begin
														{
															auxNum = while_end_iter_stack.stk[while_end_iter_stack.top];	//take if label value from the stack	
															while_end_iter_stack = pop(while_end_iter_stack);							//pop the value		
															for(int i=0  ; i<auxNum ; i++)	
															{ 										
																sprintf(snum , "%d", cp);										//while end	
																strcpy( labTab[while_end_stack.stk[while_end_stack.top]].param2, snum );	//put while end on second parameter of jmp instruct
																while_end_stack = pop(while_end_stack);				
															}
														}
													}
				;

Print 		:	tPRINT tPO Val tPF tPV	{	
											sprintf(snum, "%d", $3);
											insert_Instruction( "C", snum, "", "", "", cp );	//PRI @result
											cp++;
											pointer_value_flag = false; //reset variable
											pointer_value_flag2 = false; //reset variable
										}		
			;


Declar		: 	Declar tPV 				
				| Declar tV Declar 		
				| tINT tVAR tE Expr 	{				
											if(lookup($2) == -1 && !pointer_value)	//Variable doesn't exist and the expr is not for pointers
											{
												insert($2, 0);		//new int

												sprintf(snum, "%d", lookup($2));
												sprintf(snum2, "%d", lookup("0temp1"));
												setValueByName($2, getValueByName("0temp1")); 	//Sets the value
												insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
											    cp++;											    		
											}else
											{	
												if(pointer_value)	
												{						
													strcpy( errTab[ce].error, "Invalid convertion.\n" );
													errTab[ce].line = ce;
													ce++;													
												}	
												else
												{									
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
											pointer_value_flag = false; //reset variable
											pointer_value_flag2 = false; //reset variable
										}
				| tINT tVAR				{
											if(lookup($2) == -1)
											{
												insert($2, 0);		//new int
											}else
											{												
												strcpy( errTab[ce].error, "Variable already exists.\n" );
												errTab[ce].line = ce;
												ce++;
											}
										}
				| tINT tMUL tVAR tE Expr	{				
												if(lookup($3) == -1 && pointer_value) //Variable exists and the expression is correct
												{
													insert($3, 2);		//new pointer

													sprintf(snum, "%d", lookup($3));
													sprintf(snum2, "%d", lookup("0temp1"));		
													setValueByName($3, getValueByName("0temp1")); 	//Sets the value
													insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
												    cp++;		
												}else
												{				
													if(!pointer_value)
													{				
														strcpy( errTab[ce].error, "Invalid expression.\n" );
														errTab[ce].line = ce;
														ce++;
													}else
													{							
														strcpy( errTab[ce].error, "Variable %s already exists.\n" );
														errTab[ce].line = ce;
														ce++;
													}
												}
												pointer_value_flag = false; //reset variable
												pointer_value_flag2 = false; //reset variable
											}
				| tINT tMUL tVAR		{
											if(lookup($3) == -1)
											{
												insert($3, 2);			//new pointer
											}else
											{												
												strcpy( errTab[ce].error, "Variable already exists.\n" );
												errTab[ce].line = ce;
												ce++;
											}
										}
				| tCONST tVAR tE Expr		{
												if(lookup($2) == -1 && !pointer_value) //Variable exists and the expression is correct
												{
													insert($2, 1);		//new const													

													sprintf(snum, "%d", lookup($2));
													sprintf(snum2, "%d", lookup("0temp1"));		
													setValueByName($2, getValueByName("0temp1")); 	//Sets the value
													insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
												    cp++;		
												}else
												{											
													
													if(pointer_value)	
													{						
														strcpy( errTab[ce].error, "Invalid convertion.\n" );
														errTab[ce].line = ce;
														ce++;													
													}	
													else
													{									
														strcpy( errTab[ce].error, "Variable %s already exists.\n" );
														errTab[ce].line = ce;
														ce++;
													}
												}
												pointer_value_flag = false; //reset variable
												pointer_value_flag2 = false; //reset variable
											}
				| tCONST tVAR				{
												if(lookup($2) == -1)
												{
													insert($2, 1);		//new const
												}else
												{												
													strcpy( errTab[ce].error, "Variable already exists.\n" );
													errTab[ce].line = ce;
													ce++;
												}
											}
			;

Main		: 	tMAIN tPO tPF tCO Body tCF
			;

Val			:	tNUM		{
								if( !pointer_value_flag )	//pointer value hasn't been initialized
								{
									pointer_value_flag = true;
									pointer_value = false; 			//not a pointer expression
								}

								temp1_flag = false;

								sprintf(snum, "%d", lookup("0temp2"));
								sprintf(snum2, "%d", $1);
								setValueByName("0temp2", $1); 	//Sets the value
								insert_Instruction( "6", snum, snum2, "", "", cp ); //COP @result @operand1 
								cp++;

								$$ = lookup("0temp2");
							}
				| tVAR		{	
								if(lookup($1) != -1)	//var exists
								{
									if(lookupType($1) != 2)	//not pointer
									{
										if( !pointer_value_flag )	//pointer value hasn't been initialized
										{
											pointer_value_flag = true;
											pointer_value = false; 			//not a pointer expression
										}
										$$ = lookup($1);				//Address of the variable
									}
									else
									{
										if(	pointer_value_flag2 )
										{
											pointer_value = false; //pointer expression wrong
										}
										else{
											if( !pointer_value_flag || !pointer_value )	//pointer value hasn't been initialized or pointer value was false
											{
												pointer_value_flag = true;
												pointer_value = true; //pointer expression
												pointer_value_flag2 = true;
											}
										}										

										$$ = lookup($1);		//Address of the pointer(to print the address of the pointed variable)
									}
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
				| tMUL tVAR	{	
								if( lookupType($2) == 2 )	//var exists and is pointer
								{
									if( lookupAddress(getValueByName($2)) != -1 ) //Pointed address is valid
									{
										if( !pointer_value_flag )	//pointer value hasn't been initialized
										{
											pointer_value_flag = true;
											pointer_value = false; 			//not a pointer expression
										}
																			
										temp1_flag = false;

										sprintf(snum, "%d", lookup("0temp2"));
										sprintf(snum2, "%d", lookup($2));		//Address of the pointer 
										setValueByName("0temp2", getValueByName(lookupName(getValueByName($2)))); 	//Sets the value
										insert_Instruction( "D", snum, snum2, "", "", cp ); //PCOP @result @operand1 
										cp++;

										$$ = lookup("0temp2");	//Address of the variable (to print value of the pointed variable)		
									}
									else
									{
										strcpy( errTab[ce].error, "The pointer '" );
										strcat( errTab[ce].error, $2 );
										strcat( errTab[ce].error, "' points to an invalid address.\n" );		
										errTab[ce].line = ce;
										ce++;
									}
								}
								else
								{
									strcpy( errTab[ce].error, "The pointer " );
									strcat( errTab[ce].error, $2 );
									strcat( errTab[ce].error, " does not exist.\n" );		
									errTab[ce].line = ce;
									ce++;
								}
							}
				| tAMPERSAND tVAR	{	
										if( lookupType($2) != -1 )	//var exists
										{
											if(	pointer_value_flag2 )
											{
												pointer_value = false; //pointer expression wrong
											}
											else{
												if( !pointer_value_flag || !pointer_value )	//pointer value hasn't been initialized or pointer value was false
												{
													pointer_value_flag = true;
													pointer_value = true; //pointer expression
													pointer_value_flag2 = true;
												}
											}

											if( !temp1_flag )
											{
												temp1_flag = true;

												sprintf(snum, "%d", lookup("0temp1"));
												sprintf(snum2, "%d", lookup($2));		//Address of the pointer 
												setValueByName("0temp1", lookup($2)); 	//Sets the value
												insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num Copy address to result
												cp++;

												$$ = lookup("0temp1");
											}else
											{
												temp1_flag = false;

												sprintf(snum, "%d", lookup("0temp2"));
												sprintf(snum2, "%d", lookup($2));		//Address of the pointer 
												setValueByName("0temp2", lookup($2)); 	//Sets the value
												insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num Copy address to result
												cp++;

												$$ = lookup("0temp2");
											}
										}
										else
										{
											strcpy( errTab[ce].error, "The variable " );
											strcat( errTab[ce].error, $2 );
											strcat( errTab[ce].error, " does not exist.\n" );		
											errTab[ce].line = ce;
											ce++;
										}
									}
			;

Expr			:	Expr tPLUS Expr	{ 		
										 sprintf(snum, "%d", $1);
										 sprintf(snum2, "%d", $3);
										 sprintf(auxString, "%d", lookup("0temp1"));
										 setValueByName( "0temp1", getValueByName(lookupName($1))+getValueByName(lookupName($3)) );
										 insert_Instruction( "1", auxString, snum, snum2, "", cp ); //ADD @result @operand1 @operand2
									     cp++;

									     $$=lookup("0temp1");
									}
				|	Expr tSOU Expr	{	
										 sprintf(snum, "%d", $1);
										 sprintf(snum2, "%d", $3);
										 sprintf(auxString, "%d", lookup("0temp1"));
										 setValueByName( "0temp1", getValueByName(lookupName($1))-getValueByName(lookupName($3)) );
										 insert_Instruction( "3", auxString, snum, snum2, "", cp ); //SOU @result @operand1 @operand2
									     cp++;

									     $$=lookup("0temp1");
									}
				|	Expr tMUL Expr	{								
										 sprintf(snum, "%d", $1);
										 sprintf(snum2, "%d", $3);
										 sprintf(auxString, "%d", lookup("0temp1"));
										 setValueByName( "0temp1", getValueByName(lookupName($1))*getValueByName(lookupName($3)) );
										 insert_Instruction( "2", auxString, snum, snum2, "", cp ); //MUL @result @operand1 @operand2
									     cp++;

									     $$=lookup("0temp1");
									}
				|	Expr tDIV Expr	{ 
										 sprintf(snum, "%d", $1);
										 sprintf(snum2, "%d", $3);
										 sprintf(auxString, "%d", lookup("0temp1"));
										 setValueByName( "0temp1", getValueByName(lookupName($1))/getValueByName(lookupName($3)) );
										 insert_Instruction( "4", auxString, snum, snum2, "", cp ); //DIV @result @operand1 @operand2
									     cp++;

									     $$=lookup("0temp1");
									}
				|	tPO Expr tPF
				|	Val
			;

/*TODO:

      			| error 	{									
								strcpy( errTab[ce].error, "Expected variable or number in line: " );								
								sprintf(snum , "%d", cp);
								strcpy( errTab[ce].error, snum );								
								strcpy( errTab[ce].error, ".\n" );
								errTab[ce].line = ce;
								ce++;
      						}
*/																												



%%

void yyerror(char *s) {
	printf("%s\n", s);
	//fprintf(stderr, "%s\n", s);
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
	fprintf(fp, " \tInstruction | param1 | param2 | param 3 | comments |\n");
  	fprintf(fp,"----------------------------------------------------- \n");
	for (int i = 0 ; i < cp; i++)
	{
		fprintf(fp, "%-3d:  %-14s %-12s %-12s %-12s ;%-s \n", i, labTab[i].instruct, labTab[i].param1, labTab[i].param2, labTab[i].param3, labTab[i].comments );
	}
}

char* address_Concat( char *varName ) //concatenates [] with the address: the result is similar to: [a]
{
	char *result = malloc(16 * sizeof(char));
	strcat(result, "@");
	strcat(result, varName);

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

	initializeSymtab(); //Sets parameters like temporal variables, etc..

	//Instruction (label) table
	int **lableTable = malloc(instSIZE * 4 * sizeof(int));

	//Initialization of the label table
	int i;
	for(i = 0; i < instSIZE; i++)
	    lableTable[i] = malloc(4 * sizeof(int));


	printf("\nParser V2.0\n\n");

	fp = fopen("assOutput.out","w");


	fprintf(fp, "%d", lookup("0temp1") );

	insert("a", 0);
	setValueByName("a", 30);
	insert("b", 0);
	setValueByName("b", 40);
	insert("Pa", 2);
	setValueByName("Pa", lookup("a"));
	insert("Pb", 2);
	insert("Pc", 2);
	setValueByName("Pc", 16);

	insert("c", 1);
	insert("d", 0);
	insert("e", 1);
	insert("g", 1);


	yyparse();
	symtab_print(fp);
	print_Label_Table();
	print_Error_Table();
	fprintf(fp, "Number of lines : %d\n", cp+1); 
	fclose(fp);
	return 0;
}




/*TODO: 
	Symbol table: Addresses sare sometimes repeated
	Pointers:
		- On CondValue	 Pointer comparisson is not implemented
		- Los valores de las variables son alterados siempre, aunque haya un if, si existe a=2 esa asignacion se hace, a nivel de codigo ensamblador, los apuntadores son los unicos afectados (getValue se utiliza directamente en codigo para recuperar las direcciones de sus variables apuntadas)
	If: 	
			- Conditions must be like: ((cond)||(cond))  or  ((cond)||((cond)||(cond)))
	While:
			- Conditions must be like: ((cond)||(cond))  or  ((cond)||((cond)||(cond)))
	Users can't name a variable 0temp1 nor 0temp2	



*/