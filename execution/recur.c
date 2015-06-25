/*
** recur.c for recur in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Fri May 15 14:42:16 2015 Dan Ayasch
** Last update Sat Jun  6 14:23:06 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int		aff_history(t_chaine *chaine)
{
  while (chaine->next != NULL)
    {
      my_putnbr(chaine->i);
      my_putstr("- ");
      my_putstr(chaine->str);
      my_putchar('\n');
      chaine = chaine->next;
    }
  while (chaine->prev != NULL)
    chaine = chaine->prev;
  return (0);
}

int		caller(char **env, t_list *list, t_chaine *chaine, char *str)
{
  if ((list = parseur(str, list)) == NULL)
    return (-1);
  alias(&list);
  if ((multi_pipe(list, env)) != -1)
    return (0);
  if ((env[0] == NULL))
    {
      if ((tri(env, list)) == -2)
	{
	  free(list);
	  free(chaine);
	  return (-2);
	}
    }
  else
    {
      if ((check_list(env, list)) == -2)
	{
	  free(list);
	  free(chaine);
	  return (-2);
	}
    }
  return (0);
}

int		recur(char **env, char *prompt, t_list *list)
{
  t_chaine	*chaine;
  char		*str;

  chaine = NULL;
  while (42)
    {
      my_putstr(prompt);
      if ((str = get_next_line(0)) == NULL)
        return (-1);
      if (!(str == NULL))
	{
	  history(&chaine, str);
	  if ((my_strcmp(str, "history")) == 0)
	    aff_history(chaine);
	  else
	    if ((caller(env, list, chaine, str)) == -2)
	      return (-2);
	}
    }
  return (0);
}
