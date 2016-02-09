%{
#include <string.h>
#include "y.tab.h"
%}

%%
[ \t]+ printf(" ");
"int" printf("Trouvé un tINT!\n");
"const" printf("Trouvé un tConst!\n");

"<"  printf("Trouvé un tDIF!\n");
">"  printf("Trouvé un tDIF!\n");
"==" printf("Trouvé un tDIF!\n");
"!=" printf("Trouvé un tDIF!\n");
"("  printf("Trouvé un tPO!\n");
")"  printf("Trouvé un tPF!\n");
"||" printf("Trouvé un tOR!\n");
"&&" printf("Trouvé un tAND!\n");
"{"  printf("Trouvé un tCO!\n");
"}"  printf("Trouvé un tCF!\n");
";"  printf("Trouvé un tPV!\n");
"+"  printf("Trouvé un tPLUS!\n");
"-"  printf("Trouvé un tSOU!\n");
"*"  printf("Trouvé un tMUL!\n");
"/"  printf("Trouvé un tDIV!\n");
"="  printf("Trouvé un tE!\n");

"printf"  printf("Trouvé un tPRINT!\n");  
"if" printf("Trouvé un tIF!\n");
"while" printf("Trouvé un tWHILE!\n"); 
[a-zA-Z][a-zA-Z0-9_]* printf("Trouvé un tID!\n");
[0-9]+ printf("Trouvé un tNUM!\n");
%%
void main(void){
	yylex();
}

