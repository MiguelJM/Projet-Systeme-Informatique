%{
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%
"int" return(tINT);

"<"  return(tMIN);
">"  return(tMAY);
"<=" return(tMINEQU);
">=" return(tMAYEQU);
"==" return(tEQU);
"!=" return(tDIF);
"("  return(tPO);
")"  return(tPF);
"||" return(tOR);
"&&" return(tAND);
"{"  return(tCO);
"}"  return(tCF);
";"  return(tPV);
"+"  return(tPLUS);
"-"  return(tSOU);
"*"  return(tMUL);
"/"  return(tDIV);
"="  return(tE);
","  return(tV);

"main"			return(tMAIN);
"printf"  		return(tPRINT);
"if" 			return(tIF);
"while" 		return(tWHILE);
"const"			return(tCONST);
"else"			return(tELSE);
"\""				return(tGUILLEMETS);
[0-9]+ 					{
							yylval.nb = atof(yytext); 
							return(tNUM);
						}	
[a-zA-Z][a-zA-Z0-9_]*	{
							yylval.variable = strdup(yytext); 
							return(tVAR);
						}	
[a-zA-Z0-9_\ \\]*		{
							yylval.variable = strdup(yytext); 
							return(tSTRING);
						}
%%
/*
void main(void){
	yylex();
}*/
