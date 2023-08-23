#include "main.h"

/**
 * print_from_to - prints char addresses
 * @start: starting add
 * @stop: stopping add
 * @except: except add
 *
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int summ = 0;

	while (start <= stop)
	{
		if (start != except)
		{
			summ += _putchar(*start);
		}
		start++;
	}
	return (summ);
}

/**
 * print_rev - prints string in reverse
 *
 * @list: string
 *
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_rev(va_list list, params_t *params)
{
	int length, summ = 0;
	char *string = va_arg(list, char *);
	(void)params;

	if (string)
	{
		for (length = 0; *string; string++)
			length++;
		string--;
		for (; length > 0; length--, string--)
			summ += _putchar(*string);
	}
	return (summ);
}

/**
 * print_rot13 - prints in rot13
 *
 * @list: pointer
 *
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_rot13(va_list list, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(list, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
		    || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
