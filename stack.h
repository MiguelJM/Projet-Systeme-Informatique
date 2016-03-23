/*
 * C program to implement stack. Stack is a LIFO data structure.
 * Stack operations: PUSH(insert operation), POP(Delete operation)
 * and Display stack.
 */
#include <stdio.h>
#define MAXSIZE 32
 
struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
 
STACK push(int, STACK);
STACK  pop(STACK);
void display(STACK);
 
/*  Function to add an element to the stack */
STACK push ( int pushed_Element, STACK s )
{
    int num;
    if (s.top == (MAXSIZE - 1))
    {
        printf ("Stack is Full\n");
        return s;
    }
    else
    {
        s.top = s.top + 1;
        s.stk[s.top] = pushed_Element;
    }
    return s;
}
/*  Function to delete an element from the stack */
STACK pop (STACK s)
{
    int num;
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
        return (s);
    }
    else
    {
        //num = s.stk[s.top];
        s.top = s.top - 1;
    }
    return(s);
}
/*  Function to display the status of the stack */
void display (STACK s)
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%d\n", s.stk[i]);
        }
    }
    printf ("\n");
}