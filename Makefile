# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbalbous <rbalbous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 17:34:45 by rbalbous          #+#    #+#              #
#    Updated: 2018/04/05 14:30:08 by rbalbous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

INCLUDES = includes
OBJ_PATH = obj

include ft_printf/conv/conv.mk
include ft_printf/flags/flags.mk
include	ft_printf/tools/tools.mk
include basic/libft.mk

all : $(NAME)

$(NAME) :	$(OBJ)
			@mkdir $(OBJ_PATH) 2> /dev/null || true
			@ar rc $(NAME) $^
			@ranlib $(NAME)
			@echo "\033[33mlib done\033[m"
			
clean :
			@rm -f $(OBJ)

fclean : 	clean
			@rm -f $(NAME)
		
re :
	@make fclean
	@make all

.PHONY: all clean fclean re
