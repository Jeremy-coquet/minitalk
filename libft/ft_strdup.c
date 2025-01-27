/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerem <jeremy.coquet38@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:58:49 by jerem             #+#    #+#             */
/*   Updated: 2024/02/08 11:58:49 by jerem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char	*ft_strdup(unsigned char *src)
{
	unsigned char	*dest;
	int				i;
	int				size;

	i = 0;
	size = ft_strlen((const char *)src);
	dest = (unsigned char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	printf("%s", ft_strdup("hello"));
// 	return (0);
// }
