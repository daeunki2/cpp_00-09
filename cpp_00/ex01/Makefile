# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/15 09:40:09 by daeunki2          #+#    #+#              #
#    Updated: 2025/07/12 00:07:58 by daeunki2         ###   ########.fr        #
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



NAME = PhoneBook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Utiles.cpp Contact.cpp PhoneBook.cpp
OBJS = PhoneBook.o Utiles.o main.o Contact.o 

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Building $(NAME) 🛠️"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Build Complete! ✅"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files 🧹"
	@rm -f $(OBJS)
	@echo "cleaning ✅"

fclean: clean
	@echo "Cleaning Executable 🧹"
	@rm -f $(NAME)
	@echo "fclean ✅"

re: fclean all

.PHONY: all clean fclean re
