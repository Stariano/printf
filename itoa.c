#include "main.h"
#include <stdio.h>
/**
 * _itoa - Function that takes an integer and convert it to a string
 * @i: is the integer needed to be converted.
 * @strout: the converted string.
 * @base: on what base the int should be divided with.
 * Return: The String
 */

char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}

	if (sign)
	{
		*str++ = '-';
	}
	*str = '\0';
	_strrev(strout);

	return (strout);
}
