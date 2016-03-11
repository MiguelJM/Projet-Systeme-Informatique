#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* maximum size of hash table */
#define SIZE 255 
#define MAXTOKENLEN 40

/* power of two multiplier in hash function */
#define SHIFT 4

/* the hash function */
static int labHash ( char key )
{
  int temp = 0;
  temp = ((temp << SHIFT) + key) % SIZE;

  return temp;
}

/* a linked list of references (line nos) for each variable */
typedef struct labRefListRec 
{ 
     //int lineno;
     struct labRefListRec * next;
     /* MODIFIED */
     int lineno;          //Line number
} * RefList;


/* hash entry holds variable name and its reference list */
typedef struct labHashRec { 
     char st_name[MAXTOKENLEN];
     //int st_size;
     //RefList lines;
     /* MODIFIED */
     int st_address;          //Index where the variable is stored.
     int st_from;          //Index where the variable is stored.
     int st_to;
     struct labHashRec * next;
} * labNode;

/* the hash table */
static labNode labHashTable[SIZE];

 /* insert an entry with its line number - if entry
  *  already exists just add its reference line no.  
  */  
  /* MODIFIED */
void lab_set_to( int from, int to )
{ 
  int h = labHash((char) from);
  labNode l =  labHashTable[h];
  while ((l != NULL) && (from != l->st_from))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { 
    l = (labNode) malloc(sizeof(struct labHashRec));
    l->st_from = from;  
    l->st_to = to;
    //l->lines = (RefList) malloc(sizeof(struct RefListRec));
    //l->lines->lineno = lineno;
    //l->lines->next = NULL;
    l->next = labHashTable[h];
    labHashTable[h] = l; 
    l->st_address = h;
    printf("Label inserted.\n");
  }
  else /* found in table, so just add line number */
  { 
    printf("Label already exists.\n");
    /*
    RefList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (RefList) malloc(sizeof(struct RefListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;*/
  }
} 

/* return address of symbol if found or -1 if not found */
int lab_lookup ( int from )
{ 
  int h = labHash((char) from);
  labNode l =  labHashTable[h];
  while ((l != NULL) && (from != l->st_from))
    l = l->next;
  if (l == NULL){ 
    printf("Label not found.\n");
     return -1;
   }
  else{ 
    printf("Label found in %d.\n", l->st_address);
    return l->st_address;
  }
    printf("No labels on the table.\n");
}

/* return type value of symbol or -1 if symbol not found */
/*int lookupType( int from )
{
  char name = from;
  int h = hash(name);
  Node l =  hashTable[h];
  while ((l != NULL) && (from != l->st_from) != 0))
    l = l->next;
  if (l == NULL) {
    printf("Label not found.\n");
    return -1;
  }
  else {
    printf("The Var type is: %d.\n", l->st_type);
    return l->st_type;
  }
}*/


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
void labtab_print(FILE * of) {  
  int i;
  fprintf(of,"\n------- ------\n");
  fprintf(of,"From         To\n");
  fprintf(of,"-------- ------\n");
  for (i=0; i < SIZE; ++i)
  { 
    if (labHashTable[i] != NULL) //If there is a value on the list
    { 
      labNode l = labHashTable[i];
      while (l != NULL)
      { 
        //RefList t = l->lines;
        fprintf(of,"%-7i %-7i %-7i",l->st_from, l->st_to, l->st_address);

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