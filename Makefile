# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 14:57:58 by pchadeni          #+#    #+#              #
#    Updated: 2018/04/18 16:12:17 by pchadeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------Compilation's flags------#

AR = ar rc
CC = gcc

# flags
C_FLAGS = -Wall -Wextra

ifneq ($(NOERR),yes)
FLAGS += -Werror
endif
#------Name of the project------#

NAME = libftprintf.a

#------All sources------#

SRCS = ft_printf.c		\
	   check_flags.c	\
	   struct.c			\
	   parser.c			\
	   display.c		\
	   print_flags.c		\
	   ft_ischar.c		\
	   ft_put.c			\
	   ft_strchr.c		\
	   ft_strlen.c

#------Library------#

INCLUDES = ./includes/
INC += -I$(INCLUDES)

############ Do not edit ############

OBJ = $(SRCS:.c=.o)

#------Path------#

SRCPATH = ./srcs
OPATH = ./obj

OBJP = $(addprefix $(OPATH)/, $(SRCS:.c=.o))

#------Main rules------#

all: $(LIB) $(OPATH) $(NAME)

re: fclean all

$(OPATH)/%.o: $(SRCPATH)/%.c
	@$(CC) $(C_FLAGS) $(INC) -o $@ -c $^
	@echo " $(COL_GREEN)[OK]$(EOC)    $(COL_YELLOW)Compiling:$(EOC)" $<

$(OPATH):
	@mkdir -p $(OPATH)

$(NAME): $(OBJP)
	@$(AR) $(NAME) $^
	@ranlib $(NAME)
	@echo "$(BOLD_GREEN)$(NAME) created ✓$(EOC)"

clean:
	@rm -Rf $(OPATH)
	@echo "$(BOLD_GREEN)$(NAME) clean ✓$(EOC)"

fclean: clean
	@rm -Rf $(NAME)
	@echo "$(BOLD_GREEN)$(NAME) fclean ✓$(EOC)"
#############################################################################
#############################################################################
#ARETIRER
main: $(NAME)
	$(CC) main.c $(NAME) -o SORTIE
#------Define colors------#

BOLD_GREEN = \033[01;32m
COL_GREEN = \033[0;32m
COL_YELLOW = \033[0;33m
EOC = \033[0m
