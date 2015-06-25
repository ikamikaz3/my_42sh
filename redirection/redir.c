/*
** redir.c for redir in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Fri May  8 11:41:11 2015 Dan Ayasch
** Last update Sat May 23 12:50:19 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

char	**boucle(char **tab3, char **s2)
{
  char	*str;
  int	i;

  i = 0;
  while (42)
    {
      my_putstr(" > ");
      if ((str = get_next_line(0)) == NULL)
        return (NULL);
      if ((tab3[i] = malloc(sizeof(char) * my_strlen(str))) == NULL)
	return (0);
      tab3[i] = str;
      if (my_strncmp(s2[0], str) == 0)
	break;
      if (i + 1 == 30)
	break;
      i++;
    }
  tab3[i] = NULL;
  free(str);
  return (tab3);
}

int	d_arrow_left(char **s1, char **s2, char **env, int point)
{
  char	**tab3;
  char	**tabl;

  (void)point;
  if ((tab3 = malloc(sizeof(char *) * 4096)) == NULL)
    return (0);
  if (s2 == NULL)
    return (0);
  tab3 = boucle(tab3, s2);
  if (tab3 == NULL)
    return (0);
  if (s1[0] == NULL)
    return (0);
  if (creat_file(tab3) == 1)
    return (0);
  tabl = exec_redir(env, s1);
  exec_rm(env);
  free(tab3);
  free(tabl);
  return (0);
}
