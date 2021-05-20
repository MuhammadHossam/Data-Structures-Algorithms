#ifndef __STACK_H__
#define __STACK_H__

/*******************  INCLUDES  ***********************/
#include "Global.h"

/*Linked vs. Array based implementation
*/

//#define ARRAY_STACK
#define LINKED_STACK

/**********************************************************/

#ifdef LINKED_STACK

/*********************************************************************************/
/****************************** Linked implementation*****************************/
/*********************************************************************************/

typedef struct stacknode {
	StackEntry entry;
	struct stacknode *next;
}StackNode;

typedef struct stack {
	StackNode *top;
	unsigned char Stack_size; 
}Stack;

#else

/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

typedef struct stack {
	int top;
	StackEntry entry[MAXSTACK];
} Stack;

#endif

/*********************************************************************************/
/***************************Function Prototypes***********************************/
/*********************************************************************************/


void	Push(StackEntry, Stack *);
void	Pop(StackEntry *, Stack *);
int		StackEmpty(Stack *);
int		StackFull(Stack *);
void	CreateStack(Stack *);
void	StackTop(StackEntry *, Stack *);
int		StackSize(Stack *);
void	ClearStack(Stack *);
void	TraverseStack(Stack *, void(*pvisit)(StackEntry));








#endif // __STACK_H__