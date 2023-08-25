#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>

#define BUFFERSIZE 1024
#define BUFFFLUSH -1


#define NULLSTRING "(null)"

#define PARAMSINIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_TO_LOWER	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag
 *
 * @plus_flag: plus_flag specified
 *
 * @space_flag: hashtag_flag specified
 *
 * @hashtag_flag: _flag specified
 *
 * @zero_flag:  _flag specified
 *
 * @minus_flag:  _flag specified
 *
 * @width: width specified
 *
 * @precision: precision specified
 *
 * @h_modifier: h_modifier is specified
 *
 * @l_modifier: l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign		: 1;
	unsigned int zero_flag		: 1;
	unsigned int plus_flag		: 1;
	unsigned int minus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;

	unsigned int precision;
	unsigned int width;

	unsigned int l_modifier		: 1;
	unsigned int h_modifier		: 1;

} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format
 *
 * @f: function
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);

} specifier_t;

/* _put.c */

int _puts(char *string);
int _putchar(int c);

/* print_functions.c */

int print_char(va_list list, params_t *param);
int print_int(va_list list, params_t *param);
int print_string(va_list list, params_t *params);
int print_percent(va_list list, params_t *params);
int print_S(va_list list, params_t *params);

/* number.c */

char *convert(long int numm, int base, int flag, params_t *params);
int print_unsigned(va_list list, params_t *params);
int print_address(va_list list, params_t *params);

/* specifier.c */

int (*get_specifier(char *sp))(va_list list, params_t *params);
int get_print_func(char *sp, va_list list, params_t *params);
int get_flag(char *sp, params_t *params);
int get_modifier(char *sp, params_t *params);
char *get_width(char *sp, params_t *params, va_list list);

/* convert_number.c */

int print_hex_LOW(va_list list, params_t *params);
int print_hex_UP(va_list list, params_t *params);
int print_binary(va_list list, params_t *params);
int print_octal(va_list list, params_t *params);

/* simple_printers.c */

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list list, params_t *params);
int print_rot13(va_list list, params_t *params);

/* print_number.c */

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *string, params_t *params);
int print_number_right(char *string, params_t *params);
int print_number_left(char *string, params_t *params);

/* params.c */

void init_params(params_t *params, va_list list);

/* string_fields.c modoule */

char *get_precision(char *f, params_t *params, va_list list);

/* _prinf.c */

int _printf(const char *format, ...);

#endif
