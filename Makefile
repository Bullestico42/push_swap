# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apiscopo <apiscopo@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 01:14:37 by apiscopo          #+#    #+#              #
#    Updated: 2025/01/30 01:14:28 by apiscopo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft/libft.a

# Sources
SRC_DIR = src/
SRCS =	$(SRC_DIR)main.c \
		$(SRC_DIR)move.c \
		$(SRC_DIR)sort.c \
		$(SRC_DIR)sort_small.c \
		$(SRC_DIR)check_digits.c \
		$(SRC_DIR)check_digits_two.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)atol.c

# Objects
OBJS = $(SRCS:.c=.o)

# Headers
HEAD = include/push_swap.h

# Compiler and flags
CC = cc -g
CFLAGS = -Wall -Werror -Wextra

# Commands
RM = rm -f

# Rules
all: $(NAME)

# Compilation
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Compile libft
$(LIBFT):
	make -C libft/

# Clean objects
clean:
	$(RM) $(OBJS)
	make clean -C libft/

# Clean everything
fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

# Recompile
re: fclean all

# Phony targets
.PHONY: all clean fclean re
