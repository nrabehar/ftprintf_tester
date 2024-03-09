LIBFTPRINTF_DIR = /home/nekena/othercode/ft_printf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a
LIBFTPRINTF_HEADER_DIR = $(LIBFTPRINTF_DIR)/header
LIBFTPRINTF_HEADER = $(LIBFTPRINTF_HEADER_DIR)/ft_printf.h

SRCS = test_list.c \
	helper.c \
	tester.c \
	tests.c
OBJ_DIR = objs

NAME = tester

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all : $(NAME)
	@echo "compilation completed."

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c
	@echo "compiling..."
	@gcc -Wall -Wextra -Werror -c $< -o $(addprefix $(OBJ_DIR)/, $(<:.c=.o))
	@clear

$(NAME) : $(LIBFTPRINTF) $(OBJ_DIR) $(OBJS)
	@gcc -Wall -Wextra -Werror -I$(LIBFTPRINTF_HEADER_DIR) -L$(LIBFTPRINTF_DIR) $(OBJS) -o $(NAME) -lftprintf
	clear

${LIBFTPRINTF}:
	@echo "compiling..."
	@make -C ${LIBFTPRINTF_DIR}
	@clear

$(HEADER):
	cp $(LIBFTPRINTF_HEADER) $(HEADER)

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

.PHONY : clean fclean	all