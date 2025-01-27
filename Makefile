# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcoquet <jcoquet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 08:32:24 by jcoquet           #+#    #+#              #
#    Updated: 2024/04/04 10:38:31 by jcoquet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER		= server

NAME_CLIENT 	= client

CC 				= gcc

CFLAGS 			= -Wall -Wextra -Werror -I.

SRCS_SERVER		= server.c

SRCS_CLIENT		= client.c

OBJS_SERVER		= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT		= $(SRCS_CLIENT:.c=.o)

LIBFT			= libft/libft.a
LIBFT_MAKE		= make -C libft
LIBFT_CLEAN		= make clean -C libft
LIBFT_FCLEAN	= make fclean -C libft

all:		$(NAME_SERVER) $(NAME_CLIENT) $(LIBFT)

$(NAME_SERVER): 	$(LIBFT) $(OBJS_SERVER)
				@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRCS_SERVER) $(LIBFT)
				
$(NAME_CLIENT): $(OBJS_CLIENT)  $(LIBFT)
				@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(LIBFT)
$(LIBFT):	
				@$(LIBFT_MAKE)
				@$(LIBFT_CLEAN)

clean:
				@rm -f $(OBJS_CLIENT) $(OBJS_SERVER)

fclean: 		clean
				@rm -f $(NAME_SERVER) $(NAME_CLIENT) 
				@$(LIBFT_FCLEAN)
				
re:		
		@	rm -f  $(OBJS_CLIENT) $(OBJS_SERVER) $(NAME_SERVER) $(NAME_CLIENT) 
		@	$(LIBFT_FCLEAN)
		@	make all

.PHONY = all clean fclean re