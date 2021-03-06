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
     int st_initialized;         //Is the variable initialized?
     int st_depth;               //Was the variable declared inside a while, function or if? How deep?
     int st_type;             //0 int 1 constant 2 pointer
     int st_value;           //Value of the variable
     struct HashRec * next;
} * Node;

/* the hash table */
static Node hashTable[SIZE];

static int hash(char *key, int depth);
int hashPrevious(char *key, int depth);
int hashLastDepth(char *key);
int hashForInsert(char *key, int depth);
void insert(char *name, int type, int depth);
Node delete(char *name, int depth);
void deleteByDepth(int depth);
int lookup(char *name);
int lookupAddress(int address);
int setValueByName(char *name, int value);
int getValueByName(char *name);
int lookupType(char *name);
int lookupDepth(char *name, int depth);
char* lookupName(int address);
int getInitialized(char *name);
void symtab_print();
void initializeSymtab();
bool varInitialized(char *name);

/*Funtion that initializes the Symtable*/
void initializeSymtab()
{
  Node l =  hashTable[temp1_position-1];
  l = (Node) malloc(sizeof(struct HashRec));

  //Used to recover from function calls
  strcpy(l->st_name, "0funct_line");
  l->st_address = temp1_position-1;
  l->st_type = 0;
  l->st_depth = 0;
  l->st_initialized=0; 
  l->next = hashTable[temp1_position];
  hashTable[temp1_position-1] = l;

  l =  hashTable[temp1_position];
  l = (Node) malloc(sizeof(struct HashRec));

  //Temporal variable 1
  strcpy(l->st_name, "0temp1");
  l->st_address = temp1_position;
  l->st_type = 0;
  l->st_depth = 0;
  l->st_initialized=0; 
  l->next = hashTable[temp2_position];
  hashTable[temp1_position] = l;

  l =  hashTable[temp2_position];
  l = (Node) malloc(sizeof(struct HashRec));

  //Temporal variable 1
  strcpy(l->st_name, "0temp2");
  l->st_address = temp2_position;
  l->st_type = 0;
  l->st_depth = 0;
  l->st_initialized=0; 
  l->next = NULL;
  hashTable[temp2_position] = l;
}

/* the hash function (Also considers the depth of the key inserted)*/
static int hash ( char * key, int depth )
{ 
  /*int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { 
    temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;*/
  if(strcmp(key,"0funct_line") == 0)
    return temp1_position-1;  
  if(strcmp(key,"0temp1") == 0)
    return temp1_position;  
  if(strcmp(key,"0temp2") == 0)
    return temp2_position;  

  int temp = 0;
  Node l =  hashTable[temp];
  while ((l != NULL) && ((strcmp(key,l->st_name) != 0) || (l->st_depth != depth))) //not last node, name is not the searched one and depth is not the searched one)
  {
      l = l->next;
      temp++;
  }

  return temp;
}

