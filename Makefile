# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/15 14:56:51 by dhawkgir          #+#    #+#              #
#    Updated: 2022/01/15 14:56:52 by dhawkgir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
SRCPATH	=	src
OBJPATH	=	.obj
FT		=	libft
INC		=	include

SRCS	=	$(SRCPATH)/main.c		$(SRCPATH)/utils.c \
			$(SRCPATH)/execute.c	$(SRCPATH)/pipex.c

FLAGS	=	-Wall -Wextra -Werror

OBJECTS	=	$(SRCS:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

all: ${NAME}

$(NAME): ${OBJECTS} ${FT}
	make -s -C ${FT}
	cc -I ${INC} $(OBJECTS) -l ft -L ${FT} -o $(NAME)
	@printf "\t\e[5m\e[1m\e[32m>>>>>>>>>>\t$(NAME) created\t<<<<<<<<<<\e[0m\n"

$(OBJPATH)/%.o: $(SRCPATH)/%.c ${INC}/pipex.h | $(OBJPATH)
	cc ${FLAGS} -I ${INC} -c $< -o $@

$(OBJPATH):
	@mkdir -p $@

clean:
	make -s clean -C ${FT}
	rm -rf ${OBJPATH}

fclean: clean
	make -s fclean -C ${FT}
	rm -f ${NAME}
	@printf "\t\e[1m\e[31m>>>>>>>>>>\t$(NAME) cleaned\t<<<<<<<<<<\e[0m\n\n"

re: fclean all

bonus: ${NAME}

norm:
	norminette $(SRCPATH) $(INC) ${FT}

.PHONY: all clean fclean norm re bonus
