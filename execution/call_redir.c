/*
** call_redir.c for call_redir in /home/ayasch_d/Home/rendu/PSU_2014_42sh/execution
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sat May 23 17:37:47 2015 Dan Ayasch
** Last update Sun May 24 17:57:59 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int		call_notoken(char **env, t_list *list, int i)
{
  int		a;
  char		*str;
  char		**save;

  a = 0;
  if ((save = malloc(sizeof(char *) * 4096)) == NULL)
    return (-1);
  i--;
  str = list[i].command;
  save = list[i].option;
  if ((a = checker(save, env)) == -2)
    {
      return (-2);
    }
  else
    {
      if (!(a == 1))
        if (!(slash(env, save)) == 0)
          if ((my_exec(env, str, save)) != 0)
            my_putstr("42sh : Command not found\n");
    }
  return (0);
}

int		call_redir(t_list *list, int i, char **env)
{
  t_point	point;
  int		a;

  a = 0;
  if (i > 0 && (list[i - 1].operand[0] == '<' ||
		list[i - 1].operand[0] == '>')
      && (list[i].operand[0] == ';' ||
              list[i].operand[0] == '&' ||
	  (list[i].operand[0] == '|' && list[i].operand[1] == '|')))
    {
      point.point = 1;
      point.env = env;
      a = check_redir(list[i].option, list[i + 1].option,
                      list[i].operand, &point);
    }
  else
    {
      point.point = 0;
      point.env = env;
      a = check_redir(list[i].option, list[i + 1].option,
		      list[i].operand, &point);
    }
  return (a);
}

int		call_multi_redir(t_list *list, int i, char **env)
{
  t_point	point;

  point.point = 0;
  point.env = env;
  check_redir(list[i].option, list[i + 2].option, list[i].operand, &point);
  return (0);
}

int		no_command(t_list *list, char **env)
{
  if (list[0].operand != NULL)
    {
      if (list[0].operand[0] == '>' && list[0].command == NULL)
        {
          s_arrow_right(NULL, list[1].option, env, 0);
          return (0);
        }
      if (list[0].operand[0] == '<' && list[0].operand[1] == '<'
          && list[0].command == NULL)
        {
          d_arrow_left(NULL, list[1].option, env, 0);
          return (0);
        }
    }
  return (1);
}

int		call_no_env(char **save, char **env, t_list *list, int i)
{
  int		a;

  a = 0;
  i--;
  save = list[i].option;
  if ((a = checker(save, env)) == -2)
    return (-2);
  else
    {
      if (!(a == 1))
        if (!(slash(env, save)) == 0)
          my_putstr("Env is empty\n");
    }
  return (0);
}
