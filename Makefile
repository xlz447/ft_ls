NAME	=	ft_ls

NOC		=	\033[0m
GREEN	=	\033[0;32m
BLUE	=	\033[0;34m
RED		=	\033[0;31m

SRC		= main.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
C_FLAGS = -Wall -Wextra -Werror -g

FT		= ./libftprintf/
FT_LIB	= $(addprefix $(FT),libftprintf.a)
FT_INC	= -I ./libftprintf
FT_LNK	= -L ./libftprintf -l ftprintf

SRCDIR	= ./srcs/
INCDIR	= ./includes/
OBJDIR	= ./objs/

all: obj $(FT_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		@$(CC) $(C_FLAGS) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
		@make -C $(FT)

$(MLX_LIB):
		@make -C $(MLX)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(FT_LNK) $(THR_LNK) -lm -o $(NAME)
		@echo "$(GREEN)FT_LS       ✓ ft_ls ready$(NOC)"

clean:
		@rm -rf $(OBJDIR)
		@make -C $(FT) clean
		@echo "$(BLUE)FT_LS       ✓ Removed .o files$(NOC)"

fclean: clean
		@rm -f ./libftprintf/libftprintf.a
		@echo "$(RED)LIBFTPRINTF ✓ Removed libftprintf.a$(NOC)"
		@rm -rf $(NAME)
		@echo "$(RED)FT_LS       ✓ Removed ft_ls executable$(NOC)"

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
