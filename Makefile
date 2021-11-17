# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/11/17 16:02:07 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	miniRT
CC = 	clang
AR =	ar rcs
RM = 	rm -rf

CFLAGS =	-Wall -Werror -Wextra
CFLAGS +=	-O2
#CFLAGS +=	-g
#CFLAGS +=	-fsanitize=address

UNAME = $(shell uname)

# GRAPHICAL LFGLAGS (for linux):
#ifeq ($(shell uname), Linux)
LDFLAGS		+=	-lXext -lX11
#else
	#LDFLAGS		+=	-lmlx -framework OpenGL -framework AppKit
# -lmlx

# LDFLAGS (math.h)
LDFLAGS		+=	-lm

# **************************************************************************** #
#	MAKEFILE	#

MAKEFLAGS += --silent

SHELL := bash

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	 LIB	#

LIBPATH =	./libft/
LIBNAME =	$(LIBPATH)libft.a
LIBINC =	-I$(LIBPATH)

#ifeq ($(shell uname), Linux)
MLXPATH =	./mlx/
#else
#	MLXPATH	=	./mlx_macos/
#endif

MLXNAME =	$(MLXPATH)libmlx.a
MLXINC =	-I$(MLXPATH)

# **************************************************************************** #
#	SRCS	#

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./includes/

SRCS =		$(wildcard $(SRCSPATH)*.c) $(wildcard $(SRCSPATH)**/*.c)
SRCSNAME =	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME =	$(SRCSNAME:.c=.o)
OBJS =		$(addprefix $(OBJSPATH), $(OBJSNAME))

#%.o: %.c
#	$(CC) $(FLAGS) -Imlx $(BUFFER) -I$(INC) -c $< -o $(OBJSPATH)$(notdir $@)

# *************************************************************************** #

define	progress_bar
	i=0
	while [[ $$i -le $(words $(SRCS)) ]] ; do \
		printf " " ; \
		((i = i + 1)) ; \
	done
	printf "$(B)]\r[$(GRE)"
endef

# *************************************************************************** #
#	RULES	#

ifeq ($(UNAME), Linux)
all:		launch $(NAME)
	@printf "\n$(B)$(MAG)$(NAME) compiled$(D)\n"
else
all:
	@echo "$(B)$(RED)Error: Only Linux supported.$(D)"
endif

launch:
	$(call progress_bar)

$(NAME):	$(OBJS) lib mlx
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBNAME) $(MLXNAME) -o $(NAME)

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	$(CC) $(CFLAGS) -Imlx -I$(INC) -c $< -o $@
	@printf "█"

lib:
	@printf "$(D)$(B)$(BLU)\n$(NAME) objects compiled\n\n$(D)"
	@make -C $(LIBPATH)

mlx:
	@make -C $(MLXPATH) > /dev/null 2>&1 || true
	@printf "$(B)$(CYA)$(MLXNAME) compiled\n$(D)"

clean:
	@$(RM) $(OBJSNAME)
	@make clean -C $(LIBPATH)
	@make clean -C $(MLXPATH) > /dev/null 2>&1 || true
	@echo "$(B)Cleared$(D)"


fclean:		clean
	@$(RM) $(OBJSPATH)
	@$(RM) $(NAME)
	@make fclean -C $(LIBPATH)

re:			fclean all

.PHONY: all clean fclean re lib mlx

# **************************************************************************** #
