/*
** tri.c for tri in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Fri May 15 14:38:09 2015 Dan Ayasch
** Last update Sun May 24 20:06:24 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int		fill_list(t_list *list, char **env)
{
  int		i;
  int		a;

  i = 0;
  a = 0;
  while (list[i].command != NULL)
    {
      if (list[i].token == 3)
	{
	  if (list[i].operand[0] == '>')
	    {
	      if (list[i + 1].operand == NULL)
		a = call_redir(list, i, env);
	      else if (list[i + 1].operand[0] == '>')
		{
		  call_multi_redir(list, i, env);
		  i = i + 2;
		}
	    }
	  else
	    a = call_redir(list, i, env);
	}
      i++;
    }
  return (a);
}

int		check_list(char **env, t_list *list)
{
  int		i;
  int		a;

  i = 0;
  a = 0;
  if ((no_command(list, env)) == 0)
    return (0);
  if (!(list[0].command == NULL))
    {
      if ((multi_sep(list, env)) == 1)
	return (1);
      a = fill_list(list, env);
      i = 1;
      if (a == 0)
	if ((call_notoken(env, list, i)) == -2)
	  return (-2);
    }
  return (0);
}

int		check_token(t_list *list, int i, char **env, int a)
{
  t_point	point;

  if (list[i].token == 3)
    {
      point.point = 0;
      point.env = env;
      a = check_redir(list[i].option, list[i + 1].option,
		      list[i].operand, &point);
    }
  return (a);
}

int		tri(char **env, t_list *list)
{
  int		i;
  int		a;
  char		**save;

  i = 0;
  a = 0;
  if ((save = malloc(sizeof(char *) * 4096)) == NULL)
    return (-1);
  if (!(list[0].command == NULL))
    {
      while (list[i].command != NULL)
	{
	  a = check_token(list, i, env, a);
	  i++;
	}
      if (a == 0)
	if ((call_no_env(save, env, list, i)) == -2)
	  return (-2);
    }
  return (0);
}
