#ifndef __QUEUES_H__
#define __QUEUES_H__


/*******************  INCLUDES  ***********************/
#include "Global.h"

/*Linked vs. Array based implementation
*/

#define LINKED_QUEUE
//#define ARRAY_QUEUE

/**********************************************************/

#ifdef LINKED_QUEUE

/*********************************************************************************/
/****************************** Linked implementation*****************************/
/*********************************************************************************/

typedef struct queuenode {
	QueueEntry entry;
	struct queuenode *next;
}QueueNode;

typedef struct queue {
	QueueNode *front;
	QueueNode *rear;
	unsigned char Queue_size;
}Queue;

#else

/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

typedef struct queue {
	unsigned char front;
	unsigned char rear;
	unsigned char queue_size;
	QueueEntry entry[MAXQUEUE];
} Queue;

#endif

/*********************************************************************************/
/***************************Function Prototypes***********************************/
/*********************************************************************************/


/* Append : push an item onto the queue
   Pre: The queue exists and it is not full.
   Post: The argument item has been stored at the top of the queue. */
void Append(QueueEntry item, Queue *pq);

/* Serve: Serve an item from the queue.
   Pre: The queue exists and it is not empty.
   Post: The item at the top of the queue has been removed and returned
		 in *item  */
void Serve(QueueEntry *item, Queue *pq);

/* QueueEmpty: returns non-zero if the Queue is empty
   Pre: The Queue exists and it has been initialized.
   Post: Return non-zero if the queue is empty; zero, otherwise.
*/
int QueueEmpty(Queue *pq);

/* QueueFull: returns non-zero if the Queue is full.
   Pre: The Queue exists and it has been initialized.
   Post: Return non-zero if the Queue is full; return zero, otherwise.
 */
int QueueFull(Queue *pq);

/* CreateQueue: initialize the Queue to be empty.
   Pre: None.
   Post: The queue has been initialized to be empty.
*/
void CreateQueue(Queue *pq);

/*
Pre:   The Queue has been created and is not empty.
Post: The variable item is a copy of the front entry; the queue remains
	  unchanged.
*/
void QueueFront(QueueEntry *item, Queue *pq);

/*
Pre:  The Queue has been created.
Post: The function returns the number of entries in queue.
*/
int QueueSize(Queue *pq);

/*
Pre:  The queue has been created.
Post: queue becoems empty
*/
void ClearQueue(Queue *pq);

/*
Pre:   The Queue has been created.
Post:  Visit Each element in the Queue from the front to the rear.
*/
void TraverseQueue(Queue *pq, void(*pvisit)(QueueEntry));





#endif // __QUEUES_H__











 