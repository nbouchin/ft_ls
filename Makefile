# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbouchin <nbouchin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/31 14:56:28 by nbouchin          #+#    #+#              #
#    Updated: 2017/03/22 09:48:30 by nbouchin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls
CC		= gcc
FLAGS	= -Wall -Wextra -Werror
LIB		= libft/libft.a
LIBSRC	= libft/
SRCDIR	= src/
OBJDIR	= ./obj/
HEADER	= includes/
SRC		= ft_ls.c		parser.c		flag_a.c		flag_l.c \
		  print_file.c	order_file.c	flag_t.c		flag_r.c \
		  ft_del.c		print_oth.c		print_l.c 		execls.c \
		  error.c		print_info.c 	init_data.c 	flag_deal.c \
		  putspace.c	read_flag.c		ft_putcolor.c	del.c \
		  put_date.c
GRN		=	\033[0;32m
RED		=	\033[0;31m
CYN		=	\033[0;36m
NC		=	\033[0m

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -L./$(LIBSRC) -lft -o $(NAME) $(OBJS)
	@echo "\n${CYN}PROCESSING DONE !${NC}"

$(LIB):
	@echo "${CYN}Processing ${NC}./libft/obj ${CYN}[${NC}...${CYN}]${NC}"
	@make -C $(LIBSRC)
	@echo "\n${CYN}Processing ${NC}./obj ${CYN}[${NC}...${CYN}]${NC}"

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)$(NAME).h
	@echo "${GRN}Compiling${NC} $@"
	@$(CC) $(FLAGS) -c -o $@ $< -I $(HEADER)

clean:
	@echo "${RED}Cleaning ${NC}./obj/ ${RED}[${NC}...${RED}]${NC}"
	@rm -rf $(OBJS)
	@echo "${RED}Cleaning ${NC}./libft/obj/ ${RED}[${NC}...${RED}]${NC}"
	@make -C $(LIBSRC) clean

fclean: clean
	@echo "${RED}Cleaning ${NC}./${RED}ft_ls${NC}"
	@rm -Rf $(NAME)
	@echo "${RED}Cleaning ${NC}./libft/${RED}libft.h${NC}\n"
	@make -C $(LIBSRC) fclean
	@echo "${RED}DELET DONE !${NC}"

re: fclean all

.PHONY: all clean fclean re
