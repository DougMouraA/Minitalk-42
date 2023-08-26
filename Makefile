NAME := client server

CFLAGS = -Wall -Werror -Wextra
CC = cc
FLAGS = -Wall -Wextra -Werror 

CSRCS = client.c 
SSRCS = server.c

COBJS = $(CSRCS:.c=.o)
SOBJS = $(SSRCS:.c=.o)

CBSRCS = client_bonus.c
SBSRCS = server_bonus.c

CBOBJS = $(CBSRCS:.c=.o)
SBOBJS = $(SBSRCS:.c=.o)

LIBFT = ./libft/libft.a 

all: compile_lib $(COBJS) $(SOBJS)
	@$(CC) $(FLAGS) $(SOBJS) $(LIBFT) -o server
	@$(CC) $(FLAGS) $(COBJS) $(LIBFT) -o client

.c.o:
			@$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): compile_lib $(OBJS) 
	@$(CC) $(FLAGS) $@.o $(LIBFT) -o $@

bonus: compile_lib $(CBOBJS) $(SBOBJS)
	@$(CC) $(FLAGS) $(SBOBJS) $(LIBFT) -o server_bonus
	@$(CC) $(FLAGS) $(CBOBJS) $(LIBFT) -o client_bonus
	@echo "ready"

compile_lib:
	@cd libft && $(MAKE) 

clean:
	@$(RM) $(SOBJS) $(COBJS) $(CBOBJS) $(SBOBJS)
	@echo "cleaned"
	@cd libft && $(MAKE) clean 

fclean: clean
	@rm -f $(NAME) server_bonus client_bonus
	@cd libft && rm -f libft.a

re: fclean all



