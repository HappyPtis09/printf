#include "main.h"

/**
 * _puts - prints string
 *
 * @string: the string to print
 *
 * Return: Nothing
 */
int _puts(char *string)
{
	char *c = string;

	while (*string)
	{
		_putchar(*string++);
	}
	return (string - c);
}

/**
 * _putchar - writes the character
 *
 * @c: The character to print
 *
 * Return: 1; if error, -1
 */
int _putchar(int c)
{
	static int j;
	static char buf[BUFFERSIZE];

	if (c == BUFFFLUSH || j >= BUFFERSIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != BUFFFLUSH)
	{
		buf[j++] = c;
	}
	return (1);
}
