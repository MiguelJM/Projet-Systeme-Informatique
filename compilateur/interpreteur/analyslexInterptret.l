%{
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%
"R" return(tRETURN);
"1" return(tADD);
"2" return(tMUL);
"3" return(tSOU);
"4" return(tDIV);
"5" return(tCOP);
"6" return(tAFC);
"7" return(tJMP);
"8" return(tJMF);
"9" return(tINF);
"A" return(tSUP);
"B" return(tEQU);
"C" return(tPRI);
"D" return(tPCOP);
"E" return(tIPCOP);
"F" return(tCPA);
"10" return(tJMPA);
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
