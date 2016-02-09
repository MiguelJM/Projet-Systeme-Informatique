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
"!=" printf("Trouvé un tDIF!\n");%{
#include <string.h>
#include "y.tab.h"
#include <stdlib.h>
%}

%%
[ \t]+ printf(" ");
"int" printf("Trouvé un tINT!\n");
"const" printf("Trouvé un tConst!\n");

"<"  printf("Trouvé un tDIF!\n"); return(tDIF);
">"  printf("Trouvé un tDIF!\n"); return(tDIF);
"==" printf("Trouvé un tDIF!\n"); return(tDIF);
"!=" printf("Trouvé un tDIF!\n"); return(tDIF);
"("  printf("Trouvé un tPO!\n");  return(tPO);
")"  printf("Trouvé un tPF!\n");  return(tPF);
"||" printf("Trouvé un tOR!\n");  return(tOR);
"&&" printf("Trouvé un tAND!\n"); return(tAND);
"{"  printf("Trouvé un tCO!\n");  return(tCO);
"}"  printf("Trouvé un tCF!\n");  return(tCF);
";"  printf("Trouvé un tPV!\n");  return(tPV);
"+"  printf("Trouvé un tPLUS!\n");return(tPLUS);
"-"  printf("Trouvé un tSOU!\n"); return(tSOU);
"*"  printf("Trouvé un tMUL!\n"); return(tMUL);
"/"  printf("Trouvé un tDIV!\n"); return(tDIV);
"="  printf("Trouvé un tE!\n");   return(tE);

"printf"  printf("Trouvé un tPRINT!\n");          return(tPRINT);
"if" printf("Trouvé un tIF!\n");                  return(tIF);
"while" printf("Trouvé un tWHILE!\n");            return(tWHILE);
[a-zA-Z][a-zA-Z0-9_]* printf("Trouvé un tID!\n"); return(tID);
[0-9]+ printf("Trouvé un tNUM!\n");               return(tNUM);
%%
void main(void){
	yylex();
}
