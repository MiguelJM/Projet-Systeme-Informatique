#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* maximum size of hash table */
#define SIZE 255 
#define MAXTOKENLEN 40

/* power of two multiplier in hash function */
#define SHIFT 4

/* Temporal variables positions */
#define temp1_position SIZE-2
#define temp2_position SIZE-1


/* a linked list of references (line nos) for each variable 
typedef struct RefListRec 
{ 
     //int lineno;
     struct RefListRec * next;
     /* ADDED 
     int type;          //Constant? - 0 no - 1 yes
} * RefList; */



/* hash entry holds variable name and its reference list */
typedef struct HashRec { 
     char st_name[MAXTOKENLEN];
     //int st_size;
     //RefList lines;
     int st_address;          //Index where the variable is stored.
     /* ADDED */
     int initialized;         //Is the variable initialized?
     int st_type;             //0 int 1 constant 2 pointe
     int st_value;           //Value of the variable
     struct HashRec * next;
} * Node;

/* the hash table */
static Node hashTable[SIZE];

static int hash(char *key);
void insert(char *name, int type);
int lookup(char *name);
int lookupAddress(int address);
int setValueByName(char *name, int value);
int getValueByName(char *name);
int lookupType(char *name);
char* lookupName(int address);
void symtab_print();
void initializeSymtab();

/*Funtion that initializes the Symtable*/
void initializeSymtab()
{
  Node l =  hashTable[temp1_position];
  l = (Node) malloc(sizeof(struct HashRec));

  //Temporal variable 1
  strcpy(l->st_name, "0temp1");
  l->st_address = temp1_position;
  l->st_type = 0;
  l->next = hashTable[temp2_position];
  hashTable[temp1_position] = l;

  l =  hashTable[temp2_position];
  l = (Node) malloc(sizeof(struct HashRec));

  //Temporal variable 1
  strcpy(l->st_name, "0temp2");
  l->st_address = temp2_position;
  l->st_type = 0;
  l->next = NULL;
  hashTable[temp2_position] = l;
 /* //l =  hashTable[SIZE];
  //l = (Node) malloc(sizeof(struct HashRec));

  //Temporal variable 2
  strcmp(hashTable[SIZE-1]->st_name, "0temp2");
  hashTable[SIZE-1]->st_address = SIZE-1;
  hashTable[SIZE-1]->st_type = 0;
  hashTable[SIZE-1]->next = NULL;  */
}

/* the hash function */
static int hash ( char * key )
{ 
  /*int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { 
    temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;*/
  if(strcmp(key,"0temp1") == 0)
    return temp1_position;  
  if(strcmp(key,"0temp2") == 0)
    return temp2_position;  

  int temp = 0;
  Node l =  hashTable[temp];
  while ((l != NULL) && (strcmp(key,l->st_name) != 0))
  {
      l = l->next;
      temp++;
  }

  return temp;
}


 /* insert an entry with its line number - if entry
  *  already exists just add its reference line no.  
  */
void insert( char * name, int type )
{ 
  /* ADDED */
  //int h = hash(name);
  int h = hash(name);
  Node l =  hashTable[h];
  /*while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;
*/
  if (l == NULL && h < temp1_position) /* variable not yet in table and there is space on the table */
  { 
    l = (Node) malloc(sizeof(struct HashRec));
    strcpy(l->st_name, name);  
    /* ADDED */
    l->st_type = type;
    //l->lines = (RefList) malloc(sizeof(struct RefListRec));
    //l->lines->lineno = lineno;
    //l->lines->next = NULL;

    l->st_address = h;
    //l->next = hashTable[h];
    //hashTable[h] = l; 
    hashTable[h] = l; //new

    if( h > 0 ) //new
    {
      hashTable[h-1]->next = hashTable[h]; //new
      hashTable[h]->next = NULL; //new
    }    

    printf("Var inserted. \n");
  }
  else /* found in table, so just add line number */
  { 
    printf("Var already exists or the table is full.\n");
    /*
    RefList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (RefList) malloc(sizeof(struct RefListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;*/
  }
} 

