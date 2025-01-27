/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_pf.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 07:49:19 by jcoquet           #+#    #+#             */
/*   Updated: 2024/04/09 08:29:29 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned_pf(unsigned int nb, size_t *len)
{
	unsigned long int	nb2;

	nb2 = nb;
	if (nb2 > 9)
		ft_putnbr_unsigned_pf(nb2 / 10, len);
	ft_putchar_pf("0123456789"[nb2 % 10], len);
}
