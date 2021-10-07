/* 
 * An implementation of a dynamically-sized FIFO queue
 * in C89 using linked lists.
 * Functions included: enq(a), deq().
 * Update type accordingly as needed.
 * Copyright (C) 2021, Ashlee Tan. Licensed as attached.
 */

#define   TYPE   int

#include <stdlib.h>

/* Function prototypes */
int  enq(TYPE);
TYPE deq(void);

typedef struct elem {
	TYPE content;
	struct elem *next;
} ELEM;

static ELEM *pq;  /* pointer to first element in queue */

/*
 * Enqueues item a. Create a new queue if it doesn't exist.
 * Returns 0 upon success, else return 1 for failure.
 */
int
enq(TYPE a)
{
	ELEM *newelem;

	/* Construct new element */
	newelem = malloc(sizeof(ELEM));
	if (!newelem)
		return(1);  /* malloc failure */
	newelem->content = a;
	newelem->next = NULL;

	if (!pq)  /* queue not yet exist */
		pq = newelem;
	else {
		ELEM *temp;

		temp = pq;
		while (temp->next) /* advance to end */
			temp = temp->next;
		temp->next = newelem;
	}
	return(0);
}

/*
 * Dequeues first element from queue.
 * If exists, returns content in first element.
 * Else if doesn't exist, return 0.
 */
TYPE
deq(void)
{
	ELEM *temp;
	TYPE val;

	if (!pq)  /* queue is blank */
		return(0);
	temp = pq;
	pq = pq->next;
	val = temp->content;
	free(temp);
	return(val);
}
/* TODO */
