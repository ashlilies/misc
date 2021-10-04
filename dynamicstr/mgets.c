/*
 * Dynamically allocate memory as required for a string input from stdin.
 * Copyright (C) 2021, Ashlee Tan.
 */

#include <stdio.h>

/* Function prototype */
char *mgets(void);

/*
 * Return pointer to string input from stdin into s.
 * Doesn't check for zero-length strings. Do that yourself.
 * If string input too long, return maximum possible length.
 * Doesn't free memory for you.
 * Null pointer returned signifies memory allocation error.
 */
char *
mgets(void)
{
	int  len, sz;
	char c, *s;
	char *temp;  /* handle realloc() out of memory */

	sz = sizeof(char *);  /* current size of s */
	s = malloc(sz);        /* excluding '\0' */
	if (!s)
		return(NULL);  /* error allocating memory */

	len = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		temp = realloc(s, sz += sizeof(char *));  /* '\0' */
		if (!temp)  /* no space for new character */
			break;
		s = temp;
		s[len++] = c;
	}

	s[len] = '\0';

	return(s);
}
