/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:34:49 by jcoquet           #+#    #+#             */
/*   Updated: 2024/04/09 08:30:35 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static void	ft_filter(char *str, va_list args, size_t *len)
{
	if (*str == 'c')
		ft_putchar_pf(va_arg(args, int), len);
	else if (*str == 's')
		ft_putstr_pf(va_arg(args, char *), len);
	else if (*str == '%')
		ft_putchar_pf('%', len);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_pf(va_arg(args, int), len);
	else if (*str == 'u')
		ft_putnbr_unsigned_pf(va_arg(args, unsigned int), len);
	else if (*str == 'x')
		ft_putnbrhexa_pf(va_arg(args, unsigned int), len);
	else if (*str == 'X')
		ft_putnbrhexa_uppercase_pf(va_arg(args, unsigned int), len);
	else if (*str == 'p')
		ft_putptr_pf(va_arg(args, void *), len);
}

int	ft_printf(const char *str, ...)
{
	size_t		len;
	va_list		args;

	len = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && (*str + 1) != '\0')
		{
			ft_filter((char *)str + 1, args, &len);
			str++;
		}
		else
			ft_putchar_pf(*str, &len);
		str++;
	}
	va_end(args);
	return ((int)len);
}

// int	main(void)
// {
// 	void	*ptr;
// 	ptr = NULL;

// 	printf("\nAVEC LE VRAI PRINTF\n");
// 	printf("\n%i\n\n", printf("%p", ""));

// 	printf("AVEC MON FT_PRINTF\n\n");
// 	printf("\n%i\n\n", ft_printf("%p", ""));
// 	return (0);
// }
