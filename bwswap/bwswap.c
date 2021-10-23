/*
 * Swap 2 integers, without the use of a temporary operator.
 */

void
swap(a, b)
	int *a;
	int *b;
{
	*a = *a ^ *b;
	*b = *b ^ *a;
	*a = *a ^ *b;
}
