# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slynell <slynell@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/14 11:23:23 by slynell           #+#    #+#              #
#    Updated: 2020/08/06 12:56:45 by slynell          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra -O2

SDIR = src

ODIR = obj

HDIR = header

HEAD = libft.h
HEAD += macros.h
HEAD += ft_printf.h
HEAD += ft_printf_const_data.h
HEAD += ft_printf_errors.h

SRC = ft_check_integer.c
SRC += ft_atoill.c
SRC += get_next_line.c
SRC += ft_lstnew.c
SRC += ft_putendl_fd.c
SRC += ft_strequ.c
SRC += ft_strnstr.c
SRC += ft_atoi.c
SRC += ft_memccpy.c
SRC += ft_putnbr.c
SRC += ft_striter.c
SRC += ft_strrchr.c
SRC += ft_bzero.c
SRC += ft_memchr.c
SRC += ft_putnbr_fd.c
SRC += ft_striteri.c
SRC	+= ft_countwords.c
SRC += ft_strsplit.c
SRC += ft_strsplitfree.c
SRC += ft_isalnum.c
SRC += ft_memcmp.c
SRC += ft_putstr.c
SRC += ft_strjoin.c
SRC += ft_strnjoin.c
SRC += ft_strstr.c
SRC += ft_isalpha.c
SRC += ft_memcpy.c
SRC += ft_putstr_fd.c
SRC += ft_strlcat.c
SRC += ft_strsub.c
SRC += ft_isascii.c
SRC += ft_memdel.c
SRC += ft_strcat.c
SRC += ft_strlen.c
SRC += ft_strtrim.c
SRC += ft_isdigit.c
SRC += ft_memalloc.c
SRC += ft_strnequ.c
SRC += ft_strchr.c
SRC += ft_strmap.c
SRC += ft_tolower.c
SRC += ft_isprint.c
SRC += ft_memmove.c
SRC += ft_strclr.c
SRC += ft_strmapi.c
SRC += ft_toupper.c
SRC += ft_itoa.c
SRC += ft_memset.c
SRC += ft_strcmp.c
SRC += ft_strncat.c
SRC += ft_lstadd.c
SRC += ft_putchar.c
SRC += ft_strcpy.c
SRC += ft_strncmp.c
SRC += ft_lstiter.c
SRC += ft_putchar_fd.c
SRC += ft_strdel.c
SRC += ft_strncpy.c
SRC += ft_lstlink.c
SRC += ft_putendl.c
SRC += ft_strdup.c
SRC += ft_strndup.c
SRC += ft_strnew.c
SRC += ft_lstaddcontent.c
SRC += ft_lstdel.c
SRC += ft_lstdelone.c
SRC += ft_lstmap.c
SRC += ft_lstpushback.c
SRC += ft_abs.c
SRC += ft_assert.c
SRC += ft_divmod.c
SRC += ft_intlen.c
SRC += ft_long_pow.c
SRC += ft_longlen.c
SRC += ft_memcpy.c
SRC += ft_memswap.c
SRC += ft_pow.c
SRC += ft_strany.c
SRC += ft_strlen.c
SRC += ft_strnequ.c
SRC += ft_strrev.c
SRC += ft_uitoa_base.c
SRC += ft_uitoa_dec.c
SRC += ft_uitoa_hex.c
SRC += ft_ultoa_base.c
SRC += ft_ultoa_hex.c
SRC += ft_wstrlen.c

SOURCES = $(addprefix $(SDIR)/,$(SRC))
OBJECTS = $(addprefix $(ODIR)/,$(SRC:.c=.o))

# /*
# ** ====================== SOURCE ARRAY ==========================
# */

SDIR_ARRAY = src/ft_array
ODIR_ARRAY = obj/ft_array

SRC_ARRAY = ft_array_min.c
SRC_ARRAY += ft_array_max.c
SRC_ARRAY += ft_array_print.c
SRC_ARRAY += ft_free_matrix.c

SOURCES_ARRAY = $(addprefix $(SDIR_ARRAY)/,$(SRC_ARRAY))
OBJECTS_ARRAY = $(addprefix $(ODIR_ARRAY)/,$(SRC_ARRAY:.c=.o))

# /*
# ** ====================== SOURCE PRINTF ==========================
# */

SDIR_PRINTF = src/ft_printf
ODIR_PRINTF = obj/ft_printf

SRC_PRINTF = buffer_n_print.c
SRC_PRINTF += float_processing.c
SRC_PRINTF += float_processing_ag.c
SRC_PRINTF += float_processing_ef.c
SRC_PRINTF += float_processing_fast_dtoa.c
SRC_PRINTF += float_processing_fast_ldtoa.c
SRC_PRINTF += float_processing_fxd_dbl.c
SRC_PRINTF += ft_printf.c
SRC_PRINTF += ft_printf_utils.c
SRC_PRINTF += get_format_arg.c
SRC_PRINTF += number_processing.c
SRC_PRINTF += string_processing.c

SOURCES_PRINTF = $(addprefix $(SDIR_PRINTF)/,$(SRC_PRINTF))
OBJECTS_PRINTF = $(addprefix $(ODIR_PRINTF)/,$(SRC_PRINTF:.c=.o))


HEADERS = $(addprefix $(HDIR)/,$(HEAD))

.PHONY: clean fclean all re

all : print $(NAME)
	@2> tmp.log
	@@echo "Project $(NAME) build successfully \c" >> tmp.log
	@echo "\nProject $(NAME) build successfully \033[32m[OK]\033[0m"

$(NAME) : $(OBJECTS) $(OBJECTS_PRINTF) $(OBJECTS_ARRAY) $(HEADERS) Makefile
	@ar rc $(NAME) $? 2> tmp.log
	@ranlib $(NAME) 2> tmp.log

print:
	@echo "\nMake \033[33m$(NAME)\033[0m\c"

$(ODIR_ARRAY)/%.o : $(SDIR_ARRAY)/%.c $(HEADERS) Makefile
	@mkdir -p $(ODIR_ARRAY) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

$(ODIR_PRINTF)/%.o : $(SDIR_PRINTF)/%.c $(HEADERS) Makefile
	@mkdir -p $(ODIR_PRINTF) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"

$(ODIR)/%.o : $(SDIR)/%.c $(HEADERS) Makefile
	@mkdir -p $(ODIR) 2> tmp.log
	@$(CC) $(FLAGS) -I $(HDIR) -c $< -o $@ 2> tmp.log
	@echo "\033[32m.\033[0m\c"


clean:
	@rm -rf $(ODIR) 2> tmp.log

fclean: clean
	@rm -f $(NAME) 2> tmp.log

re: fclean all
