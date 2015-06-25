##
## Makefile for make in /home/ayasch_d/Home/rendu/PSU_2014_42sh
## 
## Made by Dan Ayasch
## Login   <ayasch_d@epitech.net>
## 
## Started on  Tue May  5 11:18:40 2015 Dan Ayasch
## Last update Sun Jun  7 15:01:24 2015 Dan Ayasch
##

NAME		= 42sh

CC		= gcc -g

CFLAGS		+= -Wall -Wextra
CFLAGS		+= -I include/

SRCS		= execution/main.c \
		  lib/get_next_line.c \
		  parseur/parseur.c \
		  lib/tools.c \
		  lib/my_str_to_wordtab.c \
		  execution/my_exec.c \
		  execution/path.c \
		  execution/multi_sep.c \
		  execution/my_prompt.c \
		  execution/my_getenv.c \
		  execution/call_redir.c \
		  lib/my_put_nbr.c \
		  lib/my_strncmp.c \
		  lib/my_puterr.c \
		  builtin/call.c \
		  builtin/echo_sign.c \
		  builtin/built_in.c \
		  lib/fonctions.c \
		  builtin/my_echo.c \
		  redirection/my_redirect.c \
		  redirection/check.c \
		  redirection/wait_file.c \
		  redirection/redir.c \
		  redirection/creat_file.c \
		  redirection/redirection.c \
		  redirection/redirection_gauche.c \
		  redirection/separator_and.c \
		  redirection/separator_or.c \
		  redirection/separator_pipe.c \
		  redirection/supp_file.c \
		  history.c \
		  execution/tri.c \
		  execution/my_put_in_list.c \
		  builtin/built_in2.c \
		  builtin/built_cd.c \
		  redirection/comma.c \
		  lib/cpy_str.c \
		  execution/recur.c \
		  builtin/my_setenv.c \
		  builtin/check_built.c \
		  lib/epur_str.c \
		  alias/my_alias2.c \
		  alias/builtin_alias.c \
		  redirection/multi_pipe.c

OBJS		= $(SRCS:.c=.o)

RM		= rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
