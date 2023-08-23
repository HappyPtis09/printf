#include "main.h"

/**
 * convert - converter function
 * @numm: number
 *
 * @base: base
 *
 * @flag: argument flags
 *
 * @params: paramater struct
 *
 * Return: string
 */
char *convert(long int numm, int base, int flag, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *pntr;
	unsigned long n = numm;
	(void)params;

	if (!(flag & CONVERT_UNSIGNED) && numm < 0)
	{
		n = -numm;
		sign = '-';

	}
	array = flag & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pntr = &buffer[49];
	*pntr = '\0';

	do	{
		*--pntr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--pntr = sign;
	return (pntr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @list: pointer
 * @params: the parameters struct
 *
 * Return: bytes to be printed
 */
int print_unsigned(va_list list, params_t *params)
{
	unsigned long len;

	if (params->l_modifier)
		len = (unsigned long)va_arg(list, unsigned long);
	else if (params->h_modifier)
		len = (unsigned short int)va_arg(list, unsigned int);
	else
		len = (unsigned int)va_arg(list, unsigned int);
	params->unsign = 1;
	return (print_number(convert(len, 10, CONVERT_UNSIGNED, params), params));
}



/**
 * print_address - prints address
 *
 * @list: pointer
 *
 * @params: the parameters struct
 *
 * Return: bytes to be printed
 */
int print_address(va_list list, params_t *params)
{
	unsigned long int n = va_arg(list, unsigned long int);
	char *string;

	if (!n)
		return (_puts("(nil)"));

	string = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--string = 'x';
	*--string = '0';
	return (print_number(string, params));
}
