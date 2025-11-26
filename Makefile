# File Name
NAME = push_swap

# Directories
SRCDIR = srcs
INCDIR = include
OBJDIR = object
LIBFTDIR = libft
BONUSDIR = checker_bonus

# Source files
SRCS = $(addprefix $(SRCDIR)/, \
change_stack.c chunk_split.c chunk_utils.c error.c input_validation.c \
op_utils.c parsing.c push_op.c reverse_rotate_op.c rotate_op.c sort_chunk.c \
sort_optimize.c sort_three.c split_utils.c stack_initz.c swap_op.c print_stack.c)

MAIN = $(addprefix $(SRCDIR)/, main.c)

# Object files 
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Libft
LIBFT = $(LIBFTDIR)/libft.a

# Flags
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I$(INCDIR) -I$(LIBFTDIR)/include

all: $(NAME)

# Creating the obj folder
$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus :

clean:
	@$(RM) $(OBJDIR)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus