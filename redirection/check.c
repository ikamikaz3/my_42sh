/*
** check.c for check in /home/ayasch_d/Home/rendu/PSU_2014_42sh/redirection
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sat May 23 17:53:37 2015 Dan Ayasch
** Last update Sat Jun  6 14:58:02 2015 Dan Ayasch
*/

#include <unistd.h>
#include <stdlib.h>
#include "list.h"

int	call_checker(char **s1, char **path, char **env, char **s2)
{
  if ((check_access(s1, path)) == 1)
    return (-1);
  if ((check_access(s2, path)) == 1)
    return (-1);
  if ((pipe_fork(s1, s2, env, path)) == -1)
    return (-1);
  return (0);
}

char	**check_path(char **env)
{
  char	*str;
  char	**tab;

  if ((str = malloc(sizeof(char) * 4096)) == NULL)
    return (0);
  if ((str = path(env)) == 0)
    return (0);
  else
    tab = my_str_to_wordtab(str, ':');
  free(str);
  return (tab);
}

int	check_slash(char **tab, char **env)
{
  if ((tab == NULL))
    return (1);
  if (tab[0][0] == '/')
    {
      if ((my_access(tab[0])) == 2)
        {
          execve(tab[0], tab, env);
          return (0);
        }
    }
  return (1);
}

int	check_access(char **s1, char **path)
{
  int	i;
  char	*str;

  i = 0;
  if (s1[0][0] == '/')
    {
      if ((my_access(s1[0])) == 2)
        return (0);
    }
  if (path == NULL)
    return (1);
  while (path[i])
    {
      str = cpy_str(path[i], s1[0]);
      if ((my_access(str)) == 2)
        return (0);
      i++;
      free(str);
    }
  return (1);
}
