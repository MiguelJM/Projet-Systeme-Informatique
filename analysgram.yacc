%{
	#include <stdio.h>
	int yylex(void);
	void yyerror(char *);
%}

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
%token tString
%token tE
%token tMAIN
%token tSOU
%token tMUL
%token tDIV
%token tPRINT
%token tNUM
%token tV

%%

Fonction	: 	tINT tID tPO Param tPF tCO Body tCF 
				{printf("Fonction trouvee");}
			;
	
Param 		:	tINT tID tV Param
			| tINT tID
			| 
				{printf("Parametre trouve");}
			;
				
Body		:	tPO tPO tPO
				{printf("Corriger Body");}
			;

If		:	tIF tPO Cond tPF tCO Body tCF
				{printf("IF trouve");}
			;

Cond		:	tID tDIF tID
			| tPO Cond tPF tOR tPO Cond tPF
			| tPO Cond tPF tAND tPO Cond tPF
			| tINT tDIF tINT
				{printf("Condition trouvee");}
			;

While		:	tWHILE tPO Cond tPF tCO Body tCF
				{printf("While trouve");}
			;

Print 		:	tPRINT tPO PrintCont tPF tPV
				{printf("Print trouve");}
			;

PrintCont	:	tID tPLUS PrintCont
			| tString tPLUS PrintCont
			| tID
			| tString
				{printf("Contenu du Print trouve");}
			;

Const		:	Declar tV Const
			Declar tPV
				{printf("Constante trouvee");}
			;

Declar		:	tINT tID tE Expr
			| tINT tID
				{printf("Declaration trouvee");}
			;

Expr		:	tNUM Op Expr	
			| tNUM
				{printf("Expresion trouvee");}
			;

Op		: 	tPLUS
			| tSOU
			| tMUL
			| tDIV
				{printf("Operateur trouve");}
				
			;

Main		: 	tMAIN tPO tPF tCO Body tCF
				{printf("Condition trouve");}
			;


Val		: 	tINT
			| tID
				{printf("Valeur trouvee");}
			;

/***TODO: Add () operators.***/
Sum		:	Val tPLUS Val tPV	
				{ $$=$1+$3; printf("Somme trouvee");}
			;
Sub		:	Val tSOU Val tPV	
				{printf("Substraction trouvee");}
			;
Mult		:	Val tMUL Val tPV	
				{printf("Multiplication trouvee");}
			;
Div		:	Val tDIV Val tPV	
				{printf("Division trouvee");}
			;

%%

void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int main(void) {
	yyparse();
	return 0;
}
