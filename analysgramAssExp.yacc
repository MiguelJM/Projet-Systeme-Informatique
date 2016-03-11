%{
	#include <stdio.h>	
	#include <string.h>
	#include <stdbool.h>

	int yylex(void);
	void yyerror(char *);
	FILE *fp;	

	#include "symtab.h"
	#include "labtab.h"

#define instSIZE 1000 

	struct symTable
	{
		char name[64];
		bool constant;		//0 es no 1 es constante y no puede ser modificada
		int value;
	};

	struct symTable table[255];
	int tableIndex = 0;

	int pc = 0; //instruction counter
  
%}

%union {
	int nb;
	char * variable;
}

%start TestStart
%token tINT 
%token tDIF
%token tID
%token tOR
%token tAND
%token tPO
%token tPF
%token tCO
%token tCF
/*%token tIF*/
%token tWHILE
%token tPV
%token tPLUS
%token <variable> tVAR
%token tE
%token tMAIN
%token tSOU
%token tMUL
%token tDIV
%token tPRINT
%token <nb> tNUM tIF
%token tV
%token tCONST

%type <nb> Expr If

%right tE
%left tPLUS tSOU
%left tMUL tDIV


%%


TestStart	:	TestMessage
			;

TestMessage	: 	Main		{printf("\n Succesful test");}
			;

Fonction	: 	tINT tID tPO Param tPF tCO Body tCF 	{printf("\n Fonction trouvee");}
			;
	
Param 		:	tINT tID tV Param 		{printf("\n Parametre trouve with ,");}
				| tINT tID				{printf("\n Parametre trouve without ,");}
			;
				
Body		:	Declar						{printf("\n Body trouve");}
			|	If							{printf("\n Body trouve");}
			|	While						{printf("\n Body trouve");}
			|	Print						{printf("\n Body trouve");}	
			| 	Assign						{printf("\n Body trouve");}
			|	Body Body					{printf("\n Body trouve");}		
			;

Assign 		:	tID tE Declar tPV			{printf("\n Assignation trouvee");}
			|	tID tE Val tPV				{printf("\n Assignation trouvee");}
			;

If			:	tIF tPO Cond tPF tCO Body tCF	{
													printf("\n IF trouve");
												 	$1 = pc;
												 	pc++;
													printf("\n %d", $1);
												 }
			;

Cond		:	Val tDIF Val	{printf ("\n Condition trouvee");}
				| tPO Cond tPF tOR tPO Cond tPF		{printf("\n Condition trouvee");}
				| tPO Cond tPF tAND tPO Cond tPF	{printf("\n Condition trouvee");}
			;

While		:	tWHILE tPO Cond tPF tCO Body tCF	{printf("\n While trouve");}
				;

Print 		:	tPRINT tPO PrintCont tPF tPV		{printf("\n Print trouve");}				
			;

PrintCont	:	PrintContText tPLUS PrintCont	{printf("\n Contenu du Print trouve");}
				| PrintContText					{printf("\n Contenu du Print trouve");}
			;

PrintContText	:	Val 				{printf("\n PrintContText trouve");}
					| tVAR			{printf("\n PrintContText trouve");}
				;


Const		:	Declar tV Const tPV  	{printf("\n Constante trouvee");}
				|Declar tPV				{printf("\n Constante trouvee");}				
			;

Declar		: 	Declar tPV 				{printf("\n Declaration trouvee");}
				| Declar tV Declar 		{printf("\n Declaration trouvee");}
				| tINT tID tE Expr 		{printf("\n Declaration trouvee");}
				| tINT tID				{printf("\n Declaration trouvee");}
			;

Main		: 	tMAIN tPO tPF tCO Body tCF		{printf("\n Main trouve");}
			;


Val			:	tNUM		{
								printf("\n Valeur avec Num trouvee %d", $1);
								fprintf(fp, "Val : %d \n", $1);
							}
				| tID		{	
								printf("\n Valeur avec ID trouvee");
								fprintf(fp, "Val : \n");
							 }
			;

/*
Ins :   tADD tNUM tNUM tNUM   { $2 = $3 + $4; }
        | tSUB tNUM tNUM tNUM { $2 = $3 - $4; }
        | tMUL tNUM tNUM tNUM { $2 = $3 * $4; }
        | tDIV tNUM tNUM tNUM { $2 = $3 / $4; }
*/


/*TODO: Test Expr*/

Expr			:	Expr tPLUS Expr	{ 	printf("\n Somme trouvee");}
				|	Expr tSOU Expr	{	printf("\n Substraction trouvee");}
				|	Expr tMUL Expr	{	printf("\n Multiplication trouvee");}
				|	Expr tDIV Expr	{ 
											fprintf(fp, "\nFirst number : \n"); 
										}
										/*{fprintf(fp, "\nMOV ax,%d\nADD ax,%d\n",$1,$3); }*/
				|	tPO Expr tPF
				|	Val
			;








/*Expr		:	tNUM Op Expr		{printf("\n Expresion trouvee");}	
				| tNUM				{printf("\n Expresion trouvee");}
			;

Op			: 	tPLUS			{printf("\n Operateur trouve");}
				| tSOU			{printf("\n Operateur trouve");}
				| tMUL			{printf("\n Operateur trouve");}
				| tDIV			{printf("\n Operateur trouve");}				
			;*/

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}



int main(void) {


	//Instruction (label) table
	int **lableTable = malloc(instSIZE * 4 * sizeof(int));

	//Initialization of the label table
	int i;
	for(i = 0; i < instSIZE; i++)
	    lableTable[i] = malloc(4 * sizeof(int));


	printf("\nParser V2.0\n\n");

	fp = fopen("assOutput.out","w");

	/*insertSymbol("a", 1, 10);
	insertSymbol("a", 0, 10);
	assignValue("a", 11);*/


	lookup("a");
	insert("a", 0);
	lookup("a");
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
	lookup("e");
	symtab_print(fp);



	yyparse();
	fclose(fp);
	return 0;
}




