/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcoquet <jcoquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:35:10 by jcoquet           #+#    #+#             */
/*   Updated: 2024/04/09 09:13:44 by jcoquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strjoin(unsigned const char *s1, unsigned const char c)
{
	unsigned char	*join;
	int				i;
	int				j;
	int				size;

	j = 0;
	i = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen((const char *)s1);
	join = (unsigned char *)malloc((sizeof(char) * (size + 2)));
	if (!join)
		return (NULL);
	while (s1[i])
		join[j++] = s1[i++];
	join[j++] = c;
	join[j] = '\0';
	return (join);
}
