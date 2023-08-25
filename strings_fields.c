#include "main.h"

/**
 * get_precision - gets the precision from the format string
 *
 * @f: the format string
 *
 * @params: the parameters struct
 *
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_precision(char *f, params_t *params, va_list list)
{
	int i = 0;

	if (*f != '.')
	{
		return (f);
	}

	f++;

	if (*f == '*')
	{
		i = va_arg(list, int);
		f++;
	}
	else if (_isdigit(*f))
	{
		while (_isdigit(*f))
		{
			i = i * 10 + (*f++ - '0');
		}
	}

	params->precision = i;

	return (f);
}
