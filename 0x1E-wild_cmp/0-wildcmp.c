#include "holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * wildcmp - Compares if two strings are the same, including the
 * asterisk wildcard
 * @s1: String 1
 * @s2: String 2
 *
 * Return: 1 if they're equal otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0')
	{
		if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		return (*s2 == '\0');
	}

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	if (*s2 == '*')
		return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));

	return (0);
}