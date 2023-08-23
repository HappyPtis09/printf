#include "main.h"

/**
 * get_specifier - finds the format func
 *
 * @sp: string format
 *
 * Return: the number of bytes printed
 */
int (*get_specifier(char *sp))(va_list list, params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*sp == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_print_func - finds the format function
 *
 * @sp: the format string
 *
 * @list: argument pointer
 *
 * @params: the parameters struct
 *
 * Return: the number of bytes
 */
int get_print_func(char *sp, va_list list, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(sp);

	if (f)
	{
		return (f(list, params));
	}
	return (0);
}

/**
 * get_flag - finds the flag function
 *
 * @sp: the format string
 *
 * @params: the parameters struct
 *
 * Return: int
 */
int get_flag(char *sp, params_t *params)
{
	int i = 0;

	switch (*sp)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - finds the modifier func
 *
 * @sp: the format string
 *
 * @params: the parameter
 *
 * Return: int
 */
int get_modifier(char *sp, params_t *params)
{
	int i = 0;

	switch (*sp)
	{
	case 'h':
		i = params->h_modifier = 1;
		break;
	case 'l':
		i = params->l_modifier = 1;
		break;
	}
	return (i);
}

/**
 * get_width - gets the width
 *
 * @sp: the format string
 *
 * @params: the parameters struct
 *
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *sp, params_t *params, va_list list)
{
	int d = 0;

	if (*sp == '*')
	{
		d = va_arg(list, int);
		sp++;
	}
	else
	{
		while (_isdigit(*sp))
			d = d * 10 + (*sp++ - '0');
	}
	params->width = d;
	return (sp);
}
