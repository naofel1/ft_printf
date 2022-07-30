# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nabentay <nabentay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 20:38:18 by nabentay          #+#    #+#              #
#    Updated: 2022/07/30 21:38:48 by nabentay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

FILES = ft_check \
		ft_print \
		ft_print2 \
		ft_printf \
		ft_puthex \
		ft_putnbr \
		ft_putptr \

SRCS_DIR = srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB_NAME): $(OBJS)
	$(AR) $@ $^

all: $(LIB_NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIB_NAME)

re: clean all

.PHONY: bonus all clean fclean re

