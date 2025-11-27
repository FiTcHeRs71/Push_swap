# File Name
NAME = push_swap
BONUS_NAME = checker

# Directories
SRCDIR = srcs
INCDIR = include
OBJDIR = object
OBJDIR_BONUS = object_bonus
LIBFTDIR = libft
BONUSDIR = checker_bonus

# Source files
SRCS = $(addprefix $(SRCDIR)/, \
change_stack.c chunk_split.c chunk_utils.c error.c initz_utils.c input_validation.c \
op_utils.c ft_parsing.c push_op.c reverse_rotate_op.c rotate_op.c sort_chunk.c \
sort_optimize.c sort_three.c split_utils.c stack_initz.c ft_execute.c swap_op.c)

MAIN = $(SRCDIR)/main.c

# Bonus source files
SRCS_BONUS = $(addprefix $(BONUSDIR)/, \
checker_bonus.c checker_utils_bonus.c)

# Object files 
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJ_MAIN = $(OBJDIR)/main.o

OBJS_BONUS_SHARED = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR_BONUS)/%.o)
OBJS_BONUS = $(SRCS_BONUS:$(BONUSDIR)/%.c=$(OBJDIR_BONUS)/%.o)

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

$(OBJDIR_BONUS):
	@mkdir -p $(OBJDIR_BONUS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR_BONUS)/%.o: $(SRCDIR)/%.c | $(OBJDIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJDIR_BONUS)/%.o: $(BONUSDIR)/%.c | $(OBJDIR_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS) $(OBJ_MAIN)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJ_MAIN) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(OBJS_BONUS_SHARED) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS_SHARED) $(OBJS_BONUS) $(LIBFT) -o $(BONUS_NAME)

clean:
	@$(RM) $(OBJDIR) $(OBJDIR_BONUS)
	@make -C $(LIBFTDIR) clean

fclean: clean
	@$(RM) $(NAME) $(BONUS_NAME)
	@make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus