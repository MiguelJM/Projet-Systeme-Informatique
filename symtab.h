#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* maximum size of hash table */
#define SIZE 255 
#define MAXTOKENLEN 40

/* power of two multiplier in hash function */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ 
  int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { 
    temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* a linked list of references (line nos) for each variable */
typedef struct RefListRec 
{ 
     //int lineno;
     struct RefListRec * next;
     /* ADDED */
     int type;          //Constant? - 0 no - 1 yes
} * RefList;


/* hash entry holds variable name and its reference list */
typedef struct HashRec { 
     char st_name[MAXTOKENLEN];
     //int st_size;
     //RefList lines;
     int st_value;          //Index where the variable is stored.
     /* ADDED */
     int st_type;
     struct HashRec * next;
} * Node;

/* the hash table */
static Node hashTable[SIZE];

 /* insert an entry with its line number - if entry
  *  already exists just add its reference line no.  
  */
void insert( char * name, int type )
{ 
  /* ADDED */
  int h = hash(name);
  Node l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { 
    l = (Node) malloc(sizeof(struct HashRec));
    strcpy(l->st_name, name);  
    /* ADDED */
    l->st_type = type;
    //l->lines = (RefList) malloc(sizeof(struct RefListRec));
    //l->lines->lineno = lineno;
    //l->lines->next = NULL;
    l->next = hashTable[h];
    hashTable[h] = l; 
    l->st_value = h;
    printf("Var inserted.\n");
  }
  else /* found in table, so just add line number */
  { 
    printf("Var already exists.\n");
    /*
    RefList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (RefList) malloc(sizeof(struct RefListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;*/
  }
} 

/* return value (address) of symbol if found or -1 if not found */
int lookup ( char * name )
{ 
  int h = hash(name);
  Node l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;
  if (l == NULL){ 
    printf("Var not found.\n");
     return -1;
   }
  else{ 
    printf("Var found in %d.\n", l->st_value);
    return l->st_value;
  }
    printf("No variabless on the table.\n");
}

/* return type value of symbol or -1 if symbol not found */
int lookupType( char * name )
{
  int h = hash(name);
  Node l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->st_name) != 0))
    l = l->next;
  if (l == NULL) {
    printf("Variable not found.\n");
    return -1;
  }
  else {
    printf("The variable type is: %d.\n", l->st_type);
    return l->st_type;
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

  printf("the name is %-12s", hashTable[97]->st_name);
  fprintf(of,"\n------------ ------ ---------- \n");
  fprintf(of,"Name         Type       Position\n");
  fprintf(of,"------------ ------ ---------- \n");
  for (i=0; i < SIZE; ++i)
  { 
    if (hashTable[i] != NULL) //If there is a value on the list
    { 
      Node l = hashTable[i];
      while (l != NULL)
      { 
        //RefList t = l->lines;
        fprintf(of,"%-12s %-7i %-7i",l->st_name, l->st_type, l->st_value);

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
        fprintf(of,"\n");
        l = l->next;
      }
    }
  }
} 