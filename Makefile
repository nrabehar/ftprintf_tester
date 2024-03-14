FT_PRINTF_DIR = /home/nekena/othercode/ft_printf
LIBFTPRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_HEADER_DIR = $(FT_PRINTF_DIR)

HELPER_DIR = $(shell pwd)/helper
HELPER = $(HELPER_DIR)/libhelper.a

SRCS = tester.c \
	ft_error.c \
	sets.c \

OBJ_DIR = objs

NAME = tester

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)
	@echo "compilation completed."

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c
	@echo "compiling..."
	@$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $(<:.c=.o))

$(NAME) : $(LIBFTPRINTF) $(HELPER) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) -I$(FT_PRINTF_HEADER_DIR) -L$(FT_PRINTF_DIR) -L$(HELPER_DIR) $(OBJS) -o $(NAME) -lftprintf -lhelper

${LIBFTPRINTF}:
	@echo "compiling..."
	@make -C ${FT_PRINTF_DIR} --no-print-directory
	@clear

${HELPER}:
	@echo "compiling..."
	@make -C ${HELPER_DIR} --no-print-directory
	@clear

clean :
	@make clean -C ${FT_PRINTF_DIR} --no-print-directory
	@make clean -C ${HELPER_DIR} --no-print-directory
	@rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean -C ${FT_PRINTF_DIR} --no-print-directory
	@make fclean -C ${HELPER_DIR} --no-print-directory
	@rm -f $(NAME)

.PHONY : clean fclean	all