# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jerem <jeremy.coquet38@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/07 11:46:16 by jerem             #+#    #+#              #
#    Updated: 2024/02/07 11:46:16 by jerem            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		ft_atoi.c \
					ft_putchar_fd.c \
					ft_putnbr_fd.c \
					ft_strdup.c \
					ft_strlen.c \
					ft_strjoin.c \
					ft_printf.c \
					ft_putchar_pf.c \
					ft_putnbr_pf.c \
					ft_putnbr_unsigned_pf.c \
					ft_putnbrhexa_pf.c \
					ft_putptr_pf.c \
					ft_putstr_pf.c \

					
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus