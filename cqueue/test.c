/*
 * Test driver for cqueue (C89)
 * Copyright (C) 2021, Ashlee Tan. Licensed as attached.
 */

#include <stdio.h>
#include <string.h>
#include "cqueue.c"

int
main(void)
{
	int  n;      /* value to be enqueued */
	char *temp;  /* temporary input holding */

	temp = malloc(sizeof(char) * 30); /* input buffer, size 30 */
	printf("(Type ? for help)\n");
	while (1) {
		temp[0] = '\0';
		printf("command: ");
		fgets(temp, 29, stdin);
		temp[strcspn(temp, "\n")] = '\0'; /* removes trailing '\n' */
		
		switch (temp[0]) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			n = atoi(temp);
			printf("enqueueing %d\n", n);
			if (enq(n))
				printf("error enqueueing %d\n", n);
			n = 0;   /* reset for next round */
			break;
		case 'q':
			printf("exiting\n");
			goto exit;
		case 'd':  /* dequeue */
			printf("dequeued %d\n", deq());
			break;
		case '?':
			printf("Enter a number to enqueue, "
			       "or enter a command.\n");
			printf("Valid commands:\n"
			       "\tq - quit the program\n"
			       "\td - dequeue first element\n");
			break;
		default:
			printf("invalid action %s\n", temp);
			break;
		}
	}
exit:
	return(0);
}
