%{
#include <string.h>
#include <stdlib.h>
#include "y.tab.h"
%}

%%
"int" return(tINT);
"const" return(tCONST);

"<"  return(tDIF);
">"  return(tDIF);
"==" return(tDIF);
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
[a-zA-Z][a-zA-Z0-9_]* 	return(tID);
[0-9]+ 			return(tNUM);
["][a-zA-Z0-9]*["]		return(tSTRING);
%%
/*
void main(void){
	yylex();
}*/
