## COLORS FORMAT
PENDING	= \x1b[0;37;40m
OK		= \x1b[0;97;42m
ERROR	= \x1b[0;37;41
RESET	= \x1b[0;0;0m
INFO	= \x1b[0;30;103m


## SETTINGS
NAME	= shellinho
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
#CFLAGS	+= -pedantic
DFLAGS	= -MMD -MP
FFLAGS	= -fsanitize=address
IFLAGS	= -Iinclude
LFLAGS	= -lreadline
DEBUG	= -g3
FLAGS	= $(CFLAGS) $(DFLAGS) $(IFLAGS) $(LFLAGS)
#FLAGS	+= $(FFLAGS)
FLAGS	+= $(DEBUG)

## DIRECTORIES
BUI_DIR	= build/
EXA_DIR	= examples/
EXT_DIR	= external/
XTR_DIR	= extras/
INC_DIR	= include/
LIB_DIR	= libs/
SRC_DIR	= src/
TES_DIR	= tests/

## SOURCES
SRC_FIL	= 	main \
			builtins \
			exit \
			interpreter_loop \
			lexing \
			prompt \
			utils1
SRC		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FIL)))
OBJ		= $(addprefix $(BUI_DIR), $(addsuffix .o, $(SRC_FIL)))

OBJF	= .cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo -en "$(PENDING)Linking $(NAME)...			"
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo -e "$(OK)    OK    $(RESET)"
	@echo -e "$(OK)	  $(NAME) is born! :D			  $(RESET)"

$(BUI_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo -en "$(PENDING)Compiling $<..			"
	@$(CC) $(FLAGS) -c $< -o $@ || (echo -e "$(ERROR)    Error    $(RESET)"; exit 1)
	@echo -e "$(OK)    OK    $(RESET)"

$(OBJF):
	@echo -en "$(PENDING)Creating build directory		"
	@mkdir -p $(BUI_DIR)
	@mkdir -p $(BUI_DIR)
	@touch $(OBJF)
	@echo -e "$(OK)    OK    $(RESET)"

clean:
	rm -rf $(BUI_DIR) $(OBJF)
	@echo -en "$(PENDING)Removing build files...		"
	@echo -e "$(OK)    OK    $(RESET)"

fclean: clean
	@echo -en "$(PENDING)Removing $(NAME)...		"
	@rm -f $(NAME)
	@echo -e "$(OK)    OK    $(RESET)"

re:
	@$(MAKE) --no-print-directory fclean
	@echo -e "$(INFO)	  Making $(NAME) again	  $(RESET)"
	@$(MAKE) --no-print-directory all

v :
	@valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline_supp.supp ./shellinho

-include $(OBJ:.o=.d)

>PHONY: all clean fclean re
