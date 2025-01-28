NAME	= libft.a
CC	= cc
CFLAGS	= -Wall -Wextra -Werror
AR	= ar
ARFLAGS	= rcs
RM	= rm -rf

SRC	=	ft_atoi ft_bzero			\
		ft_calloc ft_putendl_fd			\
		ft_itoa ft_putchar_fd			\
		ft_putstr_fd ft_striteri		\
		ft_memchr ft_memcmp			\
		ft_memcpy ft_isalnum			\
		ft_isalpha ft_isascii			\
		ft_isdigit ft_isprint			\
		ft_memmove ft_memset			\
		ft_split ft_strchr			\
		ft_strdup ft_strjoin			\
		ft_strlcat ft_strlcpy			\
		ft_strlen ft_strmapi			\
		ft_strncmp ft_strnstr			\
		ft_strrchr ft_strtrim			\
		ft_substr ft_tolower			\
		ft_toupper ft_putnbr_fd			\
		ft_lstadd_back ft_lstadd_front		\
		ft_lstclear ft_lstdelone		\
		ft_lstiter ft_lstlast			\
		ft_lstsize ft_lstnew			\
		ft_lstmap ft_realloc			\
		ft_farray ft_printf			\
		ft_putchar ft_putnbr			\
		ft_putstr ft_putuns			\
		ft_putvoid ft_putitox			\
		get_next_line get_next_line_utils	\

SRCS	= $(addsuffix .c, $(SRC))
OBJ_DIR	= obj
OBJS	= $(addprefix $(OBJ_DIR)/, $(SRC:=.o))


all:	$(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
