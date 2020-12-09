# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2020/12/09 23:14:16 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

LBPATH = ./libft/
LBNAME = $(LBPATH)libft.a

MLXPATH = ./mlx/
MLXNAME = $(MLXPATH)libmlx.a

SRCS = main.c \
	   ft_save_bmp.c

INCLUDE = miniRT.h

OBJS_NAME = ${SRCS:.c=.o}

OBJS_PATH = ./objs/

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

CC	 =	gcc -Wall -Werror -Wextra

# GRAPHICAL LFGLAGS (for linux):
LDFLAGS		+=	-lmlx -lX11 -lXext

RM	 = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTM) $(MLXM)
	$(info miniRT compiled !)

$(LIBFTM):
	make -C $(LBPATH) -f Makefile

$(MLXM):
	make -C $(MLXPATH) -f Makefile

$(OBJS_PATH)%.o : %.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) -I $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LBPATH) -f Makefile clean
	make -C $(MLXPATH) -f Makefile clean
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME) $(MLXM)
	make -C $(LBPATH) -f Makefile fclean

re: fclean $(NAME)

.PHONY: all, clean, fclean, re
