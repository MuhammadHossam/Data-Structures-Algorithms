#include "Queues.h"





#ifdef LINKED_QUEUE

/*********************************************************************************/
/****************************** Linked-based implementation***********************/
/*********************************************************************************/

/* Append : push an item onto the queue
   Pre: The queue exists and it is not full.
   Post: The argument item has been stored at the top of the queue. */
void Append(QueueEntry item, Queue *pq)
{
	QueueNode* pn = (QueueNode*)malloc(sizeof(QueueNode));
	pn->entry = item;
	pn->next = NULL;

	if (!(pq->rear))
	{
		/*
			The Queue is empty (first append)
		*/
		pq->front = pn;
	}
	else
	{
		(pq->rear)->next = pn;
	}
	pq->Queue_size++;
	pq->rear = pn;
}

/* Serve: Serve an item from the queue.
   Pre: The queue exists and it is not empty.
   Post: The item at the top of the queue has been removed and returned
		 in *item  */
void Serve(QueueEntry *item, Queue *pq)
{
	QueueNode* pn = pq->front;
	*item = pn->entry;
	if (!(pn->next))
	{
		/*
			Means that there is only one element in the queue
		*/
		pq->rear = NULL;
	}
	pq->front = pq->front->next;
	free(pn);
	pq->Queue_size--;
}

/* QueueEmpty: returns non-zero if the Queue is empty
   Pre: The Queue exists and it has been initialized.
   Post: Return non-zero if the queue is empty; zero, otherwise.
*/
int QueueEmpty(Queue *pq)
{
	return !(pq->front);
}

/* QueueFull: returns non-zero if the Queue is full.
   Pre: The Queue exists and it has been initialized.
   Post: Return non-zero if the Queue is full; return zero, otherwise.
 */
int QueueFull(Queue *pq)
{
	return pq->Queue_size == MAXQUEUE;
}

/* CreateQueue: initialize the Queue to be empty.
   Pre: None.
   Post: The queue has been initialized to be empty.
*/
void CreateQueue(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
	pq->Queue_size = 0;
}

/*
Pre:   The Queue has been created and is not empty.
Post: The variable item is a copy of the front entry; the queue remains
	  unchanged.
*/
void QueueFront(QueueEntry *item, Queue *pq)
{
	*item = pq->front->entry;
}

/*
Pre:  The Queue has been created.
Post: The function returns the number of entries in queue.
*/
int QueueSize(Queue *pq)
{
	return pq->Queue_size;
}

/*
Pre:  The queue has been created.
Post: queue becoems empty
*/
void ClearQueue(Queue *pq)
{
	while (pq->front)
	{
		pq->rear = pq->front->next;
		free(pq->front);
		pq->front = pq->rear;
	}
	pq->Queue_size = 0;
}

/*
Pre:   The Queue has been created.
Post:  Visit Each element in the Queue from the front to the rear.
*/
void TraverseQueue(Queue *pq, void(*pvisit)(QueueEntry))
{
	for (QueueNode* pn = pq->front; pn; pn = pn->next)
	{
		(*pvisit)(pn->entry);
	}
}





#else
/*********************************************************************************/
/****************************** Array-based implementation************************/
/*********************************************************************************/

/* Append : push an item onto the queue
   Pre: The queue exists and it is not full.
   Post: The argument item has been stored at the top of the queue. */
void Append(QueueEntry item, Queue *pq) {
	/*
		This condition is valid only when the user checks that the queue isn't Full
		So when the rear points to the MAXQUEUE-1 and the queue isn't full so the next 
		entry should be appended at the first index of the queue (Circular Queue).
	*/
	if (pq->rear == MAXQUEUE - 1)
	{
		pq->rear = 0;
	}
	else
	{
		pq->rear++;
	}
	pq->entry[pq->rear] = item;
	pq->queue_size++;
	
}


/* Serve: Serve an item from the queue.
   Pre: The queue exists and it is not empty.
   Post: The item at the top of the queue has been removed and returned
		 in *item  */
void Serve(QueueEntry *item, Queue *pq) {
	*item = pq->entry[pq->front];
	/*
		The user should check before that the queue isn't empty 
	*/
	if (pq->front == MAXQUEUE - 1)
	{
		pq->front = 0;
	}
	else
	{
		pq->front++;
	}
	pq->queue_size--;
}

/* QueueEmpty: returns non-zero if the Queue is empty
   Pre: The Queue exists and it has been initialized.
   Post: Return non-zero if the queue is empty; zero, otherwise.
*/
int QueueEmpty(Queue *pq) {
	return pq->queue_size == 0;
}

/* QueueFull: returns non-zero if the Queue is full.
   Pre: The Queue exists and it has been initialized.
   Post: Return non-zero if the Queue is full; return zero, otherwise.
 */
int QueueFull(Queue *pq) {
	return pq->queue_size == MAXQUEUE;
}

/* CreateQueue: initialize the Queue to be empty.
   Pre: None.
   Post: The queue has been initialized to be empty.
*/
void CreateQueue(Queue *pq) {
	pq->front = 0;
	pq->rear = -1;
	pq->queue_size = 0;
}

/*
Pre:   The Queue has been created and is not empty.
Post: The variable item is a copy of the front entry; the queue remains
	  unchanged.
*/
void QueueFront(QueueEntry *item, Queue *pq) {
	*item = pq->entry[pq->front];   
}


/*
Pre:  The Queue has been created.
Post: The function returns the number of entries in queue.
*/
int QueueSize(Queue *pq) {
	return pq->queue_size;
}

/*
Pre:  The queue has been created.
Post: queue becoems empty
*/
void ClearQueue(Queue *pq) {
	pq->queue_size = 0;
	pq->front = 0;
	pq->rear = -1;
}


/*
Pre:   The Queue has been created.
Post:  Visit Each element in the Queue from the front to the rear.
*/
void TraverseQueue(Queue *pq, void(*pvisit)(QueueEntry)) {
	unsigned char pos, s;
	for (pos = pq->front, s = 0; s < pq->queue_size; s++)
	{
		(*pvisit)(pq->entry[pos]);
		if (pos == MAXQUEUE - 1)
		{
			pos = 0;
		}
		else
		{
			pos++;
		}
	}	
}


#endif