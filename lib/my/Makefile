##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Make library
##

COMPILE_BASIC = true
COMPILE_PRINTF = false
COMPILE_LINKED = true
COMPILE_ENGINE = false

CC=gcc

CFLAGS=-Werror -Wall -Wextra

BASIC_SOURCE = src/basic/my_strupcase.c \
			src/basic/my_getnbr.c \
			src/basic/my_str_islower.c \
			src/basic/my_str_to_word_array.c \
			src/basic/my_str_isnum.c \
			src/basic/my_str_isalnum.c \
			src/basic/my_strcpy.c \
			src/basic/my_put_nbr.c \
			src/basic/my_strcmp.c \
			src/basic/my_find_prime_sup.c \
			src/basic/my_isneg.c \
			src/basic/convert_base.c \
			src/basic/my_strlowcase.c \
			src/basic/my_show_word_array.c \
			src/basic/my_swap.c \
			src/basic/my_showstr.c \
			src/basic/my_compute_square_root.c \
			src/basic/my_strncmp.c \
			src/basic/my_str_isprintable.c \
			src/basic/my_showmem.c \
			src/basic/my_is_prime.c \
			src/basic/my_putstr.c \
			src/basic/my_strcat.c \
			src/basic/my_strncpy.c \
			src/basic/my_sort_int_array.c \
			src/basic/my_strdup.c \
			src/basic/my_strlen.c \
			src/basic/my_putchar.c \
			src/basic/my_strcapitalize.c \
			src/basic/my_getnbr_base.c \
			src/basic/my_strncat.c \
			src/basic/my_revstr.c \
			src/basic/my_strstr.c \
			src/basic/my_str_isalpha.c \
			src/basic/my_str_isupper.c \
			src/basic/my_putnbr_base.c \
			src/basic/my_compute_power_rec.c\
			src/basic/my_memcmp.c \
			src/basic/my_memset.c \
			src/basic/my_strchr.c \
			src/basic/my_strrchr.c \
			src/basic/my_memcpy.c \
			src/basic/my_strjoin.c \
			src/basic/my_calloc.c \
			src/basic/my_split.c \
			src/basic/my_coolersplit.c \
			src/basic/my_memjoin.c \
			src/basic/my_memchr.c \
			src/basic/my_memmove.c \
			src/basic/gnl.c \
			src/basic/my_revmem.c \
			src/basic/report_error.c \
			src/basic/my_strreplace.c \


PRINTF_SOURCE = src/my_printf/genericf.c \
			src/my_printf/f_functions.c \
			src/my_printf/parameter_utils.c \
			src/my_printf/utils1.c \
			src/my_printf/utils2.c \
			src/my_printf/utils3.c \


LINKED_SOURCE = src/linked_lists/creation.c \
			src/linked_lists/deletion.c \
			src/linked_lists/simple_operations.c \
			src/linked_lists/iter_tools.c \
			src/linked_lists/modifications.c \
			src/linked_lists/sort.c \


ENGINE_SOURCE = src/engine/creation.c \
			src/engine/destruction.c \
			src/engine/deletion.c \
			src/engine/ticks.c \
			src/engine/displayer.c \
			src/engine/finder.c \
			src/engine/sprite_helper.c \
			src/engine/controller.c \
			src/engine/sprite_creation.c \
			src/engine/sprite_creation2.c \
			src/engine/collisions.c \
			src/engine/buttons.c \

C_FILES =

HEADERS = include/macros.h

ifeq ($(COMPILE_BASIC), true)
	C_FILES += $(BASIC_SOURCE)
	HEADERS += include/basic.h
endif
ifeq ($(COMPILE_LINKED), true)
	C_FILES += $(LINKED_SOURCE)
	HEADERS += include/linked_list.h
endif
ifeq ($(COMPILE_PRINTF), true)
	C_FILES += $(PRINTF_SOURCE)
	HEADERS += include/my_printf.h
endif
ifeq ($(COMPILE_ENGINE), true)
	C_FILES += $(ENGINE_SOURCE)
	HEADERS += include/engine.h
endif

O_FILES = $(C_FILES:.c=.o)

ASSETS = assets/font.ttf \

ASSETS_O = $(ASSETS:=.o)

EXTERN_H = $(subst include/,../../include/,$(HEADERS))

NAME=libmy.a

$(NAME): $(O_FILES) $(ASSETS_O)
	ar -rsc $(NAME) $(O_FILES) $(ASSETS_O)
	cp $(NAME) ../
	mkdir -p ../../include
	cp $(HEADERS) ../../include

all: $(NAME)

clean:
	rm -f $(O_FILES)
	rm -f $(ASSETS_O)

fclean: clean
	rm -f ../$(NAME)
	rm -f $(EXTERN_H)
	rm -f $(NAME)

re: fclean all

$(ASSETS_O): $(ASSETS)
	xxd -i "$<" | gcc -x c - -c -o "$@"

$(ASSETS): ;

.PHONY: all clean fclean re
