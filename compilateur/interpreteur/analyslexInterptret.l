%{
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%option yylineno

%%
"R" return(tRETURN);
"A" return(tADD);
"B" return(tMUL);
"C" return(tSOU);
"D" return(tDIV);
"E" return(tCOP);
"F" return(tAFC);
"AA" return(tJMP);
"AB" return(tJMF);
"AC" return(tINF);
"AD" return(tSUP);
"AE" return(tEQU);
"AF" return(tPRI);
"BA" return(tPCOP);
"BB" return(tIPCOP);
"BC" return(tCPA);
"BD" return(tJMPA);
"FE" return(tALL);	//Allouer
"FF" return(tDESA);	//Desallouer
[ \t]+ 	return(tSPACE);    /*  ignore end of line */

[0-9]+ {
				yylval.nb = atof(yytext); 
				return(tNUM);
			}	

\n  ;   /*  ignore end of line */

%%

/*
void main(void){
	yylex();
}*/
