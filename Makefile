NAME	:= so_long

CC      := cc
CFLAGS	:= -Wall -Wextra -Werror

LIBMLX	:= ./MLX42
MLX_REPO := https://github.com/codam-coding-college/MLX42.git
PRINTF_DIR := ft_printf

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	:= ./src/so_long.c ./src/map.c ./src/render_map.c ./src/utils.c \
		./src/valid_path.c ./src/validate_map.c ./src/texture_load_check.c \
		./src/key_press.c ./src/free_map.c ./src/ft_split.c \
		./src/design_map.c 

OBJS	:= ${SRCS:.c=.o}
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: libmlx $(NAME) $(PRINTF)
	@echo "Nothing to do, everything is up to date."

libmlx:
	@if [ ! -d "$(LIBMLX)" ]; then \
		echo "Cloning MLX42..."; \
		git clone $(MLX_REPO) $(LIBMLX); \
	fi
	@if [ ! -f "$(LIBMLX)/build/libmlx42.a" ]; then \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
	fi

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS) $(PRINTF)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(PRINTF) -o $(NAME)

clean:
	@rm -rf $(OBJS) 
	@make -C $(PRINTF_DIR) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)
	@make -C $(PRINTF_DIR) fclean
	@rm -rf $(LIBMLX)

re: fclean all

.PHONY: all clean fclean re libmlx
