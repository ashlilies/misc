/* 
 * An implementation of a dynamically-sized FIFO queue
 * in C89 using linked lists.
 * Update type accordingly as needed.
 * Copyright (C) 2021, Ashlee Tan. Licensed as attached.
 */

#define   TYPE   int

typedef struct elem {
	TYPE content;
	struct elem *next;
} ELEM;

ELEM *pq;  /* pointer to first element in queue */

/* TODO */
