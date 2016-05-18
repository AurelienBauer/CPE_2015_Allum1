##
## Makefile for  in /home/aurelien/rendu/PSU_2015_my_ls
## 
## Made by Aurélien
## Login   <aurelien.bauer@epitech.net>
## 
## Started on  Thu Nov 26 15:34:08 2015 Aurélien
## Last update Tue Feb 16 14:28:57 2016 Aurélien
##

RM	= rm -f									\

CC	= gcc									\

NAME	= allum1								\

CFLAGS	= -lmy -L ./lib -I ./include						\

SRCS	= main.c			\
	  parc_board.c			\
	  print_updated_board_game.c	\
	  remp_board.c			\
	  ia.c

OBJS	= $(SRCS:.c=.o)								\

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) *~

re: fclean all

.PHONY: all clean re
