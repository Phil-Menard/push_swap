CC = cc
CFLAGS = -Wall -Werror -Wextra
DEBUG_FLAGS = -g
NAME = push_swap
SRC = push_swap.c \
	init_list.c \
	instructions.c \
	array_handler.c \
	optimisation.c

OBJ = $(SRC:.c=.o)

LIBFT_PATH = libft
FT_PRINTF_PATH = ft_printf

LIBFT = $(LIBFT_PATH)/libft.a
FT_PRINTF = $(FT_PRINTF_PATH)/libftprintf.a

# Cible principale
all: $(NAME)

# Construction de l'exécutable en respectant les dépendances
$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

# Compilation des bibliothèques externes
$(LIBFT):
	make -C $(LIBFT_PATH) bonus

$(FT_PRINTF):
	make -C $(FT_PRINTF_PATH)

# Compilation des fichiers objets
%.o: %.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) -I$(LIBFT_PATH) -I$(FT_PRINTF_PATH) -c $< -o $@

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean
	make -C $(FT_PRINTF_PATH) clean

# Nettoyage complet
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean
	make -C $(FT_PRINTF_PATH) fclean

# Rebuild complet
re: fclean all
