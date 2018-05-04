# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 14:57:58 by pchadeni          #+#    #+#              #
#    Updated: 2018/05/04 15:08:37 by pchadeni         ###   ########.fr        #
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
	   display_flags.c	\
	   ft_utoa_base.c	\
	   ft_itoa_base.c	\
	   conv_flags.c		\
	   check_char.c		\
	   conv_gen.c		\
	   conv_majc.c		\
	   exit_printf.c	\
	   ft_strzerojoin.c	\
	   print_flags.c

#------Library------#

INCLUDES = ./includes/
INC += -I$(INCLUDES)
INC += -I $(LIB_PATH)

############ Do not edit ############

OBJ = $(SRCS:.c=.o)

#------Path------#

SRCPATH = ./srcs
OPATH = ./obj
LIB_PATH = ./libft

#### FILES FROM LIB ####
LIB_FILES = ft_atoi.c \
		ft_bzero.c \
		ft_case.c \
		ft_checkopt.c \
		ft_foreachint.c \
		ft_getopt.c \
		ft_ischar.c \
		ft_isx.c \
		ft_itoa.c \
		ft_lastchar.c \
		ft_lstalloc.c \
		ft_lstmanip.c \
		ft_maths.c \
		ft_memalloc.c \
		ft_memmanip.c \
		ft_nbchar.c \
		ft_nbwords.c \
		ft_put.c \
		ft_put_fd.c \
		ft_putcolor.c \
		ft_putsgap.c \
		ft_putformat.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strgap.c \
		ft_striter.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strnew.c \
		ft_splitwsp.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_tab.c \
		get_next_line.c
OBJP += $(addprefix $(LIB_PATH)/, $(LIB_FILES:.c=.o))
OBJP += $(addprefix $(OPATH)/, $(SRCS:.c=.o))

ifeq ($(DEV),yes)
	FLAGS += -g
endif

ifeq ($(SAN),yes)
	FLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

#------Main rules------#

all: c_lib $(OPATH) $(NAME)

re: fclean all

$(OPATH)/%.o: $(SRCPATH)/%.c
	@$(CC) $(FLAGS) $(C_FLAGS) $(INC) -o $@ -c $^
	@echo " $(COL_GREEN)[OK]$(EOC)    $(COL_YELLOW)Compiling:$(EOC)" $<

$(OPATH):
	@mkdir -p $(OPATH)

$(NAME): $(OBJP)
	@echo "Start making $(NAME)..."
	@$(AR) $(NAME) $^
	@ranlib $(NAME)
	@echo "$(BOLD_GREEN)$(NAME) created ✓$(EOC)"

clean:
	@$(MAKE) clean -C libft/
	@rm -Rf $(OPATH)
	@echo "$(BOLD_GREEN)$(NAME) clean ✓$(EOC)"

fclean: clean
	@$(MAKE) fclean -C libft/
	@rm -Rf $(NAME)
	@echo "$(BOLD_GREEN)$(NAME) fclean ✓$(EOC)"
#############################################################################
#############################################################################
#ARETIRER
main: $(NAME)
	$(CC) $(FLAGS) main.c $(NAME) -o SORTIE

#------Compilation of Libft------#

c_lib :
	@$(MAKE) -C libft/ MAKEFLAGS=

#------Define colors------#

BOLD_GREEN = \033[01;32m
COL_GREEN = \033[0;32m
COL_YELLOW = \033[0;33m
EOC = \033[0m

