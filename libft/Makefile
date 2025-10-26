# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: becanals <becanals@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 14:27:49 by becanals          #+#    #+#              #
#    Updated: 2025/10/26 19:49:37 by bizcru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	ft_islower.c \
		ft_isupper.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isprint.c \
		ft_isascii.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memrcpy.c \
		ft_memmove.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_memchr.c \
		ft_memchr_pos.c \
		ft_memrchr.c \
		ft_strnstr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_utoa_base.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c

OBJS = $(SRCS:.c=.o)

INC_DIR = .

INC = ft.h

CC = cc

CFLAGS += -Wall -Wextra -Werror

NAME = libft.a

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) Makefile
	ar rcs $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
