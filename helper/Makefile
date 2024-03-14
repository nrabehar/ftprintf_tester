NAME = libhelper.a

SRCS = file.c \
	string.c \
	utils.c \
	data.c \
	validator.c

OBJ_DIR = objs
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

$(OBJ_DIR)/%.o : %.c
	$(CC) $(CFLAGS) -I . -c $< -o $(addprefix $(OBJ_DIR)/, $(<:.c=.o))

$(NAME): $(OBJ_DIR) $(OBJS)
	ar -rsc $(NAME) $(OBJS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

all : $(NAME)

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : re fclean clean all