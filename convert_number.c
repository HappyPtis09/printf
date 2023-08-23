#include "main.h"

/**
 * print_hex - prints unsigned hex in lower
 * @list: pointer
 * @params: the parameters struct
 *
 * Return: bytes to be printed
 */
int print_hex(va_list list, params_t *params)
{
	unsigned long l;
	int x = 0;
	char *string;

	if (params->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);

	string = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--string = 'x';
		*--string = '0';
	}
	params->unsign = 1;
	return (x += print_number(string, params));
}

/**
 * print_HEX - prints unsigned hex in upper
 *
 * @list: pointer
 *
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_HEX(va_list list, params_t *params)
{
	unsigned long l;
	int x = 0;
	char *string;

	if (params->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);

	string = convert(l, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--string = 'X';
		*--string = '0';
	}
	params->unsign = 1;
	return (x += print_number(string, params));
}
/**
 * print_binary - print unsigned binary number
 *
 * @list: pointer
 *
 * @params: the parameters struct
 *
 * Return: bytes to be printed
 */
int print_binary(va_list list, params_t *params)
{
	unsigned int n = va_arg(list, unsigned int);
	char *string = convert(n, 2, CONVERT_UNSIGNED, params);
	int x = 0;

	if (params->hashtag_flag && n)
		*--string = '0';
	params->unsign = 1;
	return (x += print_number(string, params));
}

/**
 * print_octal - prints unsigned octal numbers
 * @list: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_octal(va_list list, params_t *params)
{
	unsigned long l;
	char *string;
	int x = 0;

	if (params->l_modifier)
		l = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		l = (unsigned short int)va_arg(list, unsigned int);
	else
		l = (unsigned int)va_arg(list, unsigned int);
	string = convert(l, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_flag && l)
		*--string = '0';
	params->unsign = 1;
	return (x += print_number(string, params));
}
