# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maltun <maltun@student.42istanbul.com.t    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 01:54:55 by maltun            #+#    #+#              #
#    Updated: 2023/09/20 03:13:34 by maltun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

PHILO_SRC = philo.c philo_utils.c

OBJ=$(PHILO_SRC:.c=.o)

RED=\033[31m
YELLOW=\033[33m
GREEN=\033[32m
CYAN=\033[36m
BLUE=\033[34m
MAGENTA=\033[35m
RESET=\033[0m

all: title $(NAME)
	@echo "$(GREEN)****** Philosophers Compiled Succesfuly ******"

title:
	@clear
	@echo "$(RED)    ____  __    _ __                       __                  ";
	@echo "   / __ \/ /_  (_) /___  _________  ____  / /_  ___  __________";
	@echo "  / /_/ / __ \/ / / __ \/ ___/ __ \/ __ \/ __ \/ _ \/ ___/ ___/";
	@echo " / ____/ / / / / / /_/ (__  ) /_/ / /_/ / / / /  __/ /  (__  ) ";
	@echo "/_/   /_/ /_/_/_/\____/____/\____/ .___/_/ /_/\___/_/  /____/  ";
	@echo "                                /_/                            $(CYAN)By maltun$(RESET)";
	@echo "";
	@echo "";

	
$(NAME): $(OBJ) 
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

.c.o:
	@$(CC) -c $(CFLAGS) $<

clean: title
	@rm -rf $(OBJ)
	@echo "$(GREEN)****** Cleaned ******"

fclean: clean
	@rm -f philo

re: fclean all

.PHONY: all clean fclean re