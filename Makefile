CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./minilibx -g
LFLAGS = -framework AppKit -framework OpenGL -L./minilibx -lmlx
MLX = ./minilibx/libmlx.a
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
GNL_SRCS = $(wildcard gnl/*.c)
GNL_OBJS = $(GNL_SRCS:.c=.o)

NAME = so_long
SRCS = src/close_frame.c src/main_func_checkers.c src/main.c \
		src/map.c src/map2.c src/movement.c src/open_windows_checker.c \
		src/open_windows_checker1.c src/custom_func.c src/valid_path_checker.c src/wall_checker.c
OBJS = $(patsubst src/%.c, obj/%.o, $(SRCS))

NAME2 = so_long_bonus
SRCS2 = bonus/src/close_frame.c bonus/src/main_func_checkers.c bonus/src/main.c \
	bonus/src/map.c bonus/src/map2.c bonus/src/movement.c \
	bonus/src/open_windows_checker.c bonus/src/open_windows_checker1.c \
	bonus/src/custom_func.c bonus/src/valid_path_checker.c bonus/src/wall_checker.c bonus/src/movement1.c
OBJS2 = $(patsubst bonus/src/%.c, bonus/obj/%.o, $(SRCS2))

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
NC = \033[0m

all : $(MLX) $(LIBFT) $(FT_PRINTF) $(NAME)

bonus: $(MLX) $(LIBFT) $(FT_PRINTF)
	@$(MAKE) $(NAME2)

$(MLX):
	@make -C ./minilibx

$(LIBFT):
	@make -C ./libft

$(FT_PRINTF):
	@make -C ./ft_printf

gnl/%.o: gnl/%.c
	@echo "$(RED)Compiling.. GNL$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ -Wno-deprecated-declarations

$(NAME) : $(OBJS) $(GNL_OBJS)
	@echo "$(PURPLE)Building ./so_long project...$(NC)"
	@$(CC) $(OBJS) $(GNL_OBJS) $(LFLAGS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(NAME2): $(OBJS2) $(GNL_OBJS)
	@echo "$(PURPLE)Building ./so_long_bonus project...$(NC)"
	@$(CC) $(OBJS2) $(GNL_OBJS) $(LFLAGS) $(LIBFT) $(FT_PRINTF) -o $(NAME2)

$(OBJS): obj/%.o: src/%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $< -o $@ -Wno-deprecated-declarations

$(OBJS2): bonus/obj/%.o: bonus/src/%.c
	@mkdir -p bonus/obj
	@$(CC) $(CFLAGS) -c $< -o $@ -Wno-deprecated-declarations

clean:
	@rm -rf $(OBJS) $(GNL_OBJS)
	@rm -rf bonus/obj
	@make clean -C ./minilibx
	@make clean -C ./libft
	@make clean -C ./ft_printf

fclean: clean
	@rm -rf $(NAME) $(NAME2)
	@make fclean -C ./libft
	@make fclean -C ./ft_printf

re : fclean all

.PHONY: clean fclean re bonus

norm:
	@norminette src/*.* gnl/*.c ft_printf/src/*.c bonus/src/*.c
