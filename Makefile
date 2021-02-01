# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/02/01 12:40:14 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = clang -Wall -Werror -Wextra
RM = rm -rf

LBPATH = ./libft/
LBNAME = $(LBPATH)libft.a
LBINC = -I$(LBPATH)

MLXPATH = ./mlx/
MLXNAME = $(MLXPATH)libmlx.a
MLXINC = -I$(MLXPATH)

SRCSPATH = ./srcs/
OBJSPATH = ./objs/
INC = ./includes/

SRCSNAME = main.c \
	   ft_check.c \
	   parse/ft_parse.c \
	   parse/ft_parse_get.c \
	   parse/ft_parse_init_list.c \
	   parse/ft_parse_utils.c \
	   parse/ft_parse_utils2.c \
	   parse/ft_parse_utils3.c \
	   parse/ft_get_obj.c \
	   parse/ft_get_obj_PRDH.c \
	   ft_render.c \
	   ft_light.c \
	   ft_color.c \
	   ft_phong.c \
	   intersection/ft_intersection.c \
	   intersection/ft_sphere.c \
	   intersection/ft_plane.c \
	   intersection/ft_square.c \
	   intersection/ft_triangle.c \
	   intersection/ft_cylinder.c \
	   ft_save_bmp.c \
	   ft_display.c \
	   ft_utils.c \
	   ft_vector_math.c \
	   ft_fill_struct.c \
	   ft_free.c \
	   get_next_line.c \
	   get_next_line_utils.c

SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))
OBJS = $(SRCS:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))

# GRAPHICAL LFGLAGS (for linux):
LDFLAGS		+=	-lXext -lX11
# -lmlx

# LDFLAGS (math.h)
LDFLAGS		+=	-lm

all: $(NAME)

%.o: %.c
	$(CC) -I$(INC) -Imlx $(LBINC) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LBPATH)
	make -C $(MLXPATH)
	$(CC) $(OBJS) $(MLXNAME) $(LBNAME) -L$(MLXPATH) -L$(LBPATH) $(LBINC) $(MLXINC) -I$(INC) $(LDFLAGS) -o $(NAME)
	$(info miniRT compiled !)

$(LIBFTM):
	make -C $(LBPATH) -f Makefile

$(MLXM):
	make -C $(MLXPATH) -f Makefile

#$(OBJSPATH)%.o : %.c
#	@mkdir $(OBJSPATH) 2> /dev/null || true
#	@$(CC) -I $(INC) -c $< -o $@

libft:	$(LIBFTM)

mlx:	$(MLXM)

clean:
	$(RM) $(OBJS)
	make -C $(LBPATH) -f Makefile clean
	make -C $(MLXPATH) -f Makefile clean
	#@rmdir $(OBJSPATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME) $(MLXM)
	make -C $(LBPATH) -f Makefile fclean

re: fclean $(NAME)

.PHONY: all, clean, fclean, re, libft, mlx
