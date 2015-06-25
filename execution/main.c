/*
** main.c for main in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Fri May 15 14:36:19 2015 Dan Ayasch
** Last update Sun May 24 14:45:25 2015 Dan Ayasch
*/

#include <signal.h>
#include <stdlib.h>
#include "list.h"

void		ctrl_c()
{
  my_putstr("\n");
  my_putstr(g_prompt);
}

int		main(int ac, char **av, char **env)
{
  t_list	list;

  (void)ac;
  (void)av;
  g_prompt = NULL;
  g_prompt = my_prompt(env);
  if ((signal(SIGINT, ctrl_c)) == SIG_ERR)
    return (2);
  if ((recur(env, g_prompt, &list)) == -2)
    return (2);
  return (2);
}
