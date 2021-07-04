NAME	= libft.a
FLAGS	= -Wall -Werror -Wextra
CFLAGS	= $(FLAGS) -I.
CC		= gcc
NORMIN	= norminette
SRC		= src/ft_atoi.c \
          src/ft_bzero.c \
          src/ft_calloc.c \
          src/ft_isalnum.c \
          src/ft_isalpha.c \
          src/ft_isascii.c \
          src/ft_isdigit.c \
          src/ft_islower.c \
          src/ft_isnotprint.c \
          src/ft_isprint.c \
          src/ft_isupper.c \
          src/ft_itoa.c \
          src/ft_lstadd_back.c \
          src/ft_lstadd_front.c \
          src/ft_lstclear.c \
          src/ft_lstdelone.c \
          src/ft_lstiter.c \
          src/ft_lstlast.c \
          src/ft_lstmap.c \
          src/ft_lstnew.c \
          src/ft_lstsize.c \
          src/ft_memccpy.c \
          src/ft_memchr.c \
          src/ft_memcmp.c \
          src/ft_memcpy.c \
          src/ft_memmove.c \
          src/ft_memrchr.c \
          src/ft_memrcpy.c \
          src/ft_memset.c \
          src/ft_putchar_fd.c \
          src/ft_putendl_fd.c \
          src/ft_putnbr_fd.c \
          src/ft_putstr_fd.c \
          src/ft_split.c \
          src/ft_strchr.c \
          src/ft_strdup.c \
          src/ft_strjoin.c \
          src/ft_strlcat.c \
          src/ft_strlcpy.c \
          src/ft_strlen.c \
          src/ft_strmapi.c \
          src/ft_strncmp.c \
          src/ft_strnstr.c \
          src/ft_strrchr.c \
          src/ft_strtrim.c \
          src/ft_substr.c \
          src/ft_tolower.c \
          src/ft_toupper.c \
          src/get_next_line.c \
          srcprintf/ft_checktype.c \
          srcprintf/ft_converter.c \
          srcprintf/ft_countnbr_dec.c \
          srcprintf/ft_countnbr_hex.c \
          srcprintf/ft_formattochr.c \
          srcprintf/ft_formattohex.c \
          srcprintf/ft_formattoint.c \
          srcprintf/ft_formattoptr.c \
          srcprintf/ft_formattostr.c \
          srcprintf/ft_printf.c \
          srcprintf/ft_putnbr_dec.c \
          srcprintf/ft_putnbr_hex.c \
          srcprintf/ft_setupflags.c
OBJ		= $(SRC:%.c=%.o)

.PHONY: all clean fclean re norm

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $?
	ranlib $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	$(NORMIN) -R CheckForbiddenSourceHeader $(SRC)
	$(NORMIN) libft.h