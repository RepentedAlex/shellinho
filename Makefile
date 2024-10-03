## COLORS
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

## BG COLORS
BG_DEF		= \x1b[0;0m
BG_BLACK	= \x1b[0;40m
BG_GREEN	= \x1b[0;42m

## COLORS FORMAT
PENDING	= \x1b[0;37;40m
OK		= \x1b[0;37;42m
ERROR	= \x1b[0;37;41
RESET	= \x1b[0;0;0m


## SETTINGS
NAME	= shellinho
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
#CFLAGS	+= -pedantic
DFLAGS	= -MMD -MP
FFLAGS	= -fsanitize=address
IFLAGS	= -Iinclude
DEBUG	= -g3
FLAGS	= $(CFLAGS) $(DFLAGS) $(IFLAGS)
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
			fadsssd
SRC		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FIL)))
OBJ		= $(addprefix $(BUI_DIR), $(addsuffix .o, $(SRC_FIL)))

OBJF	= .cache_exists

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME) linked successfully! :D"

$(BUI_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
	@echo -en "$(PENDING)Compiling $<$...				"
	@$(CC) $(FLAGS) -c $< $@ || (echo -e "$(ERROR)     Error     $(RESET)"; exit 1)
	@echo -e "$(OK)    OK    $(RESET)"

$(OBJF):
	@echo "Creating build directory"
	@mkdir -p $(BUI_DIR)
	@mkdir -p $(addprefix $(BUI_DIR), $(dir $(SRC)))
	@touch $(OBJF)
	@echo "Build directory created successfully!"

test:
	echo -e "$(BG_BLACK)Test$(BG_DEF)"

clean:
	@rm -rf $(BUI_DIR) $(OBJF)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(OBJ:.o=.d)

>PHONY: all clean fclean re
