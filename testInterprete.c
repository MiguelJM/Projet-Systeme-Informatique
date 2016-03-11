%{

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int yylex(void);
void yyerror(char *);
FILE *fp;

#include "symtab.h"

%}

%union{
    int nb;
    int i = 0;
    int ins[512][4];
    char * variable;
}

%%

Is : I Is | I;

I : tPLUS tNUM tNUM tNUM
    {
        ins[i][0] = tPLUS;
        ins[i][1] = $2;
        ins[i][2] = $3;
        ins[i][3] = $4;
        i++;
    }
    | tSOU tNUM tNUM tNUM
        {
            ins[i][0] = tSOU;
            ins[i][1] = $2;
            ins[i][2] = $3;
            ins[i][3] = $4;
            i++;
        }
    | tMUL tNUM tNUM tNUM
        {
            ins[i][0] = tMUL;
            ins[i][1] = $2;
            ins[i][2] = $3;
            ins[i][3] = $4;
            i++;
        }
    | tDIV tNUM tNUM tNUM
        {
            ins[i][0] = tDIV;
            ins[i][1] = $2;
            ins[i][2] = $3;
            ins[i][3] = $4;
            i++;
        };
%%

yyparse();
int n = 0;
while(n < i){
    if(ins[n][0] == tADD){
        m[ins[n][1]] = "="
        m[ins[n][1]] = "+"
        m[ins[n][1]] = ";"
        n++;
    }
    else if(ins[n][0] == tSOU){
        m[ins[n][1]] = "="
        m[ins[n][1]] = "-"
        m[ins[n][1]] = ";"
        n++;
    }
    else if(ins[n][0] == tMUL){
        m[ins[n][1]] = "="
        m[ins[n][1]] = "*"
        m[ins[n][1]] = ";"
        n++;
    }
    else if(ins[n][0] == tDIV){
        m[ins[n][1]] = "="
        m[ins[n][1]] = "/"
        m[ins[n][1]] = ";"
        n++;
    }
}


