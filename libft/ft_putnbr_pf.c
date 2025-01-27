/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:16:37 by jcoquet           #+#    #+#             */
/*   Updated: 2024/04/09 08:29:25 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_pf(int nb, size_t *len)
{
	long int	nb2;

	nb2 = nb;
	if (nb2 < 0)
	{
		ft_putchar_pf('-', len);
		nb2 *= -1;
	}
	if (nb2 > 9)
		ft_putnbr_pf(nb2 / 10, len);
	ft_putchar_pf("0123456789"[nb2 % 10], len);
}
