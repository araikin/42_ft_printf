NAME		:= 	libftprintf.a
FLAGS		:=	-Wall -Wextra -Werror
F_N			:=	ft_printf parse_format verify_params set_params helper_func \
				math_func csp_specifier di_specifier ouxx_specifier \
				f_specifier
SRC			:=	$(addprefix sources/, $(addsuffix .c, $(F_N)))
OBJ			:=	$(addprefix objects/, $(addsuffix .o, $(F_N)))
INCL		:=	includes

LIB			:=	libft
LIB_LINK	:=	-L $(LIB) -l ft

.PHONY:	all clean fclean re

all	: $(NAME)

objects/%.o : sources/%.c
	@/bin/mkdir -p objects
	@gcc $(FLAGS) -I $(INCL) -c $< -o $@ -g

$(NAME)	: $(OBJ)
	@make -C $(LIB)
	@ar rc $(NAME) $(OBJ) libft/*.o
	@ranlib $(NAME)
	
clean:
	@/bin/rm -rf objects
	@make -C libft clean

fclean: clean
	@/bin/rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
