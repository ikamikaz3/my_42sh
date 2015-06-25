/*
** supp_file.c for supp_file in /home/ayasch_d/Home/rendu/PSU_2014_42sh/redirection
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sun May 24 12:35:36 2015 Dan Ayasch
** Last update Sun May 24 12:36:37 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

char	**init_tab_rm()
{
  char	**tab5;

  if ((tab5 = malloc(sizeof(char *) * 4096)) == NULL)
    return (0);
  if ((tab5[0] = malloc(sizeof(char) * 4096)) == NULL)
    return (0);
  tab5[0] = "rm";
  if ((tab5[1] = malloc(sizeof(char) * 4096)) == NULL)
    return (0);
  tab5[1] = " ";
  return (tab5);
}

int	exec_rm(char **env)
{
  char	**tab5;
  char	*str;

  tab5 = init_tab_rm();
  str = cpy_str("/bin", tab5[0]);
  if ((my_access(str)) == 2)
    {
      my_do(str, env, tab5);
      return (0);
    }
  free(str);
  return (0);
}
