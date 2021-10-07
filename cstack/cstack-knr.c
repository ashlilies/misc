/* 
 * An implementation of a dynamic LIFO stack in K&R C.
 * Functions included: push(a), pop().
 * Set type accordingly.
 * Copyright (C) 2021, Ashlee Tan. Licensed as attached.
 */

#define   TYPE   int   /* type of elem inside the stack */

#include <stdlib.h>    /* used by malloc() and friends */

static TYPE *stack;    /* pointer to first element in stack */
static int  pos;       /* next avail position of top of stack; indexed */
static int  ssz;       /* current size of stack */

push(a)  /* return 0 on success, 1 on failure */
	TYPE a;
{
	TYPE *temp;  /* checking realloc failures */

	if (!ssz) { /* not yet initialized; first call */
		ssz = sizeof(TYPE);
		stack = (TYPE *) malloc(ssz);
		if (!stack) {
			ssz = 0;    /* undo */
			return(1);  /* not enough memory */
		}
	}

	if ((pos+1) * sizeof(TYPE) > ssz) { /* need more space */
		temp = (TYPE *) realloc(stack, ssz += sizeof(TYPE));
		if (!temp) {
			ssz -= sizeof(TYPE);  /* undo */
			return(1);  /* not enough memory */
		}
		stack = temp;
	}

	stack[pos++] = a;
	return(0);
}

TYPE
pop()  /* returns popped value or 0 if not found/error */
{
	TYPE val;
	TYPE *temp;  /* realloc error checking */

	if (!ssz)  /* stack doesn't exist yet */
		return(0);

	if (ssz && pos-1 < 0) {  /* the stack is now empty, but exists */
		stack[0] = 0;    /* and tried to pop last element */
		return(0);
	}

	val = stack[--pos];  /* get last stored val off stack */
	if (ssz-sizeof(TYPE) >= sizeof(TYPE)) { /* make stack smaller */
		temp = (TYPE *) realloc(stack, ssz -= sizeof(TYPE));
		if (!temp) { /* an error occured */
			ssz += sizeof(TYPE); /* undo */
			return(0);
		}
	}

	return(val);
}
