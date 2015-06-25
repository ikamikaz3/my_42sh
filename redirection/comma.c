/*
** comma.c for comma in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Fri May 15 14:29:54 2015 Dan Ayasch
** Last update Sun Jun  7 14:43:31 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int	my_comma_point(char **s1, char **s2, char **env, int point)
{
  if (point != 1)
    {
      if (!(checker(s1, env)) == 1)
	{
	  if ((my_exec(env, s1[0], s1)) == 1)
	    {
	      my_putstr("42sh : Command not found\n");
	    }
	}
    }
  if (!(checker(s2, env)) == 1)
    {
      if ((my_exec(env, s2[0], s2)) == 1)
	{
	  my_putstr("42sh : Command not found\n");
	  return (-1);
	}
    }
  return (0);
}

int	my_comma(char **s1, char **s2, char **env, int point)
{
  if (s2 == NULL)
    {
      my_exec(env, s1[0], s1);
      return (0);
    }
  if (env[0] == NULL)
    {
      if (!(checker(s1, env)) == 1)
	if (!(slash(env, s1)) == 0)
	  my_putstr("Env is empty\n");
      if (!(checker(s2, env)) == 1)
	if (!(slash(env, s2)) == 0)
	  my_putstr("Env is empty\n");
      return (0);
    }
  else
    my_comma_point(s1, s2, env, point);
  return (0);
}
