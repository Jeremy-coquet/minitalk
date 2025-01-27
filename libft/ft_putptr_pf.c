/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:35:58 by jcoquet           #+#    #+#             */
/*   Updated: 2024/04/09 08:29:35 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_printadress_pf(unsigned long int nb, size_t *len)
{
	if (nb > 15)
		ft_printadress_pf(nb / 16, len);
	ft_putchar_pf("0123456789abcdef"[nb % 16], len);
}

void	ft_putptr_pf(void *ptr, size_t *len)
{
	ft_putstr_pf("0x", len);
	ft_printadress_pf((unsigned long int)ptr, len);
}
