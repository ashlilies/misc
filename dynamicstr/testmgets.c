/*
 * Test mgets(s) function.
 * Copyright (C) 2021, Ashlee Tan.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mgets.c"

int
main(void)
{
	int len;
	char *s;

	s = mgets();
	if (!s) {
		printf("mgets returned null pointer!\n");
		return(EXIT_FAILURE);
	}
	printf("string entered: \"%s\"\n", s);
	printf("length: %ld\n", strlen(s));

	free(s);
	
	return(EXIT_SUCCESS);
}
