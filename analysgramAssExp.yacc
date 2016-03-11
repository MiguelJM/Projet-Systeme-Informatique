%{
	#include <stdio.h>	
	#include <string.h>
	#include <stdbool.h>

	int yylex(void);
	void yyerror(char *);
	FILE *fp;	

	#include "symtab.h"
	#include "labtab.h"

	struct symTable
	{
		char name[64];
		bool constant;		//0 es no 1 es constante y no puede ser modificada
		int value;
	};

	struct symTable table[255];
	int tableIndex = 0;
  
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
%token tIF
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
%token <nb> tNUM
%token tV
%token tCONST

%type <nb> Sum

%%


TestStart	:	TestMessage
			;

TestMessage	: 	Val		{printf("\n Succesful test");}
			;

Fonction	: 	tINT tID tPO Param tPF tCO Body tCF 	{printf("\n Fonction trouvee");}
			;
	
Param 		:	tINT tID tV Param 		{printf("\n Parametre trouve with ,");}
				| tINT tID				{printf("\n Parametre trouve without ,");}
			;
				
Body		:	Declar						{printf("\n Corriger Body");}
			|	If							{printf("\n Corriger Body");}
			|	While						{printf("\n Corriger Body");}
			|	Print						{printf("\n Corriger Body");}			
			;

If			:	tIF tPO Cond tPF tCO Body tCF	{printf("\n IF trouve");}
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

Declar		: 	| Declar tV Declar tPV	{printf("\n Declaration trouvee");}
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




