NAME	= fdf

# src / obj files
SRC		= main.c \
          	initialization.c \
          	color.c \
          	line_drawing.c \
          	get_points.c \
          	calculation_of_required_values.c \
          	program_control.c \
          	program_control_2.c \
          	g1_read_check.c \
          	g2_ft_w_count.c \
          	g3_ft_new_t_p.c \
          	g4_fill_t_p_karta.c \
          	g5_ft_atoi_16_10.c \
          	g6_menu.c \
          	clean_up.c \
          	rotate_and_projection.c \
          	types_of_coloration.c \
          	program_control_palitra.c \
          	program_control_3.c \
          	palitra.c \
          	g7_mouse_press_center.c \
          	g8_mouse_rotate.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
#CFLAGS	= -g

# mlx library
MLX		= ./miniLibX/
MLX_LIB	= $(addprefix $(MLX),mlx.a)
MLX_INC	= -I ./miniLibX
MLX_LNK	= -L ./miniLibX -l mlx -framework OpenGL -framework AppKit

# ft library
FT		= ./libftprintf/
FT_LIB	= $(addprefix $(FT),libftprintf.a)
FT_INC	= -I ./libftprintf/includes -I ./libftprintf/srcs/libft/includes/
FT_LNK	= ./libftprintf/libftprintf.a

# directories
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	make -C $(FT)

$(MLX_LIB):
	make -C $(MLX)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(MLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(FT) fclean

re: fclean all