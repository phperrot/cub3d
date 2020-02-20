# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: phperrot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 11:03:14 by phperrot          #+#    #+#              #
#    Updated: 2019/11/19 12:09:20 by phperrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

HEADER = libft.h

NAME = libft.a

SRC = ft_memset.c \
	  ft_bzero.c\
	  ft_memcpy.c\
	  ft_memccpy.c\
	  ft_memmove.c\
	  ft_memchr.c\
	  ft_memcmp.c\
	  ft_strlen.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_strchr.c\
	  ft_strrchr.c\
	  ft_strncmp.c\
	  ft_strlcpy.c\
	  ft_strlcat.c\
	  ft_strnstr.c\
	  ft_atoi.c\
	  ft_atoi_conv.c\
	  ft_calloc.c\
	  ft_strdup.c\
	  ft_strdup_free.c\
	  ft_strdup_char.c\
	  ft_substr.c\
	  ft_strjoin.c\
	  ft_strjoin_free.c\
	  ft_strtrim.c\
	  ft_split.c\
	  ft_ctoa.c\
	  ft_itoa.c\
	  ft_itoa_long.c\
	  ft_strmapi.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putnbr.c\
	  ft_strreplace.c\
	  ft_strsub.c\

SRCSBONUS = ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)

BOBJ = $(SRCSBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

bonus: $(OBJ) $(BOBJ)
	@ar rc $(NAME) $(OBJ) $(BOBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"
	@echo "bonus added"

%.o: %.c
	@gcc $(FLAG) -I includes -c $< -o $@

clean:
	@rm -f $(OBJ) $(BOBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all 

.PHONY: all, clean, fclean, re, bonus
