#ifndef __GLOBAL_H__
#define __GLOBAL_H__


/*******************  INCLUDES  ***********************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/********************* Integer KeyType and related macros*****************/
typedef int KeyType;

#define EQ(a, b) ((a)==(b))
#define LT(a, b) ((a)<(b))
#define LE(a, b) ((a)<=(b))
#define GT(a, b) ((a)>(b))
#define GE(a, b) ((a)>=(b))

/********************* String KeyType and related macros*****************/
/*
#define EQ(a, b) (!strcmp((a), (b)))
#define LT(a, b) (strcmp((a), (b))<0)
#define LE(a, b) (strcmp((a), (b))<=0)
#define GT(a, b) (strcmp((a), (b))>0)
#define GE(a, b) (strcmp((a), (b))>=0)
*/

/****************************************************************/

typedef struct elementtype {
	unsigned char id;
	signed short data;
}ElementType;

#define MAXELEMENTS 100

typedef ElementType QueueEntry;
#define MAXQUEUE MAXELEMENTS


typedef ElementType StackEntry;
#define MAXSTACK MAXELEMENTS

typedef ElementType ListEntry;
#define MAXLIST MAXELEMENTS

typedef ElementType TreeEntry;


typedef ElementType GraphEntry;
#define MAXVERTEX 6











#endif // __GLOBAL_H__