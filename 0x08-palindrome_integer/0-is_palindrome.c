#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Checks wheter or not a given unsigned
 * integer is a palindrome
 * @n: Number to be checked
 * Return: return 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
	unsigned long revN, remainder, orgN;

	revN = 0;
	orgN = n;

	while (n != 0)
	{
		remainder = n % 10;
		revN = revN * 10 + remainder;
		n /= 10;
	}
	if (orgN == revN)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
