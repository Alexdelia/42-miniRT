# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/01/18 09:56:47 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

LBPATH = ./libft/
LBNAME = $(LBPATH)libft.a

MLXPATH = ./mlx/
MLXNAME = $(MLXPATH)libmlx.a

SRCS = main.c \
	   ft_parse.c \
	   ft_render.c \
	   ft_check.c \
	   ft_save_bmp.c \
	   ft_display.c \
	   ft_utils.c \
	   ft_vector_math.c \
	   ft_fill_struct.c \
	   ft_free.c \
	   intersection/ft_sphere.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line.h \
	   get_next_line/get_next_line_utils.c
# WIP, ft_sphere.c will replace ft_parse.c to handle more form and a way better way

INCLUDE = miniRT.h

OBJS_NAME = ${SRCS:.c=.o}

OBJS_PATH = ./objs/

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

CC	 =	gcc -Wall -Werror -Wextra

# GRAPHICAL LFGLAGS (for linux):
LDFLAGS		+=	-lX11 -lXext
# - lmlx

# LDFLAGS (math.h)
LDFLAGS		+=	-lm

RM	 = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(LIBFTM) $(MLXM)
	@make -C $(LBPATH)
	@make -C $(MLXPATH)
	$(CC) $(OBJS) $(LBNAME) $(MLXNAME) -o $(NAME) $(LDFLAGS)
	$(info miniRT compiled !)

$(LIBFTM):
	make -C $(LBPATH) -f Makefile

$(MLXM):
	make -C $(MLXPATH) -f Makefile

$(OBJS_PATH)%.o : %.c
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@$(CC) -I $(INCLUDE) -c $< -o $@

libft:	$(LIBFTM)

mlx:	$(MLXM)

clean:
	$(RM) $(OBJS)
	make -C $(LBPATH) -f Makefile clean
	make -C $(MLXPATH) -f Makefile clean
	@rmdir $(OBJS_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME) $(MLXM)
	make -C $(LBPATH) -f Makefile fclean

re: fclean $(NAME)

.PHONY: all, clean, fclean, re, libft, mlx
