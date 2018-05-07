# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pchadeni <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 14:57:58 by pchadeni          #+#    #+#              #
#    Updated: 2018/05/07 18:36:58 by pchadeni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------Compilation's flags------#

AR = ar rc
CC = gcc

# flags
C_FLAGS = -Wall -Wextra

ifneq ($(NOERR),yes)
C_FLAGS += -Werror
endif

ifeq ($(DEV),yes)
FLAGS += -g
endif

ifeq ($(SAN),yes)
FLAGS += -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls
endif

#------Name of the project------#

NAME = libftprintf.a

#------All sources------#

FTPRINTF = ft_printf.c	\
	   attrib_flags.c	\
	   check_flags.c	\
	   struct.c			\
	   parser.c			\
	   flags_digit.c	\
	   flags_str.c		\
	   ft_utoa_base.c	\
	   ft_itoa_base.c	\
	   check_char.c		\
	   conv_digit.c		\
	   conv_cs.c		\
	   conv_majcs.c		\
	   conv_uni.c		\
	   exit_printf.c	\
	   ft_strzerojoin.c	\
	   print_flags.c

############ Do not edit ############

#------Library------#

INCLUDES = ./includes/
INC += -I$(INCLUDES)
INC += -I $(LIB_PATH)

#### FILES FROM LIB ####
LIB_FILES = ft_atoi.c	\
		ft_bzero.c		\
		ft_case.c 		\
		ft_checkopt.c	\
		ft_foreachint.c	\
		ft_getopt.c		\
		ft_ischar.c		\
		ft_isx.c		\
		ft_itoa.c		\
		ft_lastchar.c	\
		ft_lstalloc.c	\
		ft_lstmanip.c	\
		ft_maths.c		\
		ft_memalloc.c	\
		ft_memmanip.c	\
		ft_nbchar.c		\
		ft_nbwords.c	\
		ft_put.c		\
		ft_put_fd.c		\
		ft_putcolor.c	\
		ft_putsgap.c	\
		ft_putformat.c	\
		ft_strcat.c		\
		ft_strchr.c		\
		ft_strclr.c		\
		ft_strcmp.c		\
		ft_strcpy.c		\
		ft_strdel.c		\
		ft_strdup.c		\
		ft_strgap.c		\
		ft_striter.c	\
		ft_strjoin.c	\
		ft_strlen.c		\
		ft_strmap.c		\
		ft_strnew.c		\
		ft_splitwsp.c	\
		ft_strsplit.c	\
		ft_strstr.c		\
		ft_strsub.c		\
		ft_strtrim.c	\
		ft_tab.c		\
		get_next_line.c

#------Path------#

OPATH = obj
LIB_PATH = libft
SRCS_PATH = srcs
SRCS_LIB    += $(addprefix $(LIB_PATH)/, $(LIB_FILES))
SRCS_PRINTF += $(addprefix $(SRCS_PATH)/, $(FTPRINTF))

SRCS += $(SRCS_LIB)
SRCS += $(SRCS_PRINTF)

OBJP += $(addprefix ./$(OPATH)/, $(LIB_PATH))
OBJP += $(addprefix ./$(OPATH)/, $(SRCS_PATH))

OBJ += $(addprefix ./$(OPATH)/, $(SRCS:.c=.o))

#------Main rules------#

all: $(OPATH) $(NAME)

$(NAME): $(OBJ)
	@echo "Start making $(NAME)..."
	@$(AR) $(NAME) $^
	@ranlib $(NAME)
	@echo "$(BOLD_GREEN)$(NAME) created ✓$(EOC)"

$(OPATH):
	@echo "Start creating obj folder..."
	@mkdir -p $(OPATH)
	@echo "$(OPATH) created"
	@mkdir -p $(OBJP)
	@echo "$(OBJP) created"

$(OPATH)/%.o: %.c
	@$(CC) $(FLAGS) $(C_FLAGS) $(INC) -o $@ -c $<
	@echo " $(COL_GREEN)[OK]$(EOC)    $(COL_YELLOW)Compiling:$(EOC)" $<

clean:
	@rm -Rf $(OPATH)
	@echo "$(BOLD_GREEN)$(NAME) clean ✓$(EOC)"

fclean: clean
	@rm -Rf $(NAME)
	@echo "$(BOLD_GREEN)$(NAME) fclean ✓$(EOC)"

re: fclean all

#############################################################################
#ARETIRER
main: $(NAME)
	$(CC) $(FLAGS) main.c $(NAME) -o SORTIE

#------Define colors------#

BOLD_GREEN = \033[01;32m
COL_GREEN = \033[0;32m
COL_YELLOW = \033[0;33m
EOC = \033[0m

