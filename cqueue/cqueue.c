/* 
 * An implementation of a dynamically-sized FIFO queue
 * in C89 using linked lists.
 * Functions included: enq(a), deq().
 * Update type accordingly as needed.
 * Copyright (C) 2021, Ashlee Tan. Licensed as attached.
 */

#define   TYPE   int

/* Function prototypes */
int  enq(TYPE);
TYPE deq(void);

typedef struct elem {
	TYPE content;
	struct elem *next;
} ELEM;

ELEM *pq;  /* pointer to first element in queue */

/*
 * Enqueues item a. Create a new queue if it doesn't exist.
 * Returns 0 upon success, else return 1 for failure.
 */
int
enq(TYPE a)
{}

/*
 * Dequeues first element from queue.
 * If exists, returns content in first element.
 * Else if doesn't exist, return 0.
 */
TYPE
deq(void)
{}
/* TODO */
