%{
	#include <stdio.h>	
	#include <string.h>
	#include <stdbool.h>

	int yylex(void);
	void yyerror(char *);

extern FILE *yyin;
extern int yylineno;     //To keep track of the lex lines

#define maxINSTRUCT 2048 
#define maxSYMBOLS 255 

    int cp = 0;
    int ins[maxINSTRUCT][4];
    int symTab[maxSYMBOLS];

%}

%union {
	int nb;
}

%start Is
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
%token tALL
%token tDESA
%token <nb> tNUM 


%%

Is : 	I Is
	| 	I
	| tRETURN
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
				printf("JUMP TO: %d\n", $5);	
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
    | tALL 
      {
            ins[cp][0] = tJMP;	//Ignore
	        ins[cp][1] = cp+1;
        	cp++;
      }
    | tDESA
      {
            ins[cp][0] = tJMP;	//Ignore
	        ins[cp][1] = cp+1;	
        	cp++;
      }
	| tSPACE /* NOTHING */
    ;

%%

void yyerror(char *s) {
	printf("%s\n", s);
	//fprintf(stderr, "%s\n", s);
}

int main(void) {

	printf("\nInterpreter V1.0\n");

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

	cp=0;
	while( cp < total_lines )
	{
		//printf("cp: %d ", cp);
		switch(ins[cp][0])
		{
			case tADD:	
			//printf("ADD %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				symTab[ins[cp][1]] = symTab[ins[cp][2]] + symTab[ins[cp][3]];
				cp++;
			break;

			case tMUL: 
			//printf("MUL %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				symTab[ins[cp][1]] = symTab[ins[cp][2]] * symTab[ins[cp][3]];
				cp++;
			break;

			case tSOU: 
			//printf("SOU %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				symTab[ins[cp][1]] = symTab[ins[cp][2]] - symTab[ins[cp][3]];
				cp++;
			break;	

			case tDIV: 
			//printf("DIV %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				symTab[ins[cp][1]] = symTab[ins[cp][2]] / symTab[ins[cp][3]];
				cp++;
			break;

			case tCOP: 
			//printf("COP %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				symTab[ins[cp][1]] = symTab[ins[cp][2]];
				cp++;
			break;

			case tAFC: 
			//printf("AFC %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				symTab[ins[cp][1]] = ins[cp][2];
				cp++;
			break;

			case tJMP:
			//printf("JMP %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				cp = ins[cp][1];
			break;

			case tJMF:
			//printf("JMF %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				if( symTab[ins[cp][1]] == 0 )	//If the condition is false
					cp = ins[cp][2];
				else
					cp++;
			break;

			case tINF:
			//printf("INF %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				if( symTab[ins[cp][2]] > symTab[ins[cp][3]] )	
					symTab[ins[cp][1]] = 1;
				else
					symTab[ins[cp][1]] = 0;
				cp++;
			break;

			case tSUP:
			//printf("SUP %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				if( symTab[ins[cp][2]] < symTab[ins[cp][3]] )
					symTab[ins[cp][1]] = 1;
				else
					symTab[ins[cp][1]] = 0;
				cp++;
			break;

			case tEQU:
			//printf("EQU %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				if( symTab[ins[cp][2]] == symTab[ins[cp][3]] )	
					symTab[ins[cp][1]] = 1;
				else
					symTab[ins[cp][1]] = 0;
				cp++;
			break;

			case tPRI:	
			//printf("PRI %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				printf("%d\n", symTab[ins[cp][1]]);
				cp++;
			break;

			case tPCOP:
			//printf("PCOP %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				symTab[ins[cp][1]] = symTab[symTab[ins[cp][2]]];
				cp++;
			break;

			case tIPCOP:
			//printf("IPCOP %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				symTab[symTab[ins[cp][1]]] = symTab[ins[cp][2]];
				cp++;
			break;

			case tCPA:
			//printf("CPA %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				symTab[ins[cp][1]] = ins[cp][2];
				cp++;
			break;

			case tJMPA:
			//printf("JMPA %d %d %d\n", ins[cp][1], ins[cp][2], ins[cp][3]);
				cp = ins[cp][1];
				cp++;
			break;

			default:	//UNKNOWN instruction
				cp++;
			break;
		}
	}
	printf("\n");

	return 0;
}




/*TODO: 
	- There are some numbers reserved for the token detection (i.e. 1 for tADD), and can not be used for any other thing.
*/