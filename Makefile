# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: becanals <becanals@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 14:27:49 by becanals          #+#    #+#              #
#    Updated: 2025/11/19 18:13:34 by becanals         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FLS =	main.c \
			constructors.c \
			fts_state.c \
			fts_convert1.c \
			fts_convert2.c 
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FLS))
BUILD_DIR = build
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

SRC_FLS_BNS = main_bonus.c \
			constructors_bonus.c \
			fts_state1_bonus.c \
			fts_state2_bonus.c \
			fts_convert1_bonus.c \
			fts_convert2_bonus.c \
			expansion1_bonus.c \
			expansion2_bonus.c
SRC_DIR_BNS = bns
SRCS_BNS = $(addprefix $(SRC_DIR_BNS)/, $(SRC_FLS_BNS))
BUILD_DIR_BNS = build_bns
OBJS_BNS = $(SRCS_BNS:$(SRC_DIR_BNS)/%.c=$(BUILD_DIR_BNS)/%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INC_DIR = inc
INC = $(INC_DIR)/ft_printf.h

CC = cc
CFLAGS += -Wall -Wextra -Werror #-g -fsanitize=address

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(INC) Makefile
	cp $(LIBFT) $(NAME)
	ar -rcs $@ $(OBJS)
	ranlib $@

$(LIBFT): 
	make -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile | $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR_BNS)/%.o: $(SRC_DIR_BNS)/%.c $(INC) Makefile | $(BUILD_DIR_BNS)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(BUILD_DIR_BNS):
	mkdir -p $(BUILD_DIR_BNS)

bonus: $(OBJS_BNS) $(LIBFT) $(INC) Makefile 
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS_BNS)
	ranlib $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(BUILD_DIR)

bclean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(BUILD_DIR_BNS)

fclean: clean bclean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
