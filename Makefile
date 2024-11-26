NAME			= philosophers

# Directories
HEADER			= -Isrc
SRC_DIR			= ./src/
OBJ_DIR			= ./obj/

# Compiler and CFlags
CC				= cc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -f

# Source Files
SRCS			= $(SRC_DIR)actions.c $(SRC_DIR)alive.c $(SRC_DIR)av_allocation.c $(SRC_DIR)data.c $(SRC_DIR)error_exit.c \
				$(SRC_DIR)philo_utils.c $(SRC_DIR)philo.c $(SRC_DIR)threads_utils.c

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 			= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build
all: 			$(NAME)
				@echo "Philosophers - All set"

$(NAME): 		$(OBJ)
				@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
				@echo "Philosophers - Object files created"
				@echo "Philosophers - Executable file created"

# Compile object files from source files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

# Clean
clean:
				@$(RM) -r $(OBJ_DIR)
				@echo "Philosophers - Object files deleted"

fclean: 		clean
				@$(RM) $(NAME)
				@echo "Philosophers - Executable file deleted"
				@echo "Philosophers - All clean"

re: 			fclean all

# Phony targets represent actions not files
.PHONY: 		all clean fclean re
