/*
** separator_or.c for separator in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Thu May 14 11:17:22 2015 Dan Ayasch
** Last update Sun Jun  7 15:54:38 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int	separator_or(char **s1, char **s2, char **env, int point)
{
  if (s2 == NULL)
    {
      my_exec(env, s1[0], s1);
      return (0);
    }
  if (point == 1)
    return (0);
  else
    {
      if ((my_exec(env, s1[0], s1) == 0))
	return (1);
      else
	{
	  my_putstr("42sh : Command not found\n");
	  if ((my_exec(env, s2[0], s2)) == 1)
	    {
	      my_putstr("42sh : Command not found\n");
	      return (1);
	    }
	}
    }
  return (5);
}
