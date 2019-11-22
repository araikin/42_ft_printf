/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asultanb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:06:06 by asultanb          #+#    #+#             */
/*   Updated: 2019/11/21 18:39:00 by asultanb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	argp;

	i = 0;
	len = 0;
	va_start(argp, format);
	while (format[i])
	{
		if (format[i] == '%')
			len += parse_format(&argp, (char *)format, &i);
		else
			len += print_format(format[i++]);
	}
	va_end(argp);
	return (len);
}

int			print_format(char c)
{
	ft_putchar(c);
	return (1);
}

int			clear_format(t_format *data)
{
	free(data);
	return (0);
}

t_format	*initialize_format(void)
{
	t_format	*data;

	if (!(data = malloc(sizeof(data))))
		return (NULL);
	data->specifier = '\0';
	data->precision = 0;
	data->width = 0;
	data->length = 0;
	data->flags = 0;
	return (data);
}