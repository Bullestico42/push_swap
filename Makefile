# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apiscopo <apiscopo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 01:14:37 by apiscopo          #+#    #+#              #
#    Updated: 2025/02/06 23:20:35 by apiscopo         ###   ########.fr        #
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
	@printf "\rCompiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@printf "\r$(NAME) compiled successfully.\n"

# Compile libft
$(LIBFT):
	@printf "\rCompiling libft..."
	@make -C libft/ --no-print-directory
	@printf "\rLibft compiled successfully.\n"

# Compilation des fichiers .o à partir des .c
%.o: %.c $(HEAD)
	@printf "\rCompiling $<...               "
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean objects
clean:
	@printf "\rCleaning object files..."
	@$(RM) $(OBJS)
	@make clean -C libft/ --no-print-directory
	@printf "\rObject files cleaned.\n"

# Clean everything
fclean: clean
	@printf "\rRemoving $(NAME)..."
	@$(RM) $(NAME)
	@make fclean -C libft/ --no-print-directory
	@printf "\r$(NAME) removed.\n"

# Recompile
re: fclean all

# Phony targets
.PHONY: all clean fclean re
