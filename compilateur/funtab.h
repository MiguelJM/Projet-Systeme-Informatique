#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* maximum size of hash table */
#define SIZE 255 
#define MAXTOKENLEN 40

/* power of two multiplier in hash function */
#define SHIFT 4

/* hash entry holds variable name and its reference list */
typedef struct HashRecFun { 
     char st_name[MAXTOKENLEN];
     int st_address;               //Address of the function
     int st_line;                  //Line where the function begins
     int st_type;                  //Return type 0 int 1 void
     struct HashRecFun * next;
} * NodeFunc;

/* the hash table */
static NodeFunc hashTableFunc[SIZE];

static int hashFunc(char *key);
int hashPreviousFunc(char *key);
int hashForInsertFunc(char *key);
void insertFunc(char *name, int type, int line);
int lookupFunc(char *name);
int lookupAddressFunc(int address);
int lookupTypeFunc(char *name);
int lookupLineFunc(char *name);
char* lookupNameFunc(int address);
void functab_print();

/* the hash function */
static int hashFunc ( char * key )
{ 
  int temp = 0;
  NodeFunc l =  hashTableFunc[temp];
  while ((l != NULL) && (strcmp(key,l->st_name) != 0))
  {
      l = l->next;
      temp++;
  }

  return temp;
}

/* Used to obtain the previous node to key */
int hashPreviousFunc ( char * key )
{ 
  int temp = 0;
  NodeFunc l =  hashTableFunc[temp];
  NodeFunc aux = l;
  while ((l != NULL) && (strcmp(key,l->st_name) != 0))
  {
      aux = l;
      l = l->next;
      temp++;
  }

  if( aux != l ) //There is no previous var
    return aux->st_address;
  else 
    return -1;
}

/* the hash function to insert variables */
int hashForInsertFunc ( char * key )
{ 
  int temp = 0;
  NodeFunc l =  hashTableFunc[temp];
  while ((l != NULL) && (strcmp(key,l->st_name) != 0))
  {
      if( l->st_address != temp )
          return temp;
      l = l->next;
      temp++;
  }

  return temp;
}

 /* insert an entry with its line number - if entry
  *  already exists just add its reference line no.  
  */
void insertFunc( char * name, int type, int line )
{ 
  int h = hashForInsertFunc(name);
  NodeFunc l =  hashTableFunc[h];
  
  if (l == NULL && h < SIZE) /* variable not yet in table and there is space on the table */
  { 
    l = (NodeFunc) malloc(sizeof(struct HashRec));
    strcpy(l->st_name, name);  
    /* ADDED */
    l->st_type = type; 
    l->st_address = h;
    l->st_line = line;
    hashTableFunc[h] = l; 

    if( h > 0 ) //It is not the first insertion 
    { 
      l->next = hashTableFunc[h-1]->next;
      hashTableFunc[h-1]->next = l; 
      hashTableFunc[h] = l;
    }   

    //printf("Var inserted. \n");
  }
  else /* found in table, so just add line number */
  { 
    printf("Var '%s' already exists or the table is full.\n", name);
  }
} 

/* return address of function if found or -1 if not found  BY NAME*/
int lookupFunc( char * name )
{ 
  int h = hashFunc(name);
  NodeFunc l =  hashTableFunc[h];

  if (l == NULL){ 
    //printf("Var not found.\n");
     return -1;
   }
  else{ 
   // printf("Var found in %d.\n", l->st_address);
    return l->st_address;
  }
    //printf("No Functions on the table.\n");
    return -1;
}

/* return address of function if found or -1 if not found  BY ADDRESS*/
int lookupAddressFunc ( int address )
{ 
  if( address >= SIZE )
     return -1;

  NodeFunc l =  hashTableFunc[address];
  if (l == NULL ){ 
    //printf("Var not found.\n");
     return -1;
   }
  else{ 
    //printf("Var found in %d.\n", l->st_address);
    return l->st_address;
  }
    //printf("No Functions on the table.\n");
  return -1;
}

/* return type value of symbol or -1 if symbol not found */
int lookupTypeFunc( char * name )
{
  int h = hashFunc(name);
  NodeFunc l =  hashTableFunc[h];

  if (l == NULL) {
   // printf("Function not found.\n");
    return -1;
  }
  else {
   // printf("The Function type is: %d.\n", l->st_type);
    return l->st_type;
  }
}

/* return type value of symbol or -1 if symbol not found */
int lookupLineFunc( char * name )
{
  int h = hashFunc(name);
  NodeFunc l =  hashTableFunc[h];

  if (l == NULL) {
   // printf("Function not found.\n");
    return -1;
  }
  else {
   // printf("The Function type is: %d.\n", l->st_type);
    return l->st_line;
  }
}

/* return name of symbol or -1 if symbol not found */
char* lookupNameFunc( int address )
{
  if( address >= SIZE )
     return "NULL";

  NodeFunc l =  hashTableFunc[address];

  if (l == NULL ) {
   // printf("Function not found.\n");
    return "NULL";
  }
  else {
   //printf("The Function name is: %s.\n", l->st_name);
    return l->st_name;
  }
}

/* print to stdout by default */ 
void functab_print(FILE * of) {  
  int i;
  fprintf(of,"\n               Function Table        \n");
  fprintf(of,"\n----------  ---------    ------    --------\n");
  fprintf(of,"Name         Address      Type       Line\n");
  fprintf(of,"----------  ---------    ------    --------\n");

  NodeFunc l = hashTableFunc[0];
  while (l != NULL)
  { 
    fprintf(of,"%-15s %-10i %-10i %-10i\n",l->st_name, l->st_address, l->st_type, l->st_line);
    l = l->next;
  }
} 