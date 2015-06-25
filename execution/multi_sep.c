/*
** mutli_sep.c for multisep in /home/ayasch_d/Home/rendu/PSU_2014_42sh/execution
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sun May 24 19:58:25 2015 Dan Ayasch
** Last update Mon May 25 17:11:49 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int		multi_sep_or(t_list *list, char **env, int i)
{
  t_point	point;

  if (list[i + 1].operand == NULL)
    return (0);
  if (list[i].operand[0] == '|' && list[i].operand[1] == '|'
      && list[i + 1].operand[0] == '|' && list[i + 1].operand[1] == '|')
    {
      point.point = 0;
      point.env = env;
      if (check_redir(list[i].option, list[i + 1].option,
                      list[i].operand, &point) == 2)
        return (1);
      else
        my_exec(env, list[i + 2].command, list[i + 2].option);
      return (1);
    }
  return (0);
}

int		multi_sep(t_list *list, char **env)
{
  int		i;
  t_point	point;

  i = -1;
  while (list[++i].command != NULL)
    {
      if (list[i].token == 3)
        {
	  if (list[i + 1].operand == NULL)
	    return (0);
          if (list[i].operand[0] == '&' && list[i + 1].operand[0] == '&')
            {
              point.point = 0;
              point.env = env;
              check_redir(list[i].option, list[i + 1].option,
                          list[i].operand, &point);
              if (list[i + 2].option != NULL && list[i + 2].command != NULL)
                my_exec(env, list[i + 2].command, list[i + 2].option);
              return (1);
            }
          if ((multi_sep_or(list, env, i)) == 1)
            return (1);
        }
    }
  return (0);
}
