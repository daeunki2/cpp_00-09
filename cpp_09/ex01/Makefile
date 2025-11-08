# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/22 10:54:57 by daeunki2          #+#    #+#              #
#    Updated: 2025/11/08 15:51:35 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Text colors
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# Bold text colors
BOLD_BLACK = \033[1;30m
BOLD_RED = \033[1;31m
BOLD_GREEN = \033[1;32m
BOLD_YELLOW = \033[1;33m
BOLD_BLUE = \033[1;34m
BOLD_MAGENTA = \033[1;35m
BOLD_CYAN = \033[1;36m
BOLD_WHITE = \033[1;37m

# Reset color
RESET = \033[0m

NAME = RPN
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INC_DIR)

OBJ_DIR = obj
SRC_DIR = src
INC_DIR = inc

SRCS = src/main.cpp \
        src/RPN.cpp \
        src/Error.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_DIR) $(OBJS)
	@echo "Building $(NAME) 🛠️"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(BOLD_GREEN)---------------------------------------------------------------------------------------------$(RESET)"
	@echo "$(BOLD_GREEN)✅ Build Complete! $(NAME) executable created. $(RESET)"
	@echo "$(CYAN)Usage: $(RESET)./$(NAME) \"<RPN expression>\""
	@echo "$(CYAN)Valid Tokens: $(RESET)"
	@echo "  $(BOLD_YELLOW)Operands (Numbers):$(RESET) Single-digit integers with out plus sign or plus sign $(BOLD_WHITE)0-9$(RESET)."
	@echo "  $(BOLD_YELLOW)Operators:$(RESET) $(BOLD_WHITE)+ - * /$(RESET)"
	@echo "$(BOLD_GREEN)--------------------------------------------------------------------------------------------$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files 🧹"
	@rm -rf $(OBJ_DIR)
	@echo "cleaning ✅"

fclean: clean
	@echo "Cleaning Executable 🧹"
	@rm -f $(NAME)
	@echo "fclean ✅"

re: fclean all

.PHONY: all clean fclean re