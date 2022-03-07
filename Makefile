## general variables -----------------------------------------------------------
CC				=	gcc -g
CFLAGS			=	-Wall -Wextra -Werror
FSAN			=	-fsanitize=address
RM				=	rm -rf
OS				=	$(shell uname)

## other variables -------------------------------------------------------------
LIBFT_FLAGS		=	-I libft

ifeq ($(OS), Linux)
	MLX_FLAGS	=	-L mlx -l mlx -L /usr/lib -l Xext -l X11 -l m
else
	MLX_FLAGS	=	-L mlx -l mlx -framework OpenGL -framework AppKit
endif

## program name ----------------------------------------------------------------
NAME			=	so_long
BONUS			=	so_long_bonus
LEAK_CHECK		=	so_long_leak_check

## libraries and sources -------------------------------------------------------
LIBFT_A			=	libft.a
LIBFT_DIR		=	libft

ifeq ($(OS), Linux)
LIBMLX_A		=	libmlx.a
LIBMLX_DIR		=	mlx
endif

SRCS_DIR		=	srcs/basic
BONUS_SRCS_DIR	=	srcs/bonus

INCS_DIR		=	incs

BONUS_INCS_DIR	=	bonus_incs

SRCS			=	so_long.c \
					check_argument.c \
					get_map.c \
					check_map.c \
					display.c \
					init_imgs.c \
					events.c \
					error.c \
					free_imgs.c \
					free_so_long.c \

BONUS_SRCS		=	so_long_bonus.c \
					events_bonus.c \
					check_argument.c \
					get_map.c \
					check_map.c \
					display_bonus.c \
					init_imgs.c \
					print_score.c \
					error.c \
					free_imgs.c \
					free_so_long.c \

ifeq ($(OS), Linux)
	SRCS		+=	linux_utils.c
	BONUS_SRCS	+=	linux_utils_bonus.c
else
	SRCS		+=	mac_utils.c
	BONUS_SRCS	+=	mac_utils_bonus.c
endif

## rules to make objects -------------------------------------------------------
OBJS			=	$(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

BONUS_OBJS		=	$(addprefix $(BONUS_SRCS_DIR)/, $(BONUS_SRCS:.c=.o))

%.o				:	%.c $(LIBFT_A)
					$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

$(NAME)			:	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
					$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(LIBFT_FLAGS) $(MLX_FLAGS)

$(BONUS)		:	$(BONUS_OBJS) $(LIBFT_A) $(LIBMLX_A)
					$(CC) -o $@ $(BONUS_OBJS) -I $(INCS_DIR) $(LIBFT_A) $(LIBFT_FLAGS) $(MLX_FLAGS)

$(LEAK_CHECK)	:	$(OBJS) $(LIBFT_A) $(LIBMLX_A)
					$(CC) -o $@ $(OBJS) -I $(INCS_DIR) $(LIBFT_A) $(LIBFT_FLAGS) $(MLX_FLAGS) $(FSAN)

$(LIBFT_A)		:
					make -C $(LIBFT_DIR) $(LIBFT_FLAGS)
					mv $(LIBFT_DIR)/$(LIBFT_A) .

$(LIBMLX_A)		:
					make -C $(LIBMLX_DIR)

## rules -----------------------------------------------------------------------
all				:	$(NAME)

bonus			:	$(BONUS)

leak_check		:	$(LEAK_CHECK)

ifeq ($(OS), Linux)
clean			:
					$(RM) $(OBJS) $(LIBFT_A) $(LIBMLX_A)
					$(RM) $(BONUS_OBJS) $(LIBFT_A) $(LIBMLX_A)
					make clean -C $(LIBFT_DIR)
					make clean -C $(LIBMLX_DIR)
else
clean			:
					$(RM) $(OBJS) $(LIBFT_A)
					$(RM) $(BONUS_OBJS) $(LIBFT_A)
					make clean -C $(LIBFT_DIR)
endif


fclean			:	clean
					$(RM) $(NAME) $(LEAK_CHECK) $(BONUS)
					make fclean -C $(LIBFT_DIR)

re				:	fclean all

## phony, not real -------------------------------------------------------------
.PHONY			:	all bonus leak_check clean fclean re
