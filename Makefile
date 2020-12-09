# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2020/12/09 07:45:29 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

LBPATH = ./libft/

LBNAME = $(LBPATH)libft.a

SRCS = main.c \
	   ft_save_bmp.c

OBJS_NAME = ${SRCS:.c=.o}

OBJS_PATH = ./objs/

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

CC	 =	gcc -Wall -Werror -Wextra

RM	 = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LBPATH)
	@cp $(LBNAME) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	$(info miniRT compiled !)

$(OBJS_PATH)%.o : %.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) -I ft_printf.h -c $< -o $@

clean:
	@make clean -C $(LBPATH)
	@$(RM) $(OBJS)
	@make fclean -C $(LBPATH)
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LBPATH)

re: fclean all
	@make re -C $(LBPATH)

.PHONY: all, clean, fclean, re
