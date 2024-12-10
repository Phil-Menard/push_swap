CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap.a
SRC = push_swap.c \
	init_list.c \

OBJ = $(SRC:.c=.o)

LIBFT_PATH = libft
FT_PRINTF_PATH = ft_printf

# Ajouter les règles pour libft et ft_printf
LIBFT = $(LIBFT_PATH)/libft.a
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

all: $(NAME)

# Construire le projet avec les bibliothèques
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	ar -rv $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)

# Inclure les fichiers objets dans libft et ft_printf
$(LIBFT):
	make -C $(LIBFT_PATH) bonus

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_PATH) -I$(FT_PRINTF_PATH) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(FT_PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(FT_PRINTF_PATH) fclean

re: fclean all
