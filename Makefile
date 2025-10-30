# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: becanals <becanals@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 14:27:49 by becanals          #+#    #+#              #
#    Updated: 2025/10/30 16:20:07 by becanals         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FLS =	main.c \
			constructors.c \
			fts_state1.c \
			fts_state2.c \
			fts_convert1.c \
			fts_convert2.c \
			expansion1.c \
			expansion2.c
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FLS))

BUILD_DIR = build
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INC_DIR = inc
INC = $(INC_DIR)/ft_printf.h

CC = cc
CFLAGS += -Wall -Wextra -Werror -g -fsanitize=address

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $@ $(OBJS)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

test: $(NAME) test.c
	$(CC) -g -fsanitize=address test.c -L. $(NAME) libft.a -o test

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean 
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
