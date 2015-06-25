/*
** check_built.c for check in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Tue May 19 17:13:53 2015 Dan Ayasch
** Last update Sun May 24 18:19:27 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int	check_built(char **save)
{
  int	i;
  char	*str;
  char	**tab;

  i = 0;
  str = "cd .. env exit setenv unsetenv";
  tab = my_str_to_wordtab(str, ' ');
  if (save == NULL)
    return (0);
  while (tab[i])
    {
      if ((my_strncmp(tab[i], save[0])) == 0)
	return (1);
      i++;
    }
  free(tab);
  return (0);
}
