#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

/**
 * _printf - Function that mimic the original printf function
 * but on a smaller scale
 * @format: Format Specifier like %c , %d, etc..
 * Return: Number of bytes that it took
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, j = 0;
	char buff[100] = {0}, tmp[20];
	char *str_arg;

	va_start(ap, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				/* Convert char */
				case 'c': {
						buff[j] = (char)va_arg(ap, int);
						j++;
						break;
				}
				/* Convert decimal */
				case 'd': {
						_itoa(va_arg(ap, int), tmp, 10);
						strcpy(&buff[j], tmp);
						j += strlen(tmp);
						break;
				}
				case 's': {
						str_arg = va_arg(ap, char*);
						strcpy(&buff[j], str_arg);
						j += strlen(str_arg);
						break;
				}
			}
		}
		else
		{
			buff[j] = format[i];
			j++;
		}
		i++;
	}
	fwrite(buff, j, 1, stdout);
	va_end(ap);
	return (j);
}
