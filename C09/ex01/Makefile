# Makefile for libft.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directories
SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = $(SRC_DIR)

# Source and object files
SRCS = $(SRC_DIR)/ft_putchar.c $(SRC_DIR)/ft_swap.c \
       $(SRC_DIR)/ft_putstr.c $(SRC_DIR)/ft_strlen.c \
       $(SRC_DIR)/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

# Library name
LIB = libft.a

# Default rule
all: $(LIB)

# Rule to create the library
$(LIB): $(OBJS)
	@echo "Creating $@"
	@ar rcs $@ $^

# Compile source files into object files
%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

# Clean temporary files
clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)

# Clean and remove the library
fclean: clean
	@echo "Removing library $(LIB)..."
	@rm -f $(LIB)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re

