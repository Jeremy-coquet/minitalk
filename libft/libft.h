/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerem <jeremy.coquet38@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:27:28 by jerem             #+#    #+#             */
/*   Updated: 2024/02/07 09:27:28 by jerem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int				ft_atoi(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(int n, int fd);
unsigned char	*ft_strdup(unsigned char *src);
unsigned char	*ft_strjoin(unsigned const char *s1, unsigned char c);
size_t			ft_strlen(const char *str);
int				ft_printf(const char *str, ...);
void			ft_putchar_pf(char c, size_t *len);
void			ft_putnbr_pf(int nb, size_t *len);
void			ft_putnbr_unsigned_pf(unsigned int nb, size_t *len);
void			ft_putnbrhexa_pf(unsigned int nb, size_t *len);
void			ft_putnbrhexa_uppercase_pf(unsigned int nb, size_t *len);
void			ft_putptr_pf(void *ptr, size_t *len);
void			ft_putstr_pf(char *str, size_t *len);
int				ft_printf(const char *str, ...);

#endif