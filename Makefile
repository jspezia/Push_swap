CC				=	gcc -O2 -g
FLAGS			=	#-Wall -Wextra -Werror
NAME			=	push_swap
LIB				=	libft/libft.a
LIB_PATH		=	libft/
INCLUDES		=	-I $(LIB_PATH)./includes -I ./includes -I /usr/X11/include
DIR_LIBS		=	/usr/X11/lib
LDFLAGS			=	-L$(DIR_LIBS) -lXext -lX11 -lmlx
SRCS			=	src/main.c									\
					src/parser.c								\
					src/options.c								\
					src/resolve.c								\
					src/check_sort.c							\
					src/print.c									\
					src/swap.c									\
					src/push.c									\
					src/rotate.c								\
					src/reverse.c								\
					src/interactive_mode.c						\
					src/algo_bubble_sort.c						\
					src/algo_fifty_fifty.c						\
					src/up_down.c
SRCS			+=	src/mlx_my_pixel_put_to_image.c				\
					src/mlx_draw_line.c							\
					src/mlx_image.c								\
					src/mlx_draw_ps.c							\
					src/mlx.c
OBJS			=	$(SRCS:src/%.c=obj/%.o)

# COLORS
C_NO			=	"\033[00m"
C_OK			=	"\033[35m"
C_GOOD			=	"\033[32m"
C_ERROR			=	"\033[31m"
C_WARN			=	"\033[33m"

# DBG MESSAGE
SUCCESS			=	$(C_GOOD)SUCCESS$(C_NO)
OK				=	$(C_OK)OK$(C_NO)


all: obj $(NAME)

$(NAME): $(LIB) $(OBJS)
	@$(CC) $(FLAGS) -o $@ $^ $(LDFLAGS) -L $(LIB_PATH) -lft
	@echo "Compiling" [ $(NAME) ] $(SUCCESS)

$(LIB):
	@make -C $(LIB_PATH)

obj:
	@mkdir -p obj

obj/%.o: src/%.c ./includes/push_swap.h
	@$(CC) $(FLAGS) -c -o $@ $< $(INCLUDES)
	@echo "Linking" [ $< ] $(OK)

clean:
	@rm -f $(OBJS)
	@rm -rf obj
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIB_PATH) fclean
	@echo "Delete" [ $(NAME) ] $(OK)

re: fclean all

.PHONY: clean all re fclean

