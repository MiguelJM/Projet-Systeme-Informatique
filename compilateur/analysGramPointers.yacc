%{
	#include <stdio.h>	
	#include <string.h>
	#include <stdbool.h>

	#include "symtab.h"
	#include "funtab.h"
	#include "stack.h"

	int yylex(void);
	void yyerror(char *);

	char *address_Concat( char * );
	void insert_Instruction( char *, char *, char *, char *, char *, int );
	void write_ASM_File();

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
	int cp = 1; //instruction counter (Begins in 1 because 0 is a JMP to avoid executing the decalred functions)
	int cp_Offset = 0; //Offset of the instruction counter

	struct stack funct_stack;				//Allows to jump back to the line after function call

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

  	bool temp1_flag = false;		//Used to indicate if temp1 is being used (in that case, use temp2)

	char snum[5];		//To convert numbers to strings
	char snum2[5];		//To convert numbers to strings
	char auxString[32];	
	char auxString2[32];

	struct paramTable callParams[MAXPARAMETERS];   	//Stores the parameters of the function
	char lastFuncCreated[32]; 						//Stores the last function to be declared
	int paramCount = 0;
	
	char last_while_type[8]; //Returns the last type of while retrieved

	int auxNum;	
	int depth = 0;				//Allows to determine how deep a variable is

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
%token tVOID
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

Begin 		: Fonctions {
							/* Ignore Function instructions at first */
							sprintf(snum, "%d", cp);	
							insert_Instruction( "7", snum, "", "", "", 0 ); //JMP line
						}
			  Main
			;

Fonctions	: Fonction  
			| Fonctions Fonction
			| /* Nothing */
			;

Fonction	: 	tINT tVAR 					{
												depth++;

												strcpy(lastFuncCreated, "-Invalid");	//Copy an impossible name (in case function was created to avoid conflict with parameters)
												if( lookupFunc($2) == -1 ) //Funtion doesn't exist
												{			
													strcpy(lastFuncCreated, $2);	//Store the name of this function							
													insert_Instruction( "ALLOUER", "FONCTION", $2, "", "", cp ); //Reserve space for the function
												    cp++;	
													insertFunc( $2, 0, cp );		
												}
												else
												{
													strcpy( errTab[ce].error, "The function already exists.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
				tPO Param tPF tCO Body tCF 	{	
												/* Delete variables created on the function */
												sprintf(snum, "%d", depth);							
												insert_Instruction( "DESALLOUER", "VARS in Depth", snum, "", "", cp ); //Reserve space for the function
												cp++;
												deleteByDepth( depth );	//Delete variables from this depth
												depth--;				//Used for variable creation
														
												sprintf(snum, "%d", lookup("0funct_line"));					
												insert_Instruction( "10", snum, "", "", "", cp ); //JMPA @var
												cp++;	
											}
			|	tVOID tVAR 					{
												depth++;

												strcpy(lastFuncCreated, "-Invalid");	//Copy an impossible name (in case function was created to avoid conflict with parameters)
												if( lookupFunc($2) == -1 )
												{						
													strcpy(lastFuncCreated, $2);	//Store the name of this function											
													insert_Instruction( "ALLOUER", "FONCTION", $2, "", "", cp ); //Reserve space for the function
												    cp++;	
													insertFunc( $2, 1, cp );		
												}
												else
												{
													strcpy( errTab[ce].error, "The function already exists.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
				tPO Param tPF tCO Body tCF 	{	
												/* Delete variables created on the function */
												sprintf(snum, "%d", depth);							
												insert_Instruction( "DESALLOUER", "VARS in Depth", snum, "", "", cp ); //Reserve space for the function
												cp++;
												deleteByDepth( depth );	//Delete variables from this depth
												depth--;				//Used for variable creation

												sprintf(snum, "%d", lookup("0funct_line"));					
												insert_Instruction( "10", snum, "", "", "", cp ); //JMPA @var
												cp++;	
											}				 			
			;

	
Param 		:	Param tV Param 							
				| tINT tVAR			{
										if( lookupFunc(lastFuncCreated) != -1 ) //Funtion doesn't exist
											insertParameter(lookupFunc(lastFuncCreated), $2, 0, depth); 
									}	
				| tINT tMUL tVAR	{
										if( lookupFunc(lastFuncCreated) != -1 ) //Funtion doesn't exist
											insertParameter(lookupFunc(lastFuncCreated), $3, 2, depth); 
									}
				| /* Nothing */			
			;

FunctCall	:	tVAR tPO 			{	
										strcpy(lastFuncCreated, "-Invalid");	//Copy an impossible name (in case function was created to avoid conflict with parameters)
										if( lookupFunc($1) != -1 )	//Function exists
										{
											/* Create variables for the parameters */
											depth++;
											strcpy(lastFuncCreated, $1);	//Store the name of this function		
										}
									}
				ParamCall tPF tPV	{	
											paramCount = 0;	//Reset
											if( lookupFunc($1) != -1 )	//Function exists
											{




												/* Function CALL */

												funct_stack = push(cp+2, funct_stack);			//store line after function call

												auxNum = funct_stack.stk[funct_stack.top];			//recover line after function call												
												sprintf(snum, "%d", lookup("0funct_line"));
												sprintf(snum2, "%d", auxNum);
												setValueByName(snum, auxNum); 	//Sets the value
											    insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result constant 
											    cp++;	
										
												sprintf(snum, "%d", lookupLineFunc($1));
											    insert_Instruction( "7", snum, "", "", "", cp ); //JMP line  
											    cp++;	

											    funct_stack = pop(funct_stack);						//pop the value	(last line on stack is going to be used on the next instruction)

												auxNum = funct_stack.stk[funct_stack.top];			//recover line after function call								
												sprintf(snum, "%d", lookup("0funct_line"));
												sprintf(snum2, "%d", auxNum);
												setValueByName(snum, auxNum); 	//Sets the value
												insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result constant 
											    cp++;




											    /* Delete variables created on the function */
												sprintf(snum, "%d", depth);							
												insert_Instruction( "DESALLOUER", "VARS in Depth", snum, "", "", cp ); //Reserve space for the function
												cp++;
												deleteByDepth( depth );	//Delete variables from this depth
											    depth--;	
											}
											else
											{
												strcpy( errTab[ce].error, "The function does not exist.\n" );
												errTab[ce].line = cp;
												ce++;
											}
										}
			;	

	
ParamCall 		: ParamCall tV ParamCall 		
				| tVAR						{
												if( lookupFunc(lastFuncCreated) != -1 )	//Function exists
												{
													if( getParameterCount(lookupFunc(lastFuncCreated)) >= paramCount )
													{		
														//if types are correct and variable is initialized
														setParameter( lookupFunc(lastFuncCreated), paramCount, getValueByName($1) );
														strcpy(auxString, getParameterName(lookupFunc(lastFuncCreated), paramCount));

														/* ASM */
														//Create Variable
														sprintf(snum, "%d", lookupDepth(auxString, depth));
														sprintf(snum2, "%d", lookupType(auxString));
														insert_Instruction( "ALLOUER", snum, auxString, snum2, "", cp ); //ALLOUER @var varName varType 
													    cp++;

														//Assign value
														sprintf(snum, "%d", lookupDepth(auxString, depth));
														sprintf(snum2, "%d", lookup($1));
														setValueByName($1, getValueByName($1)); 	//Sets the value
														insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
													    cp++;

														paramCount++;										
													}
													else
													{													
														strcpy( errTab[ce].error, "Invalid number of parameters.\n" );
														errTab[ce].line = cp;
														ce++;	
													}
												}
											}
				| tNUM						{
												if( lookupFunc(lastFuncCreated) != -1 )	//Function exists
												{
													if( getParameterCount(lookupFunc(lastFuncCreated)) >= paramCount )
													{	
														setParameter( lookupFunc(lastFuncCreated), paramCount, $1 );

														paramCount++;												
													}
													else
													{													
														strcpy( errTab[ce].error, "Invalid number of parameters.\n" );
														errTab[ce].line = cp;
														ce++;	
													}
												}
											}
				| /* Nothing */	
			;

Main		: 	tMAIN tPO tPF tCO Body tCF
			;

Body		:	Declar
			|	If							
			|	While						
			|	Print							
			| 	Assign		
			|   FunctCall				
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
												errTab[ce].line = cp;
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
											errTab[ce].line = cp;
											ce++;
										}	
									}
			|	tVAR tE Expr tPV	{
										if(lookupType($1) == 0 && !pointer_value)	//Variable exists and is integer and the expression is not for pointer
										{				
											if( temp1_flag )	//value is in temp1
												sprintf(auxString, "0temp1");	
											else
												sprintf(auxString, "0temp2");	

											sprintf(snum, "%d", lookup($1));
											sprintf(snum2, "%d", lookup(auxString));
											setValueByName($1, getValueByName(auxString)); 	//Sets the value
											insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
										    cp++;			
										}
										else
										{
											if(lookupType($1) == 2) //Variable exists and is pointer
											{
												if(	pointer_value ) //The expression is correct for the pointer
												{	
													if( temp1_flag )	//value is in temp1
														sprintf(auxString, "0temp1");	
													else
														sprintf(auxString, "0temp2");	

													sprintf(snum, "%d", lookup($1));
													sprintf(snum2, "%d", lookup(auxString));
													setValueByName($1, getValueByName(auxString)); 	//Sets the value
													insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
												    cp++;	
												}
												else
												{
													strcpy( errTab[ce].error, "Invalid pointer convertion.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
											else
											{
												strcpy( errTab[ce].error, "Trying to assign number value to a constant or variable that doesn't exist.\n" );
												errTab[ce].line = cp;
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
														errTab[ce].line = cp;
														ce++;
													}
												}
												else
												{
													strcpy( errTab[ce].error, "Invalid pointer assignment.\n" );
													errTab[ce].line = cp;
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
														errTab[ce].line = cp;
														ce++;
													}
												}
												else
												{
													strcpy( errTab[ce].error, "Invalid pointer assignment.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
			|	tMUL tVAR tE tNUM tPV 		{
												if(lookupType($2) == 2 )	//Variable exists and is pointer
												{			
													if( lookupAddress(getValueByName($2)) != -1 ) //Pointed address is valid
													{
														if( temp1_flag )	//value is in temp1
															sprintf(auxString, "0temp1");	
														else
															sprintf(auxString, "0temp2");	

														sprintf(snum, "%d", lookup(auxString));
														sprintf(snum2, "%d", $4);	
														setValueByName(auxString, $4); 	//Sets the value	
														insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num 
													    cp++;	

														sprintf(snum, "%d", lookup($2));		
														sprintf(snum2, "%d", lookup(auxString));
														setValueByName(lookupName(getValueByName($2)), getValueByName(auxString)); 	//Sets the value
														insert_Instruction( "E", snum, snum2, "", "", cp ); //IPCOP @result @operand1 copies the value stored at @operand1 to @result.value
													    cp++;		
													}
													else
													{
														strcpy( errTab[ce].error, "The pointer '" );
														strcat( errTab[ce].error, $2 );
														strcat( errTab[ce].error, "' points to an invalid address.\n" );		
														errTab[ce].line = cp;
														ce++;
													}
												}
												else
												{
													strcpy( errTab[ce].error, "The pointer doesn't exist.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
			|	tVAR tE tAMPERSAND tVAR tPV {
												if(lookupType($1) == 2 && lookupType($4) != -1 && lookupType($4) != 2)	//Both variable exist, the first is pointer, and the second is not pointer
												{				
													if( temp1_flag )	//value is in temp1
														sprintf(auxString, "0temp1");	
													else
														sprintf(auxString, "0temp2");	

													sprintf(snum, "%d", lookup(auxString));
													sprintf(snum2, "%d", lookup($4));	
													setValueByName(auxString, lookup($4)); 	//Sets the value	
													insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num Copy address to result
												    cp++;	

													sprintf(snum, "%d", lookup($1));
													sprintf(snum2, "%d", lookup(auxString));
													setValueByName($1, getValueByName(auxString)); 										//Sets the value of the pointer		
													insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
												    cp++;	
												}
												else
												{
													strcpy( errTab[ce].error, "The pointer doesn't exist.\n" );
													errTab[ce].line = cp;
													ce++;
												}
											}
			;

Condition 	: 	tPO Cond tPF	{
									depth++;	//Used for variable creation

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
													insert_Instruction( "7", snum, "", "", "", $1-1 );		//If ended, jump to else body end
												}
			| 	tIF Condition tCO Body tCF		{	
													strcpy( auxString, "0temp1" );
													sprintf(auxString, "%d", lookup(auxString));
													sprintf(snum , "%d", cp+1);												//next instruction to ignore else jmp 						
													//Can't set the value because we don't know the last comparrison results
													insert_Instruction( "8", auxString, snum, "", "", $2 );				//If statement is false jump to else body JMF

													sprintf(snum , "%d", cp+1);									//Obtain if end
													insert_Instruction( "7", snum, "", "", "", cp );			//JMP If ended, jump to else body end (If there is an else instruction, will be overwritten)
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
								
													sprintf(snum, "%d", depth);							
													insert_Instruction( "DESALLOUER", "VARS in Depth", snum, "", "", cp ); //Reserve space for the function
													cp++;
													deleteByDepth( depth );	//Delete variables from this depth
													depth--;				//Used for variable creation
												}
			;

Cond		:	CondValue CompareToken CondValue 		{		
															if( !temp1_flag )
															{
																temp1_flag = true;
															}

															strcpy( auxString, "0temp1" );
															sprintf(auxString, "%d", lookup(auxString));
															sprintf(snum, "%d", lookup("0temp1"));
															sprintf(snum2, "%d", lookup("0temp2"));	
															//Can't assign value from comparisson to temp
															insert_Instruction( $2, auxString, snum, snum2, "", cp ); //COMPARISSON
															cp++;
														}
				|  	tPO Cond tPF tOR  	{									
											strcpy( auxString, "0temp1" );
											sprintf(auxString, "%d", lookup(auxString));
											sprintf(snum , "%d", cp+2);			
											//Can't set the value because we don't know the last comparrison results
											insert_Instruction( "8", auxString, snum, "", "", cp );				//If statement is false jump to else body JMF
											cp++;

											if_begin_count++;
											if_stack = push(cp, if_stack);												//Remember this line to later add the if begin line
											insert_Instruction( "7", "IF BEGIN", "", "", "", cp );					//If statement is true jump to the last if and return true value JMP
											cp++;
										}
					tPO Cond tPF 		{									
											strcpy( auxString, "0temp1" );
											sprintf(auxString, "%d", lookup(auxString));
											sprintf(snum , "%d", cp+2);			
											//Can't set the value because we don't know the last comparrison results
											insert_Instruction( "8", auxString, snum, "", "", cp );				//If statement is false jump to else body JMF
											cp++;

											if_begin_count++;
											if_stack = push(cp, if_stack);												//Remember this line to later add the if begin line
											insert_Instruction( "7", "IF BEGIN", "", "", "", cp );					//If statement is true jump to the last if and return true value JMP
											cp++;
										}
				| tPO Cond tPF tAND 	{
											else_begin_count++;
											else_stack = push(cp, else_stack);											//Remember this line to later add the else begin line
													
											strcpy( auxString, "0temp1" );
											sprintf(auxString, "%d", lookup(auxString));	
											insert_Instruction( "8", auxString, "ELSE BEGIN", "", "", cp );				//If statement is false jump to else body JMF
											cp++;
										}
					tPO Cond tPF		{
											else_begin_count++;
											else_stack = push(cp, else_stack);											//Remember this line to later add the else begin line
			
											strcpy( auxString, "0temp1" );
											sprintf(auxString, "%d", lookup(auxString));
											insert_Instruction( "8", auxString, "ELSE BEGIN", "", "", cp );				//If statement is false jump to else body JMF
											cp++;										
										}
			;


//TODO: conditions must be like: ((cond)||(cond))  or  ((cond)||((cond)||(cond)))

CondWhile		:	CondValue CompareToken CondValue 	{					
															if( !temp1_flag )
															{
																temp1_flag = true;
															}
															strcpy( auxString, "0temp1" );
															sprintf(auxString, "%d", lookup(auxString));
															sprintf(snum, "%d", lookup("0temp1"));
															sprintf(snum2, "%d", lookup("0temp2"));	
															//Can't assign value from comparisson to temp
															insert_Instruction( $2, auxString, snum, snum2, "", cp ); //COMPARISSON
															cp++;
														}
				|  tPO CondWhile tPF tOR  	{					
												strcpy( auxString, "0temp1" );
												sprintf(auxString, "%d", lookup(auxString));
												sprintf(snum , "%d", cp+2);			
												//Can't set the value because we don't know the last comparrison results
												insert_Instruction( "8", auxString, snum, "", "", cp );				//If statement is false jump to else body JMF
												cp++;

												while_begin_count++;
												while_begin_stack = push(cp, while_begin_stack);					//Remember this line to later add the while begin line
												insert_Instruction( "7", "WHILE BEGIN", "", "", "", cp );			//Jump to the begining of the while JMP
												cp++;
											}
				 tPO CondWhile tPF 			{				
												strcpy( auxString, "0temp1" );
												sprintf(auxString, "%d", lookup(auxString));	
												sprintf(snum , "%d", cp+2);			
												//Can't set the value because we don't know the last comparrison results
												insert_Instruction( "8", auxString, snum, "", "", cp );				//If statement is false jump to else body JMF
												cp++;

												while_begin_count++;
												while_begin_stack = push(cp, while_begin_stack);					//Remember this line to later add the while begin line
												insert_Instruction( "7", "WHILE BEGIN", "", "", "", cp );			//Jump to the begining of the while JMP
												cp++;
											}
				| tPO CondWhile tPF tAND 	{		
												while_end_count++;
												while_end_stack = push(cp, while_end_stack);						//Remember this line to later add the while end line		
											
												strcpy( auxString, "0temp1" );
												sprintf(auxString, "%d", lookup(auxString));
												insert_Instruction( "8", auxString, "WHILE END", "", "", cp );				//If statement is false jump to else body JMF
												cp++;
											}
				tPO CondWhile tPF			{			
												while_end_count++;
												while_end_stack = push(cp, while_end_stack);						//Remember this line to later add the while end line		
															
												strcpy( auxString, "0temp1" );
												sprintf(auxString, "%d", lookup(auxString));	
												insert_Instruction( "8", auxString, "WHILE END", "", "", cp );				//If statement is false jump to else body JMF
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
									errTab[ce].line = cp;
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
											errTab[ce].line = cp;
											ce++;
										}										
									}
									else
									{
										strcpy( errTab[ce].error, "The variable " );
										strcat( errTab[ce].error, $2 );
										strcat( errTab[ce].error, " does not exist.\n" );		
										errTab[ce].line = cp;
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
														depth++;	//Used for variable creation
														$1=cp;										//Save while begin
			
													}
				ConditionWhile tCO Body tCF			{				
														int whileBegin = while_last_cond.stk[while_last_cond.top];
														while_last_cond = pop(while_last_cond);							//pop the value		
																	
														strcpy( auxString, "0temp1" );
														sprintf(auxString, "%d", lookup(auxString));
														sprintf(snum , "%d", cp+1);	
														//Can't assign value from comparisson
														insert_Instruction( "8", auxString, snum, "", "", whileBegin );				//Jump to while end in case condition is not met JMF

														sprintf(snum , "%d", $1);												
														insert_Instruction( "7", snum, "", "", "", cp );	//JMP to while begin
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
	

														sprintf(snum, "%d", depth);							
														insert_Instruction( "DESALLOUER", "VARS in Depth", snum, "", "", cp ); //Reserve space for the function
														cp++;
														deleteByDepth( depth );	//Delete variables from this depth
														depth--;				//Used for variable creation
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

Declar 		: 	DeclarInt 
			|	DeclarPtr
			| 	DeclarCnst
			;

DeclarInt	:	tINT DeclarInt tPV
			|	DeclarInt tV DeclarInt
			|   tVAR tE Expr 	{				
									if(lookupDepth($1, depth) == -1 && !pointer_value)	//Variable doesn't exist and the expr is not for pointers
									{
										insert($1, 0, depth);		//new int

										sprintf(snum, "%d", lookupDepth($1, depth));
										sprintf(snum2, "%d", lookupType($1));
										insert_Instruction( "ALLOUER", snum, $1, snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									    if( temp1_flag )	//Last value was stored in temp1
											strcpy( auxString, "0temp1");
										else
											strcpy( auxString, "0temp2");

										sprintf(snum, "%d", lookupDepth($1, depth));
										sprintf(snum2, "%d", lookup(auxString));
										setValueByName($1, getValueByName(auxString)); 	//Sets the value
										insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
									    cp++;											    		
									}else
									{	
										if(pointer_value)	
										{						
											strcpy( errTab[ce].error, "Invalid convertion.\n" );
											errTab[ce].line = cp;
											ce++;													
										}	
										else
										{									
											strcpy( errTab[ce].error, "Variable already exists.\n" );
											errTab[ce].line = cp;
											ce++;
										}
									}
									pointer_value_flag = false; //reset variable
									pointer_value_flag2 = false; //reset variable
								}
			| 	tVAR			{		
									if(lookupDepth($1, depth) == -1)	//Variable doesn't exist at this depth
									{
										insert($1, 0, depth);		//new int

										sprintf(snum, "%d", lookupDepth($1, depth));
										sprintf(snum2, "%d", lookupType($1));
										insert_Instruction( "ALLOUER", snum, $1, snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									}else
									{												
										strcpy( errTab[ce].error, "Variable already exists.\n" );
										errTab[ce].line = cp;
										ce++;
									}
								}
			;

DeclarPtr	:	tINT tMUL DeclarPtr tPV
			|	DeclarPtr tV DeclarPtr
			| 	tVAR tE Expr	{				
									if(lookupDepth($1, depth) == -1 && pointer_value) //Variable exists and the expression is correct
									{
										insert($1, 2, depth);		//new pointer

										sprintf(snum, "%d", lookupDepth($1, depth));
										sprintf(snum2, "%d", lookupType($1));
										insert_Instruction( "ALLOUER", snum, $1, snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									    if( temp1_flag )	//temp1 is not being used
											sprintf(auxString, "0temp1");	
										else
											sprintf(auxString, "0temp2");		

										sprintf(snum, "%d", lookupDepth($1, depth));
										sprintf(snum2, "%d", lookup(auxString));		
										setValueByName($1, getValueByName(auxString)); 	//Sets the value
										insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
									    cp++;		
									}else
									{				
										if(!pointer_value)
										{				
											strcpy( errTab[ce].error, "Invalid expression.\n" );
											errTab[ce].line = cp;
											ce++;
										}else
										{							
											strcpy( errTab[ce].error, "Variable %s already exists.\n" );
											errTab[ce].line = cp;
											ce++;
										}
									}
									pointer_value_flag = false; //reset variable
									pointer_value_flag2 = false; //reset variable
								}
				| 	tVAR		{
									if(lookupDepth($1, depth) == -1)
									{
										insert($1, 2, depth);			//new pointer

										sprintf(snum, "%d", lookupDepth($1, depth));
										sprintf(snum2, "%d", lookupType($1));
										insert_Instruction( "ALLOUER", snum, $1, snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									}else
									{												
										strcpy( errTab[ce].error, "Variable already exists.\n" );
										errTab[ce].line = cp;
										ce++;
									}	
								}
			;		

DeclarCnst	:	tCONST DeclarCnst tPV
			|	DeclarCnst tV DeclarCnst
			| 	tVAR tE Expr	{
									if(lookupDepth($1, depth) == -1 && !pointer_value) //Variable exists and the expression is correct
									{
										insert($1, 1, depth);		//new const		

										sprintf(snum, "%d", lookupDepth($1, depth));
										sprintf(snum2, "%d", lookupType($1));
										insert_Instruction( "ALLOUER", snum, $1, snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;											

									    if( temp1_flag )	//temp1 is not being used
											sprintf(auxString, "0temp1");	
										else
											sprintf(auxString, "0temp2");	

										sprintf(snum, "%d", lookupDepth($1, depth));
										sprintf(snum2, "%d", lookup(auxString));		
										setValueByName($1, getValueByName(auxString)); 	//Sets the value
										insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
									    cp++;		
									}else
									{											
												
										if(pointer_value)	
										{						
											strcpy( errTab[ce].error, "Invalid convertion.\n" );
											errTab[ce].line = cp;
											ce++;													
										}	
										else
										{									
											strcpy( errTab[ce].error, "Variable %s already exists.\n" );
											errTab[ce].line = cp;
											ce++;
										}
									}
									pointer_value_flag = false; //reset variable
									pointer_value_flag2 = false; //reset variable
								}
				|  tVAR			{
									if(lookupDepth($1, depth) == -1)
									{
										insert($1, 1, depth);		//new const

										sprintf(snum, "%d", lookupDepth($1, depth));
										sprintf(snum2, "%d", lookupType($1));
										insert_Instruction( "ALLOUER", snum, $1, snum2, "", cp ); //ALLOUER @var varName varType 
									    cp++;

									}else
									{												
										strcpy( errTab[ce].error, "Variable already exists.\n" );
										errTab[ce].line = cp;
										ce++;
									}
								}
			;

Val			:	tNUM		{
								if( !pointer_value_flag )	//pointer value hasn't been initialized
								{
									pointer_value_flag = true;
									pointer_value = false; 			//not a pointer expression
								}
												
								if( !temp1_flag )	//temp1 is not being used
								{
									temp1_flag = true;
									sprintf(auxString, "0temp1");	
								}else
								{
									temp1_flag = false;
									sprintf(auxString, "0temp2");	
								}	


								sprintf(snum, "%d", lookup(auxString));
								sprintf(snum2, "%d", $1);
								setValueByName(auxString, $1); 	//Sets the value
								insert_Instruction( "6", snum, snum2, "", "", cp ); //AFC @result num 
								cp++;

								$$ = lookup(auxString);
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

										if( !temp1_flag )	//temp1 is not being used
										{
											temp1_flag = true;
											sprintf(auxString, "0temp1");	
										}else
										{
											temp1_flag = false;
											sprintf(auxString, "0temp2");	
										}	

										sprintf(snum, "%d", lookup(auxString));
										sprintf(snum2, "%d", lookup($1));
										setValueByName(auxString, getValueByName($1)); 	//Sets the value
										insert_Instruction( "5", snum, snum2, "", "", cp ); //COP @result @operand1 
										cp++;

										$$ = lookup(auxString);	//temp contains Address of the pointer(to print the address of the pointed variable)
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

										$$ = lookup($1);	//Address of the pointer(to print the address of the pointed variable)
									}
								}
								else
								{
									strcpy( errTab[ce].error, "The variable " );
									strcat( errTab[ce].error, $1 );
									strcat( errTab[ce].error, " does not exist.\n" );		
									errTab[ce].line = cp;
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
												
										if( !temp1_flag )	//temp1 is not being used
										{
											temp1_flag = true;
											sprintf(auxString, "0temp1");	
										}else
										{
											temp1_flag = false;
											sprintf(auxString, "0temp2");	
										}						

										sprintf(snum, "%d", lookup(auxString));
										sprintf(snum2, "%d", lookup($2));		//Address of the pointer 
										setValueByName(auxString, getValueByName(lookupName(getValueByName($2)))); 	//Sets the value
										insert_Instruction( "D", snum, snum2, "", "", cp ); //PCOP @result @operand1 
										cp++;

										$$ = lookup(auxString);	//Address of the variable (to print value of the pointed variable)		
									}
									else
									{
										strcpy( errTab[ce].error, "The pointer '" );
										strcat( errTab[ce].error, $2 );
										strcat( errTab[ce].error, "' points to an invalid address.\n" );		
										errTab[ce].line = cp;
										ce++;
									}
								}
								else
								{
									strcpy( errTab[ce].error, "The pointer " );
									strcat( errTab[ce].error, $2 );
									strcat( errTab[ce].error, " does not exist.\n" );		
									errTab[ce].line = cp;
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
											errTab[ce].line = cp;
											ce++;
										}
									}
			;

Expr			:	Expr tPLUS Expr	{ 		
										 if( temp1_flag )	//value is in temp1
											sprintf(auxString, "%d", lookup("0temp1"));
										else
											sprintf(auxString, "%d", lookup("0temp2"));
										sscanf(auxString, "%d", &auxNum);

										 sprintf(snum, "%d", $1);
										 sprintf(snum2, "%d", $3);;
										 setValueByName( lookupName(auxNum), getValueByName(lookupName($1))+getValueByName(lookupName($3)) );
										 insert_Instruction( "1", auxString, snum, snum2, "", cp ); //ADD @result @operand1 @operand2
									     cp++;

									     $$=auxNum;
									}
				|	Expr tSOU Expr	{	
										 if( temp1_flag )	//value is in temp1
											sprintf(auxString, "%d", lookup("0temp1"));
										else
											sprintf(auxString, "%d", lookup("0temp2"));
										sscanf(auxString, "%d", &auxNum);

										 sprintf(snum, "%d", $1);
										 sprintf(snum2, "%d", $3);
										 setValueByName( lookupName(auxNum), getValueByName(lookupName($1))-getValueByName(lookupName($3)) );
										 insert_Instruction( "3", auxString, snum, snum2, "", cp ); //SOU @result @operand1 @operand2
									     cp++;

									     $$=auxNum;
									}
				|	Expr tMUL Expr	{								
										 if( temp1_flag )	//value is in temp1
											sprintf(auxString, "%d", lookup("0temp1"));
										else
											sprintf(auxString, "%d", lookup("0temp2"));
										sscanf(auxString, "%d", &auxNum);

										 sprintf(snum, "%d", $1);
										 sprintf(snum2, "%d", $3);;
										 setValueByName( lookupName(auxNum), getValueByName(lookupName($1))*getValueByName(lookupName($3)) );
										 insert_Instruction( "2", auxString, snum, snum2, "", cp ); //MUL @result @operand1 @operand2
									     cp++;

									     $$=auxNum;
									}
				|	Expr tDIV Expr	{ 
										if( temp1_flag )	//value is in temp1
											sprintf(auxString, "%d", lookup("0temp1"));
										else
											sprintf(auxString, "%d", lookup("0temp2"));
										sscanf(auxString, "%d", &auxNum);

										 sprintf(snum, "%d", $1);
										 sprintf(snum2, "%d", $3);
										 setValueByName( lookupName(auxNum), getValueByName(lookupName($1))/getValueByName(lookupName($3)) );
										 insert_Instruction( "4", auxString, snum, snum2, "", cp ); //DIV @result @operand1 @operand2
									     cp++;

									     $$=auxNum;
									}
				|	tPO Expr tPF
				|	Val 		
			;







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
		fprintf(fp, "Error found in line: %d \n %s \n", errTab[i].line, errTab[i].error );

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


void write_ASM_File()
{	
	FILE *ASM_File;	
	ASM_File = fopen("asm_Code.out","w");
	int total_lines = cp;
	for( int i=0; i<total_lines; i++)
	{
		if((strcmp(labTab[i].instruct, "ALLOUER") != 0) && (strcmp(labTab[i].instruct, "DESALLOUER") != 0))	//These two instructions are not implemented yet
		{
			fprintf(ASM_File, "%s %s %s %s\n", labTab[i].instruct, labTab[i].param1, labTab[i].param2, labTab[i].param3); 
		}
	}
	fprintf(ASM_File, "R\n"); 
	fclose(ASM_File);
}




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


	insert("a", 0, 0);
	setValueByName("a", 30);
	insert("b", 0, 0);
	//delete("a", 0);
	setValueByName("b", 40);
	insert("Pa", 2, 0);
	setValueByName("Pa", lookup("a"));
	insert("Pb", 2, 0);
	insert("Pc", 2, 0);
	setValueByName("Pc", 16);

	//delete("a");
	//delete("b");
	insert("c", 1, 0);
	insert("d", 0, 0);
	insert("e", 1, 0);
	//delete("c");
	//delete("d");
	insert("g", 1, 0);


	yyparse();
	functab_print(fp);
	symtab_print(fp);
	print_Label_Table();
	print_Error_Table();
	fprintf(fp, "Number of lines : %d\n", cp+1); 
	fclose(fp);
	write_ASM_File();

	return 0;
}




/*TODO: 
	- No initialized verification
	Functions:
		- Variables are created on a static addres, ALLOUER should use free spaces, not static spaces
		- Variables created outside the function are detected (Suggestion: Ask for a minimum depth to use (lookup), which is the depth of the function)
		- Certain times, when a variable is created on a function, there is a segmentation fault
	Pointers:
		- On CondValue	 Pointer comparisson is not implemented
	If: 	
			- Conditions must be like: ((cond)||(cond))  or  ((cond)||((cond)||(cond)))
	While:
			- Conditions must be like: ((cond)||(cond))  or  ((cond)||((cond)||(cond)))
	Errors:
		- When two errors arecommited one next to the other, the marker will say they were commited on the same line (because cp wasn't updated)
		- Error lines are taken from ASM code and not from the input code

	Whitespaces interfer with some tokens for example: int a; will detect the token "int " instead of "int"



| error 	{									
								strcpy( errTab[ce].error, "Expected variable or number in line: " );								
								sprintf(snum , "%d", cp);
								strcpy( errTab[ce].error, snum );								
								strcpy( errTab[ce].error, ".\n" );
								errTab[ce].line = cp;
								ce++;
      						}


NOTE:
	Temp variables are called: 0temp1 nor 0temp2	
*/