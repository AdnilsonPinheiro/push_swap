# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adpinhei <adpinhei@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/11 17:06:56 by adpinhei          #+#    #+#              #
#    Updated: 2025/07/01 20:30:18 by adpinhei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET := push_swap

CC := cc

CFLAGS := -Wall -Wextra -Werror -g

BUILD_DIR := build

# Source Groups
MAIN_SRCS := main.c

LIST_SRCS := list/ft_makelst.c list/ft_firstnode.c \
			list/ft_lstsize.c

PARSING_SRCS := parsing/ft_rank.c parsing/ft_atol.c

CHECKER_SRCS := checkers/ft_repetition.c checkers/ft_printlst.c \
				checkers/ft_isdone.c checkers/ft_mid.c

ERROR_SRCS := error/ft_clearlst.c

OPERATIONS_SRCS := operations/ft_sort.c operations/ft_move_a.c \
				operations/ft_rot.c operations/ft_revrot.c \
				operations/ft_push.c operations/ft_move_b.c \

OUTPUT_SRCS := output/ft_putstr.c

# Combine all source files
SRC_FILES := $(MAIN_SRCS) $(PARSING_SRCS) $(CHECKER_SRCS) \
			$(OPERATIONS_SRCS) $(ERROR_SRCS) $(LIST_SRCS) \
			$(OUTPUT_SRCS)

OBJ_FILES := $(patsubst %.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

HEADER := push_swap.h

.PHONY: all clean fclean re valgrind test norm

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(YELLOW)Compiled Program$(RESET) $(TARGET)"

$(BUILD_DIR)/%.o: %.c $(HEADER) | $(BUILD_DIR)
	@echo "$(GREEN)Creating directory: $(RESET)$(dir $@)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

valgrind: $(TARGET)
	@echo "$(YELLOW)Valgrind Report$(RESET)"
	@valgrind --leak-check=full --show-leak-kinds=all \
	--track-origins=yes ./$(TARGET) -48 -12 0 1 5 42 112 -100

test: $(TARGET)
	@if [ -f ./test.sh ]; then \
		echo "$(GREEN)Running tests...$(RESET)"; \
		./test.sh; \
	else \
		echo "$(RED)test.sh not found!$(RESET)"; \
	fi

norm:
	@norminette -R CheckForbiddenSourceHeader

gdb: $(TARGET)
#	@ARGS="$(shell shuf -i 0-1000 -n 10)"; \#
	gdb --tui --args ./$(TARGET) -48 -12 0 1 5 42 112 -100

clean:
	@rm -f $(OBJ_FILES)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@rm -f $(TARGET)
	@echo "$(RED)Removed$(RESET) $(TARGET)"

re: fclean all

RED = \033[1;31m

GREEN = \033[1;32m

YELLOW = \033[1;33m

BLUE = \033[1;34m

RESET = \033[0m
