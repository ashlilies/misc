/*
 * Tester for bwswap.c
 */

#include <stdio.h>
#include "bwswap.c"

main()
{
	int a, b;

	printf("Enter a: ");
	scanf("%d", &a);
	printf("Enter b: ");
	scanf("%d", &b);

	printf("a: %d, b: %d\n", a, b);
	swap(&a, &b);
	printf("a: %d, b: %d\n", a, b);
}
