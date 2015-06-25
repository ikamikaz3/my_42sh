/*
** separator_and.c for separator_and in /home/billot_t/rendu/PSU_2014_42sh
** 
** Made by Thomas Billot
** Login   <billot_t@epitech.net>
** 
** Started on  Tue May 12 17:15:42 2015 Thomas Billot
** Last update Mon May 25 17:07:32 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int	separator_and(char **s1, char **s2, char **env, int point)
{
  if (s2 == NULL)
    {
      my_exec(env, s1[0], s1);
      return (0);
    }
  if (point == 1)
    {
      if (my_exec(env, s2[0], s2) == 1)
	return (-1);
    }
  else
    {
      if (my_exec(env, s1[0], s1) == 1)
	return (-1);
      else
	{
	  if (my_exec(env, s2[0], s2) == 1)
	    return (-1);
	}
    }
  return (0);
}
