#include "main.h"

/**
 * print_char - prints character
 * @list: pointer
 *
 * @param: parametr
 *
 * Return: number chars printed
 */
int print_char(va_list list, params_t *param)
{
	char pad_char = ' ';
	unsigned int i = 1, summ = 0, ch = va_arg(list, int);

	if (param->minus_flag)
		summ += _putchar(ch);
	while (i++ < param->width)
		summ += _putchar(pad_char);
	if (!param->minus_flag)
		summ += _putchar(ch);
	return (summ);
}

/**
 * print_int - prints integer
 *
 * @list: argument pointer
 *
 * @param: the parameters
 *
 * Return:chars printed
 */
int print_int(va_list list, params_t *param)
{
	long j;

	if (param->l_modifier)
		j = va_arg(list, long);
	else if (param->h_modifier)
		j = (short int)va_arg(list, int);
	else
		j = (int)va_arg(list, int);
	return (print_number(convert(j, 10, 0, param), param));
}

/**
 * print_string - prints string
 *
 * @list: argument pointer
 *
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list list, params_t *params)
{
	char *string = va_arg(list, char *), pad_char = ' ';
	unsigned int p = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!string))
		case 1:
			string = NULL_STRING;

	j = p = _strlen(string);
	if (params->precision < p)
		j = p = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < p; i++)
				sum += _putchar(*string++);
		else
			sum += _puts(string);
	}
	while (j++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < p; i++)
				sum += _putchar(*string++);
		else
			sum += _puts(string);
	}
	return (sum);
}

/**
 * print_percent - prints string
 *
 * @list: pointer
 *
 * @params: the parameters struct
 *
 * Return: number chars
 */
int print_percent(va_list list, params_t *params)
{
	(void)list;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @list: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list list, params_t *params)
{
	char *str = va_arg(list, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
