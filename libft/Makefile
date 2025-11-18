# File name
NAME = libft.a

# Directories
SRCDIR = srcs
INCDIR = include
OBJDIR = obj

# Source files
SRCS = $(addprefix $(SRCDIR)/, \
	ft_printf.c parse.c ft_print_char.c 							\
	ft_print_int.c ft_print_void.c ft_tolower.c ft_toupper.c 		\
	ft_isprint.c ft_isascii.c ft_isalnum.c ft_isdigit.c 			\
	ft_isalpha.c ft_atoi.c ft_strlen.c ft_strlcat.c ft_strncmp.c	\
	ft_strdup.c ft_calloc.c ft_memcpy.c ft_strchr.c ft_memset.c		\
	ft_strrchr.c ft_strnstr.c ft_bzero.c ft_memchr.c ft_memcmp.c	\
	ft_memmove.c ft_strlcpy.c ft_itoa.c ft_strjoin.c ft_split.c		\
	ft_striteri.c ft_strmapi.c ft_substr.c ft_strtrim.c ft_lstmap.c	\
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c	\
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c			\
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c)

# Object files
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Progress tracking
TOTAL_FILES := $(words $(SRCS))
CURRENT_FILE = 0

# Chromatic gradient colors
C1 = \033[38;5;196m
C2 = \033[38;5;202m
C3 = \033[38;5;208m
C4 = \033[38;5;214m
C5 = \033[38;5;220m
C6 = \033[38;5;226m
C7 = \033[38;5;190m
C8 = \033[38;5;154m
C9 = \033[38;5;118m
C10 = \033[38;5;82m
C11 = \033[38;5;46m
C12 = \033[38;5;51m
C13 = \033[38;5;45m
C14 = \033[38;5;39m
C15 = \033[38;5;33m
C16 = \033[38;5;27m
C17 = \033[38;5;21m
C18 = \033[38;5;57m
C19 = \033[38;5;93m
C20 = \033[38;5;129m
RESET = \033[0m
GREEN = \033[0;32m
CYAN = \033[0;36m
YELLOW = \033[0;33m
BOLD = \033[1m

CC = gcc
RM = rm -rf
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I$(INCDIR)

all: $(NAME)
	@echo ""
	@echo "$(GREEN) ▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄$(RESET)"
	@echo "$(GREEN)█  ✓✓ $(C2)C$(C3)o$(C4)m$(C5)p$(C6)i$(C7)l$(C8)a$(C9)t$(C10)i$(C11)o$(C12)n $(C13)s$(C14)u$(C15)c$(C16)c$(C17)e$(C18)s$(C19)s$(C20)f$(C1)u$(C2)l$(C3): $(C5)l$(C7)i$(C9)b$(C11)f$(C13)t$(C15).$(C17)a $(GREEN)✓✓  █$(RESET)"
	@echo "$(GREEN) ▀▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▀$(RESET)"
	@echo ""

# Creating the obj folder
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compilation of object files with progress bar
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@$(eval CURRENT_FILE=$(shell echo $$(($(CURRENT_FILE)+1))))
	@$(eval PERCENT=$(shell echo $$(($(CURRENT_FILE)*100/$(TOTAL_FILES)))))
	@$(eval PROGRESS=$(shell echo $$(($(CURRENT_FILE)*40/$(TOTAL_FILES)))))
	@printf "$(CYAN)⚙ Compiling [$(YELLOW)"
	@printf "%0.s█" $$(seq 1 $(PROGRESS))
	@printf "%0.s " $$(seq $(PROGRESS) 39)
	@printf "$(CYAN)] $(BOLD)%3d%%$(RESET) $(CYAN)%-50s$(RESET)\r" $(PERCENT) "$<"
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	@if [ $(CURRENT_FILE) -eq $(TOTAL_FILES) ]; then \
		printf "\r$(CYAN)⚙ Compiling [$(GREEN)"; \
		printf "%0.s█" $$(seq 1 40); \
		printf "$(CYAN)] $(BOLD)100%%$(RESET) $(GREEN)✓ All files compiled!                    $(RESET)\n"; \
	fi

# Creating the static library without relink
$(NAME): $(OBJS)
	@if [ ! -f $(NAME) ]; then \
		echo "$(CYAN)⚙ Creating archive $(NAME)...$(RESET)"; \
		$(AR) $(NAME) $(OBJS); \
	else \
		echo "$(GREEN)✓ $(NAME) is already up to date$(RESET)"; \
	fi

clean:
	@echo "$(CYAN)⚙ Removing object files...$(RESET)"
	@$(RM) $(OBJDIR)
	@echo "$(GREEN)✓ Clean successful$(RESET)"

fclean: clean
	@echo "$(CYAN)⚙ Removing $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ Fclean successful$(RESET)"

re: fclean all

.PHONY: all clean fclean re