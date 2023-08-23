#include "main.h"

/**
 * _isdigit - checks if character is digit
 *
 * @c: the char to check
 *
 * Return: 1 if digit, else 0
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - the length of a string
 *
 * @s: the string to check for length
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
	{
		i++;
	}
	return (i);
}

/**
 * print_number - prints a number
 *
 * @string: the number as a string
 *
 * @params: the parameter struct
 *
 * Return: chars printed
 */
int print_number(char *string, params_t *params)
{
	unsigned int a = _strlen(string);
	int neg = (!params->unsign && *string == '-');

	if (!params->precision && *string == '0' && !string[1])
	{
		string = "";
	}
	if (neg)
	{
		string++;
		a--;
	}
	if (params->precision != UINT_MAX)
	{
		while (a++ < params->precision)
		{
			*--string = '0';
		}
	}
	if (neg)
	{
		*--string = '-';
	}

	if (!params->minus_flag)
	{
		return (print_number_right_shift(string, params));
	}
	else
	{
		return (print_number_left_shift(string, params));
	}
}

/**
 * print_number_right_shift - prints a number
 *
 * @string: the base number string
 *
 * @params: the parameter struct
 *
 * Return: char
 */
int print_number_right_shift(char *string, params_t *params)
{
	unsigned int n = 0, n1, n2, i = _strlen(string);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	n1 = n2 = (!params->unsign && *string == '-');
	if (n1 && i < params->width && pad_char == '0' && !params->minus_flag)
		string++;
	else
		n1 = 0;
	if ((params->plus_flag && !n2) ||
		(!params->plus_flag && params->space_flag && !n2))
		i++;
	if (n1 && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !n2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 &&
		!params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n += _putchar(pad_char);
	if (n1 && pad_char == ' ')
		n += _putchar('-');
	if (params->plus_flag && !n2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !n2 &&
		!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(string);
	return (n);
}

/**
 * print_number_left_shift - prints a number
 *
 * @string: the base string
 *
 * @params: the parameter struct
 *
 * Return: char
 */
int print_number_left_shift(char *string, params_t *params)
{
	unsigned int n = 0, n1, n2, i = _strlen(string);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	n1 = n2 = (!params->unsign && *string == '-');
	if (n1 && i < params->width && pad_char == '0' && !params->minus_flag)
		string++;
	else
		n1 = 0;

	if (params->plus_flag && !n2 && !params->unsign)
		n += _putchar('+'), i++;
	else if (params->space_flag && !n2 && !params->unsign)
		n += _putchar(' '), i++;
	n += _puts(string);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
