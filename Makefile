# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pde-bakk <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/02 17:36:51 by pde-bakk       #+#    #+#                 #
#    Updated: 2019/12/24 14:33:32 by pde-bakk      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRC = minirt.c objects.c

OBJ = $(SRC:.c=.o)

HEADER = minirt.h

FLAGS = -Wall -Werror -Wextra

MAGIC = -I minilibx_mms_20191025_beta -L minilibx_mms_20191025_beta -lmlx -framework OpenGL -framework AppKit libmlx.dylib

# COLORS
PINK = \x1b[35;01m
BLUE = \x1b[34;01m
YELLOW = \x1b[33;01m
GREEN = \x1b[32;01m
RED = \x1b[31;01m
WHITE = \x1b[31;37m
RESET = \x1b[0m


all: $(NAME)

$(NAME):
	@echo "$(YELLOW)Linking the library"
	cp minilibx_mms_20191025_beta/libmlx.dylib libmlx.dylib
	gcc -c $(FLAGS) $(HEADER) $(SRC)
	ar -rc $(NAME) $(OBJ)
	@echo "$(GREEN)Done!"

clean:
	@echo "$(RED)Cleaning..."
	/bin/rm -f *.o *~ *.gch

fclean: clean
	/bin/rm -f $(NAME) libmlx.dylib

re: fclean all

bonus: re
	@echo "$(PINK)Linking bonus files"

run: re
	gcc $(MAGIC) miniRT
	./a.out
