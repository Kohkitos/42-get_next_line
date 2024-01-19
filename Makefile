# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsanz-go <fsanz-go@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/19 18:19:50 by fsanz-go          #+#    #+#              #
#    Updated: 2024/01/19 18:22:10 by fsanz-go         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME

NAME = get_next_line.a

# COMPILER

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar -rc

# INCLUDE

INCLUDE = get_next_line.h

# SOURCES

SRC = 

OBJ = $(SRC:%.c=%.o)


# RM

RM = rm -rf

# RULES

.PHONY: all re clean fclean bonus

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		$(AR) $(NAME) $(OBJ)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all