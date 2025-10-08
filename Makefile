NAME=webserv

# Directories
SRC_DIR=srcs/
INC_DIR=includes/
OBJ_DIR=objs/

# Compiling options
CC=g++
CCFLAGS= -Wall -Wextra -Werror --std=c++98 -g -gdwarf-4

# Sources
SRCS= srcs/main.cpp \
	  srcs/parser.cpp

# Rule to create list of OBJS
OBJ = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Rule to compile .cpp in .o
$(OBJ_DIR)/%.o:$(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create a $(NAME) executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

# General rules
.PHONY: all
all: $(NAME)

.PHONY: clean
clean:
	rm -rf $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	rm -rf $(NAME)

.PHONY: re
re: fclean all
