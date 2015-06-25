/*
** my_redirect.c for redirect in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Fri May  8 11:33:29 2015 Dan Ayasch
** Last update Sat Jun  6 14:41:56 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

const t_redir	g_tab2[] =
  {
    {&my_comma, ";"},
    {&d_arrow_left, "<<"},
    {&s_arrow_right, ">"},
    {&d_arrow_right, ">>"},
    {&s_arrow_left, "<"},
    {&separator_and, "&&"},
    {&separator_or, "||"},
    {&separator_pipe, "|"}
  };

int		retur_value_redir(char **s1, char **s2, t_point *point, int i)
{
  int		res;

  res = 0;
  if ((res = g_tab2[i].ftn(s1, s2, point->env, point->point)) == -1)
    {
      my_putstr("42sh : Command not found\n");
      return (-1);
    }
  else if (res == 5)
    return (2);
  return (0);
}

int		check_redir(char **s1, char **s2, char *redir, t_point *point)
{
  int		i;
  char		*str;
  int		res;
  char		**tab;

  res = 0;
  str = "; << > >> < && || |";
  tab = my_str_to_wordtab(str, ' ');
  i = 0;
  while (tab[i])
    {
      if ((my_strcmp2(tab[i], redir)) == 0)
	{
	  if ((res = retur_value_redir(s1, s2, point, i)) == -1)
	    return (-1);
	  else if (res == 2)
	    return (2);
	  free(tab);
	  return (1);
	}
      i++;
    }
  free(tab);
  return (0);
}
