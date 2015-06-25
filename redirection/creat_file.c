/*
** creat_file.c for creat_file in /home/ayasch_d/Home/rendu/PSU_2014_minishell2
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Wed Mar 11 12:49:51 2015 Dan Ayasch
** Last update Sun May 24 14:09:42 2015 Dan Ayasch
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "list.h"

int	creat_file(char **tab3)
{
  int	fd;
  int	i;

  i = 0;
  if ((fd = open(" ", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
    return (1);
  if (tab3[0] == NULL)
    return (1);
  while (tab3[i])
    {
      if ((write(fd, tab3[i], my_strlen(tab3[i]))) == -1)
	return (1);
      if ((write(fd, "\n", 1)) == -1)
	return (1);
      i++;
    }
  if (close(fd) == -1)
    return (1);
  return (0);
}

char	**init_tab_redir(char **clear2)
{
  char	**tab4;
  int	i;
  int	j;

  if ((tab4 = malloc(sizeof(char *) * 4096)) == NULL)
    return (0);
  if ((tab4[0] = malloc(sizeof(char) * 4096)) == NULL)
    return (0);
  tab4[0] = clear2[0];
  if ((clear2[0][0] == 'c' && clear2[0][1] == 'a' && clear2[0][2] == 't')
      || (clear2[0][0] == 'w' && clear2[0][1] == 'c'))
    {
      if ((tab4[1] = malloc(sizeof(char) * 4096)) == NULL)
	return (0);
     tab4[1] = " ";
    }
  i = 1;
  j = 1;
  while (clear2[i])
    tab4[j++] = clear2[i++];
  return (tab4);
}

char	**fill_tabl(char **env, char **tabl, char **tab4, char **clear2)
{
  char	*str;
  int	i;

  i = 0;
  while (tabl[i])
    {
      str = cpy_str(tabl[i], clear2[0]);
      if ((my_access(str)) == 2)
	{
	  my_do(str, env, tab4);
	  return (tabl);
	}
      i++;
    }
  return (tabl);
}

char	**exec_redir(char **env, char **clear2)
{
  char	**tabl;
  char	**tab4;

  tab4 = init_tab_redir(clear2);
  if ((tabl = read_path(env)) == 0)
    if ((slash(env, clear2)) == 0)
      return (tabl);
  if (tabl != 0)
    {
      if ((slash(env, clear2)) == 0)
	return (tabl);
      tabl = fill_tabl(env, tabl, tab4, clear2);
    }
  free(tab4);
  return (tabl);
}