/* return address of symbol if found or -1 if not found  BY NAME*/
int lookup ( char * name )
{ 
  int h = hash(name);
  Node l =  hashTable[h];
  /*while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;*/
  if (l == NULL){ 
    printf("Var not found.\n");
     return -1;
   }
  else{ 
    printf("Var found in %d.\n", l->st_address);
    return l->st_address;
  }
    printf("No variables on the table.\n");
}

/* return address of symbol if found or -1 if not found  BY ADDRESS*/
int lookupAddress ( int address )
{ 
  Node l =  hashTable[address];
  if (l == NULL || address >= SIZE ){ 
    printf("Var not found.\n");
     return -1;
   }
  else{ 
    printf("Var found in %d.\n", l->st_address);
    return l->st_address;
  }
    printf("No variabless on the table.\n");
}

int setValueByName( char * name, int value )
{ 
  int h = hash(name);
  Node l =  hashTable[h];
  /*while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;*/
  if (l == NULL){ 
    printf("Var not found.\n");
     return -1;
   }
  else{ 
    printf("Var found in %d.\n", l->st_address);
    l->st_value = value;
     return 0;
  }
    printf("No variabless on the table.\n");
}

int getValueByName( char * name )
{ 
  int h = hash(name);
  Node l =  hashTable[h];
 /* while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;*/
  if (l == NULL){ 
    printf("Var not found.\n");
     return -1;
   }
  else{ 
    printf("Var found in %d.\n", l->st_address);
    return l->st_value;
  }
    printf("No variabless on the table.\n");
}

/* return type value of symbol or -1 if symbol not found */
int lookupType( char * name )
{
  int h = hash(name);
  Node l =  hashTable[h];
 /* while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;*/
  if (l == NULL) {
    printf("Variable not found.\n");
    return -1;
  }
  else {
    printf("The variable type is: %d.\n", l->st_type);
    return l->st_type;
  }
}

/* return name of symbol or -1 if symbol not found */
char* lookupName( int address )
{
  Node l =  hashTable[address];
  if (l == NULL || address >= SIZE ) {
    printf("Variable not found.\n");
    return "NULL";
  }
  else {
    printf("The variable name is: %s.\n", l->st_name);
    return l->st_name;
  }
}

/* set datatype of symbol returns 0 if symbol not found 
int setType( char * name, int t )
{
   int h = hash(name);
   Node l =  hashTable[h];
   while ((l != NULL) && (strcmp(name,l->st_name) != 0))
     l = l->next;
   if (l == NULL) return -1;
   else {
     l->st_type = t;
     return 0;
   }
}*/

/* print to stdout by default */ 
void symtab_print(FILE * of) {  
  int i;
  fprintf(of,"\n----------  ------     ----------  ----------- \n");
  fprintf(of,"Name         Type       Position      Value\n");
  fprintf(of,"----------  ------     ----------  ----------- \n");
 // for (i=0; i < SIZE; ++i)
 // { 
    //if (hashTable[i] != NULL) //If there is a value on the list
    //{ 
    Node l = hashTable[0];
    while (l != NULL)
    { 
      //RefList t = l->lines;
      fprintf(of,"%-13s %-10i %-10i %-10i \n",l->st_name, l->st_type, l->st_address, l->st_value);

      /*if (l->st_type == INT_TYPE)
         fprintf(of,"%-7s","int ");
      if (l->st_type == REAL_TYPE)
         fprintf(of,"%-7s","real");
      if (l->st_type == STR_TYPE)
         fprintf(of,"%-7s","string");*/


      /*while (t != NULL)
      { fprintf(of,"%4d ",t->lineno);
        t = t->next;
      }*/
      l = l->next;
    }

    /* Print temporal variables */
    l = hashTable[temp1_position];
    fprintf(of,"%-13s %-10i %-10i %-10i \n",l->st_name, l->st_type, l->st_address, l->st_value);
    l = hashTable[temp2_position];
    fprintf(of,"%-13s %-10i %-10i %-10i \n",l->st_name, l->st_type, l->st_address, l->st_value);
    //}
 // }
} 