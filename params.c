#include "main.h"

/**
 * init_params - clears struct; reset buf
 *
 * @params: the parameters struct
 *
 * @list: the argument pointer
 *
 * Return: Nothing
 */

void init_params(params_t *params, va_list list)
{
	params->unsign = 0;

	params->zero_flag = 0;
	params->plus_flag = 0;
	params->minus_flag = 0;
	params->space_flag = 0;
	params->hashtag_flag = 0;

	params->width = 0;
	params->precision = UINT_MAX;

	params->h_modifier = 0;
	params->l_modifier = 0;

	(void)list;
}