/* Used to obtain the previous node to key */
int hashPrevious ( char * key, int depth )
{ 
  /* Temporal variables should not be seen by the outside*/
  if(strcmp(key,"0funct_line") == 0)
  {
    printf("Error: reserved variable");
    return -1;  
  }
  if(strcmp(key,"0temp1") == 0)
  {
    printf("Error: Temporal variable");
    return -1;  
  }
  if(strcmp(key,"0temp2") == 0) 
  {
    printf("Error: Temporal variable");
    return -1; 
  } 

  int temp = 0;
  Node l =  hashTable[temp];
  Node aux = l;
  while ((l != NULL) && ((strcmp(key,l->st_name) != 0) || (l->st_depth != depth))) //not last node, name is not the searched one and depth is not the searched one
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

/* the hash function: It looks for variable key on the last possible depth */
int hashLastDepth ( char * key )
{ 
  if(strcmp(key,"0funct_line") == 0)
    return temp1_position-1;  
  if(strcmp(key,"0temp1") == 0)
    return temp1_position;  
  if(strcmp(key,"0temp2") == 0)
    return temp2_position;  

  int temp = 0, depth = -1;
  Node l =  NULL;
  Node aux = hashTable[temp];

  while ( aux != NULL ) //There are elements on the list
  {
      if( (strcmp(key,aux->st_name) == 0) && aux->st_depth > depth ) //Name = searched name and depth is deeper than last recorded
      {
          l = aux;
          depth = aux->st_depth;
      }
      aux = aux->next;
      temp++;
  }

  if( l != NULL )
    return l->st_address;
  else
    return temp;
}

/* the hash function to insert variables */
int hashForInsert ( char * key, int depth )
{ 
  if(strcmp(key,"0funct_line") == 0)
    return temp1_position-1;  
  if(strcmp(key,"0temp1") == 0)
    return temp1_position;  
  if(strcmp(key,"0temp2") == 0)
    return temp2_position;  

  int temp = 0;
  Node l =  hashTable[temp];
  while ((l != NULL) && ((strcmp(key,l->st_name) != 0) || (l->st_depth != depth))) //not last node, name is not the searched one and depth is not the searched one
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
void insert( char * name, int type, int depth )
{ 
  int h = hashForInsert(name, depth);
printf("%s Inserting variable\n", name);     
  Node l =  hashTable[h];
  
  if (l == NULL && h < temp1_position-1) /* variable not yet in table and there is space on the table */
  { 
    l = (Node) malloc(sizeof(struct HashRec));
    strcpy(l->st_name, name);  
    /* ADDED */
    l->st_type = type;
    l->st_depth = depth;
    l->st_initialized = 0; 
    l->st_address = h;
    hashTable[h] = l; 

    if( h > 0 ) //It is not the first insertion 
    { 
      l->next = hashTable[h-1]->next;
      hashTable[h-1]->next = l; 
      hashTable[h] = l;
    }   

    //printf("Var inserted. \n");
  }
  else /* found in table, so just add line number */
  { 
    printf("Var '%s' already exists or the table is full.\n", name);
  }
} 

/* Delete a node returns the next node to the deleted one */
Node delete( char * name, int depth )
{  
  int h = hash(name, depth);
  Node l =  hashTable[h];

  if (l == NULL && h < temp1_position-1) /* variable is not in table, avoids deleting temporals */
  { 
    printf("Error: Var not found.\n");    
  }
  else
  {
    int hP = hashPrevious(name, depth);
    if(hP != -1) //It is not the first node on the list
    {
        if( l->next != NULL ) //There is a node after (move next node to this position to erease this one)
        {
          int previousNode = hashPrevious(name, depth);
          Node aux = l->next;     //Next node

          l->next = aux->next;        //Point to next of next
          hashTable[aux->st_address] = NULL;
          l = aux;                    //Copy next node to this position
          l->st_address = h;
          hashTable[h] = l;      

          hashTable[previousNode]->next = hashTable[h]; //Last node points to this one

          return l;
          //free(l);  //Delete node (erease from memory)
        }
        else
        {
          hashTable[hP]->next = NULL;     //Node before points to end
          hashTable[h] = NULL;            //This node is released
          return NULL;

          //free(l);  //Delete node (erease from memory)
        }
    }
    else
    {
        //Puts the next node on the position 0
        int nextAddress = l->next->st_address;

        l = l->next;
        l->st_address = 0;
        hashTable[0] = l;
        hashTable[nextAddress] = NULL; //RELEASE MEMORY?
        return l;

        //free(l);  //Delete node (erease from memory)     
    } 
  }
}

void deleteByDepth(int depth)
{
  Node l =  hashTable[0];
  while ( l != NULL )
  {
      while( l != NULL && l->st_depth == depth )  //Delete this var
      {
        l = delete( l->st_name, depth );
      }
      if( l != NULL )
        l = l->next;
  }
}

/* return address of symbol if found or -1 if not found  BY NAME*/
int lookup( char * name  )
{ 
  int h = hashLastDepth(name);
  Node l =  hashTable[h];

  if (l == NULL){ 
    //printf("Var not found.\n");
     return -1;
   }
  else{ 
   // printf("Var found in %d.\n", l->st_address);
    return l->st_address;
  }
    //printf("No variables on the table.\n");
    return -1;
}

/* return address of symbol if found or -1 if not found  BY ADDRESS*/
int lookupAddress ( int address )
{ 
  if( address >= SIZE )
     return -1;

  Node l =  hashTable[address];
  if (l == NULL ){ 
    //printf("Var not found.\n");
     return -1;
   }
  else{ 
    //printf("Var found in %d.\n", l->st_address);
    return l->st_address;
  }
    //printf("No variabless on the table.\n");
  return -1;
}

int setValueByName( char * name, int value )
{ 
  int h = hashLastDepth(name);
  Node l =  hashTable[h];

  if (l == NULL){ 
    //printf("Var not found.\n");
     return -1;
   }
  else{ 
    //printf("Var found in %d.\n", l->st_address);
    l->st_value = value;
    l->st_initialized = 1;
     return 0;
  }
   // printf("No variabless on the table.\n");
  return -1;
}

int getValueByName( char * name )
{ 
  int h = hashLastDepth(name);
  Node l =  hashTable[h];

  if (l == NULL){ 
    //printf("Var not found.\n");
     return -1;
   }
  else{ 
    //printf("Var found in %d.\n", l->st_address);
    return l->st_value;
  }
    //printf("No variabless on the table.\n");
}

/* return type value of symbol or -1 if symbol not found */
int lookupType( char * name )
{
  int h = hashLastDepth(name);
  Node l =  hashTable[h];

  if (l == NULL) {
   // printf("Variable not found.\n");
    return -1;
  }
  else {
   // printf("The variable type is: %d.\n", l->st_type);
    return l->st_type;
  }
}

/* return 0 or 1 if the value is initialized */
int getInitialized( char * name )
{
  int h = hashLastDepth(name);
  Node l =  hashTable[h];

  if (l == NULL) {
   // printf("Variable not found.\n");
    return -1;
  }
  else {
   // printf("The variable type is: %d.\n", l->st_type);
    return l->st_initialized;
  }
}

/* return the address of a variable Name with Depth, if error returns -1 */
int lookupDepth( char * name, int depth )
{
  int h = hash(name, depth);
  Node l =  hashTable[h];

  if (l == NULL) {
   // printf("Variable not found.\n");
    return -1;
  }
  else {
   // printf("The variable type is: %d.\n", l->st_type);
    return l->st_address;
  }
}

/* return name of symbol or -1 if symbol not found */
char* lookupName( int address )
{
  if( address >= SIZE )
     return "NULL";

  Node l =  hashTable[address];

  if (l == NULL ) {
   // printf("Variable not found.\n");
    return "NULL";
  }
  else {
   //printf("The variable name is: %s.\n", l->st_name);
    return l->st_name;
  }
}


bool varInitialized( char *name ) //Returns true if the variable has been initialized
{
  int h = hashLastDepth(name);
  Node l =  hashTable[h];
  if ( l == NULL ) {
   // printf("Variable not found.\n");
    return false;
  }
  else {
    if( l->st_initialized )
      return true;
  }
  return false;
}

/* print to stdout by default */ 
void symtab_print(FILE * of) {  
  int i;
  fprintf(of,"\n                        Symbol Table                               \n");
  fprintf(of,"\n----------  ------   ----------  ---------  -------  ------------- \n");
  fprintf(of,"Name         Type     Position     Value     Depth    Initialized\n");
  fprintf(of,"----------  ------   ----------  ---------  -------  -------------\n");

  Node l = hashTable[0];
  while (l != NULL)
  { 
    fprintf(of,"%-13s %-10i %-10i %-10i %-10i %-10i\n",l->st_name, l->st_type, l->st_address, l->st_value, l->st_depth, l->st_initialized);
    l = l->next;
  }

  /* Print temporal variables */
  l = hashTable[temp1_position-1];
  fprintf(of,"%-13s %-10i %-10i %-10i %-10i %-10i\n",l->st_name, l->st_type, l->st_address, l->st_value, l->st_depth, l->st_initialized);
  l = hashTable[temp1_position];
  fprintf(of,"%-13s %-10i %-10i %-10i %-10i %-10i\n",l->st_name, l->st_type, l->st_address, l->st_value, l->st_depth, l->st_initialized);
  l = hashTable[temp2_position];
  fprintf(of,"%-13s %-10i %-10i %-10i %-10i %-10i\n",l->st_name, l->st_type, l->st_address, l->st_value, l->st_depth, l->st_initialized);
} 