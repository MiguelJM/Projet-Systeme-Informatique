%{
	#include <stdio.h>	
	#include <string.h>
	#include <stdbool.h>

	int yylex(void);
	void yyerror(char *);

extern FILE *yyin;

#define maxINSTRUCT 2048 
#define maxSYMBOLS 255 

    int cp = 0;
    int ins[maxINSTRUCT][4];
    int symTab[maxSYMBOLS];

%}

%union {
	int nb;
}

%start TestStart
%token tRETURN;
%token tADD
%token tMUL
%token tSOU
%token tDIV
%token tCOP
%token tAFC
%token tJMP
%token tJMF
%token tINF
%token tSUP
%token tEQU
%token tPRI
%token tPCOP
%token tIPCOP
%token tCPA
%token tJMPA
%token tSPACE
%token <nb> tNUM 


%%


TestStart	:	TestMessage
			;

TestMessage	: Is		{printf("\n Succesful test\n");}
			| tRETURN	{printf("\n Return foud, end test\n");}
			;

Is : 	I Is
	| 	I
	;

I : 
	  tADD tSPACE tNUM tSPACE tNUM tSPACE tNUM
      {
        ins[cp][0] = tADD;
        ins[cp][1] = $3;
        ins[cp][2] = $5;
        ins[cp][3] = $7;
        cp++;
      }
    | tMUL tSPACE tNUM tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tMUL;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
	        ins[cp][3] = $7;
        	cp++;
      }
    | tSOU tSPACE tNUM tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tSOU;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
	        ins[cp][3] = $7;
        	cp++;
      }
    | tDIV tSPACE tNUM tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tDIV;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
	        ins[cp][3] = $7;
        	cp++;
      }
    | tCOP tSPACE tNUM tSPACE tNUM 
      {
            ins[cp][0] = tCOP;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
        	cp++;
      }
    | tAFC tSPACE tNUM tSPACE tNUM 
      {
            ins[cp][0] = tAFC;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
        	cp++;
      }
    | tJMP tSPACE tNUM
      {
            ins[cp][0] = tJMP;
	        ins[cp][1] = $3;
        	cp++;
      }
    | tJMF tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tJMF;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
        	cp++;
      }
    | tINF tSPACE tNUM tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tINF;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
	        ins[cp][3] = $7;
        	cp++;
      }
    | tSUP tSPACE tNUM tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tSUP;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
	        ins[cp][3] = $7;
        	cp++;
      }
    | tEQU tSPACE tNUM tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tEQU;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
	        ins[cp][3] = $7;
        	cp++;
      }
    | tPRI tSPACE tNUM
      {
            ins[cp][0] = tPRI;
	        ins[cp][1] = $3;
        	cp++;
      }
    | tPCOP tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tPCOP;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
        	cp++;
      }
    | tIPCOP tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tIPCOP;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
        	cp++;
      }
    | tCPA tSPACE tNUM tSPACE tNUM
      {
            ins[cp][0] = tCPA;
	        ins[cp][1] = $3;
	        ins[cp][2] = $5;
        	cp++;
      }
    | tJMPA tSPACE tNUM 
      {
            ins[cp][0] = tJMPA;
	        ins[cp][1] = $3;
        	cp++;
      }
    ;

%%

void yyerror(char *s) {
	printf("%s\n", s);
	//fprintf(stderr, "%s\n", s);
}

int main(void) {

	printf("Interpreter V1.0\n\n");

	yyin = fopen("asm_Code.out", "r");

	if(yyin == NULL)
	{
		printf("Error: File not found.\n");
		return -1;
	}
	else
	{
		do{
			yyparse();
			printf("%p\n",yyin);
		}while(!feof(yyin));
	}

	//yyparse();

	int total_lines = cp;

	printf("\nLecture end.\n");

	printf("\nPrinting instructions.\n");
	for( cp=0; cp < total_lines; cp++)
	{
		printf("%d %d %d %d\n", ins[cp][0], ins[cp][1], ins[cp][2], ins[cp][3]);
	}

	printf("\nExecuting the code.\n");
	for( cp=0; cp < total_lines; cp++)
	{
		switch(ins[cp][0])
		{
			case tADD:	
				symTab[ins[cp][1]] = symTab[ins[cp][2]] + symTab[ins[cp][3]];

			break;

			case tMUL: 
				symTab[ins[cp][1]] = symTab[ins[cp][2]] * symTab[ins[cp][3]];
			break;

			case tSOU: 
				symTab[ins[cp][1]] = symTab[ins[cp][2]] - symTab[ins[cp][3]];
			break;	

			case tDIV: 
				symTab[ins[cp][1]] = symTab[ins[cp][2]] / symTab[ins[cp][3]];
			break;

			case tCOP: 
				symTab[ins[cp][1]] = symTab[ins[cp][2]];
			break;

			case tAFC: 
				symTab[ins[cp][1]] = ins[cp][2];
			break;

			case tJMP:
				cp = symTab[ins[cp][1]];
			break;

			case tJMF:
				if( symTab[ins[cp][1]] == 0 )	//If the condition is false
					cp = symTab[ins[cp][2]];	
			break;

			case tINF:
				if( symTab[ins[cp][2]] < symTab[ins[cp][3]] )	
					symTab[ins[cp][1]] == 1;
			break;

			case tSUP:
				if( symTab[ins[cp][2]] > symTab[ins[cp][3]] )	
					symTab[ins[cp][1]] == 1;
			break;

			case tEQU:
				if( symTab[ins[cp][2]] == symTab[ins[cp][3]] )	
					symTab[ins[cp][1]] == 1;
			break;

			case tPRI:	
				printf("%d\n", symTab[ins[cp][1]]);
			break;

			case tPCOP:
				symTab[ins[cp][1]] = symTab[symTab[ins[cp][2]]];
			break;

			case tIPCOP:
				symTab[symTab[ins[cp][1]]] = symTab[ins[cp][2]];
			break;

			case tCPA:
				symTab[ins[cp][1]] = ins[cp][2];
			break;

			case tJMPA:
				cp = ins[cp][1];
			break;

			default:	//UNKNOWN instruction
			break;
		}
	}
	printf("\n");

	return 0;
}




/*TODO: 
	- There are some numbers reserved for the token detection (i.e. 1 for tADD), and can not be used for any other thing.
*/