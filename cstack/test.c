/*
 * Test driver for cstack (K&R).
 * Copyright (C) 2021, Ashlee Tan. Licensed as attached.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cstack.c"

main()
{
	int  n;      /* value to be pushed */
	int  count;
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
			printf("pushing %d\n", n);
			if (push(n))
				printf("error pushing %d\n", n);
			n = 0;   /* reset for next round */
			break;
		case 'q':
			printf("exiting\n");
			exit(0);
		case 'p':  /* pop */
			printf("popped %d\n", pop());
			break;
		case '?':
			printf("Enter a number to push it to the stack, "
			       "or enter a command.\n");
			printf("Valid commands:\n"
			       "\tq - quit the program\n"
			       "\tp - pop last value off stack\n");
			break;
		default:
			printf("invalid action %s\n", temp);
			break;
		}
	}
}
