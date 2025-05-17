# **************************************************************************** #
#                                  BIG LIBFT                                  #
# **************************************************************************** #

NAME		= lib/libbiglibft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f
INCLUDES	= -Iincludes

SRCS = \
	srcs/libc/ft_atoi.c \
	srcs/libc/ft_bzero.c \
	srcs/libc/ft_calloc.c \
	srcs/libc/ft_isalnum.c \
	srcs/libc/ft_isalpha.c \
	srcs/libc/ft_isascii.c \
	srcs/libc/ft_isdigit.c \
	srcs/libc/ft_isprint.c \
	srcs/libc/ft_itoa.c \
	srcs/libc/ft_memchr.c \
	srcs/libc/ft_memcmp.c \
	srcs/libc/ft_memcpy.c \
	srcs/libc/ft_memmove.c \
	srcs/libc/ft_memset.c \
	srcs/libc/ft_putchar_fd.c \
	srcs/libc/ft_putendl_fd.c \
	srcs/libc/ft_putnbr_fd.c \
	srcs/libc/ft_putstr_fd.c \
	srcs/libc/ft_split.c \
	srcs/libc/ft_strchr.c \
	srcs/libc/ft_strdup.c \
	srcs/libc/ft_striteri.c \
	srcs/libc/ft_strjoin.c \
	srcs/libc/ft_strlcat.c \
	srcs/libc/ft_strlcpy.c \
	srcs/libc/ft_strlen.c \
	srcs/libc/ft_strmapi.c \
	srcs/libc/ft_strncmp.c \
	srcs/libc/ft_strnstr.c \
	srcs/libc/ft_strrchr.c \
	srcs/libc/ft_strtrim.c \
	srcs/libc/ft_substr.c \
	srcs/libc/ft_tolower.c \
	srcs/libc/ft_toupper.c \
	srcs/gnl/get_next_line.c \
	srcs/printf/srcs/ft_print_adress.c \
	srcs/printf/srcs/ft_printf.c \
	srcs/printf/srcs/ft_putchar.c \
	srcs/printf/srcs/ft_putnbr_base.c \
	srcs/printf/srcs/ft_putnbr.c \
	srcs/printf/srcs/ft_putnbr_unsigned.c \
	srcs/printf/srcs/ft_putstr.c

OBJS = $(SRCS:srcs/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@mkdir -p lib
	@$(AR) $(NAME) $(OBJS)

obj/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
