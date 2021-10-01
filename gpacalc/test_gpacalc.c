#include <stdio.h>
#include "gpacalc.c"

/* Test the function, numgrade(s) */
int
main(void)
{
	float ngrade;
	char s[100];

	printf("Enter alphabetical grade: ");
	scanf("%s", s);
	ngrade = numgrade(s);
	if ((int) ngrade == -1)  /* type conversion needed for float */
		printf("Invalid grade entered!\n");
	else
		printf("Numerical grade = %.1f\n", ngrade);
}
