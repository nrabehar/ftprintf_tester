FT_PRINTF_DIR = ..
LIBFTPRINTF = $(FT_PRINTF_DIR)/libftprintf.a
FT_PRINTF_HEADER_DIR = $(FT_PRINTF_DIR)

HELPER_DIR = $(shell pwd)/helper
HELPER = $(HELPER_DIR)/libhelper.a

SRCS = tester.c \
	signal_handler.c \
	sets.c \

OBJ_DIR = objs

NAME = tester

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

CC = gcc

CFLAGS = 

all : $(NAME)
	@echo ""

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $(addprefix $(OBJ_DIR)/, $(<:.c=.o))

$(NAME) : $(LIBFTPRINTF) $(HELPER) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) -I$(FT_PRINTF_HEADER_DIR) -L$(FT_PRINTF_DIR) -L$(HELPER_DIR) $(OBJS) -o $(NAME) -lftprintf -lhelper

${LIBFTPRINTF}:
	@make -C ${FT_PRINTF_DIR} --no-print-directory

${HELPER}:
	@make -C ${HELPER_DIR} --no-print-directory

clean :
	@rm $(LIBFTPRINTF)
	@rm $(HELPER)
	@rm -f $(NAME)

fclean :
	@make fclean -C ${FT_PRINTF_DIR} --no-print-directory
	@make fclean -C ${HELPER_DIR} --no-print-directory
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)

re : clean all

.PHONY : clean fclean	all re
