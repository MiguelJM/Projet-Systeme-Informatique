%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
%}

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
%token tSTRING
%token tE
%token tMAIN
%token tSOU
%token tMUL
%token tDIV
%token tPRINT
%token tNUM
%token tV
%token tCONST
%token tNUM

%%

TestStart	:	TestMessage
		;

TestMessage	: 	Div		{printf("\n Succesful test");}
		;

Fonction	: 	tINT tID tPO Param tPF tCO Body tCF 	{printf("\n Fonction trouvee");}
			;
	
Param 		:	tINT tID tV Param 		{printf("\n Parametre trouve with ,");}
				| tINT tID				{printf("\n Parametre trouve without ,");}
			;
				
Body		:	tPO tPO tPO						{printf("\n Corriger Body");}				
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
					| tSTRING			{printf("\n PrintContText trouve");}
				;


Const		:	Declar tV Const tPV  	{printf("\n Constante trouvee");}
				|Declar tPV				{printf("\n Constante trouvee");}				
			;

Declar		: 	tINT tID tE Expr		{printf("\n Declaration trouvee");}
				| tINT tID				{printf("\n Declaration trouvee");}
			;

Expr		:	tNUM Op Expr		{printf("\n Expresion trouvee");}	
				| tNUM				{printf("\n Expresion trouvee");}
			;

Op			: 	tPLUS			{printf("\n Operateur trouve");}
				| tSOU			{printf("\n Operateur trouve");}
				| tMUL			{printf("\n Operateur trouve");}
				| tDIV			{printf("\n Operateur trouve");}				
			;

Main			: 	tMAIN tPO tPF tCO Body tCF		{printf("\n Main trouve");}
			;


Val			:	tNUM		{printf("\n Valeur avec Num trouvee");}
				| tID		{printf("\n Valeur avec ID trouvee");}
			;

/***TODO: Add () operators
	  Aren't Expr and Sum+Sub+Mult+Div the same thing? Take in mind the ASM translation	
***/
Sum			:	Val	tPLUS Val tPV	{ printf("\n Somme trouvee");}
			;

Sub			:	Val tSOU Val tPV		{printf("\n Substraction trouvee");}
			;

Mult		:	Val tMUL Val tPV		{printf("\n Multiplication trouvee");}
			;

Div			:	Val tDIV Val tPV		{printf("\n Division trouvee");}
			;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
	return 0;
}
