CC := gcc
CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := libft
LIBFT_ARCHIVE := $(LIBFT_PATH)/libft.a
MLX_PATH := minilibx
MLX_ARCHIVE := $(MLX_PATH)/libmlx.a
MLX_FLAGS := -L$(MLX_PATH) -lmlx -L/usr/X11/lib -lXext -lX11 -lm -lbsd

SRC := main.c accessibility.c game_logic.c graphics.c \
       keyboard_controls.c map_utils.c parse_map.c validate_map.c \
       move_player.c
NAME := so_long
HEADER := so_long.h

GREEN := \033[0;32m
YELLOW := \033[0;33m
RESET := \033[0m

all: $(NAME)

$(NAME): $(SRC) $(LIBFT_ARCHIVE) $(MLX_ARCHIVE) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(SRC) -I$(LIBFT_PATH) -I$(MLX_PATH) \
	-L$(LIBFT_PATH) -lft $(MLX_FLAGS)
	@echo "$(GREEN)So_long compiled successfully.$(RESET)"

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT_PATH)
	@echo "$(GREEN)Libft compiled successfully.$(RESET)"

$(MLX_ARCHIVE):
	$(MAKE) -C $(MLX_PATH)
	@echo "$(GREEN)MiniLibX compiled successfully.$(RESET)"

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	@echo "$(YELLOW)Cleaned object files.$(RESET)"

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	@echo "$(YELLOW)Cleaned all files.$(RESET)"

re: fclean all

.PHONY: all clean fclean re