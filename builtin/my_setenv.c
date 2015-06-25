/*
** my_setenv.c for my_setenv in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Fri May 15 14:45:31 2015 Dan Ayasch
** Last update Sat May 23 14:34:53 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int	setenv_empty(char **env, char **s)
{
  if (s[1] == NULL && s[2] == NULL)
    {
      my_env(env, s);
      return (1);
    }
  return (0);
}

int	setenv_nd_empty(char **env, char **s)
{
  char	*str2;
  int	i;

  i = 0;
  if (s[1] != NULL && s[2] == NULL)
    {
      while (env[i] != NULL)
        {
          str2 = env_name(env[i]);
          if (my_strncmp(s[1], str2) == 0)
            {
              env[i] = cpy_str2(str2, "=");
              free(str2);
              return (1);
            }
          i++;
          free(str2);
        }
      env[i] = cpy_str2(s[1], "=");
      i++;
      env[i] = NULL;
      return (1);
    }
  return (0);
}

int	setenv_not_empty(char **env, char **s)
{
  char	*str;
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      str = env_name(env[i]);
      if (my_strncmp(s[1], str) == 0)
        {
          env[i] = cpy_str2(s[1], "=");
	  env[i] = cpy_str2(env[i], s[2]);
          return (1);
        }
      i++;
      free(str);
    }
  env[i] = cpy_str2(s[1], "=");
  env[i] = cpy_str2(env[i], s[2]);
  env[++i] = NULL;
  return (0);
}

int	my_setenv(char **env, char **s)
{
  if ((setenv_empty(env, s)) == 1)
    return (1);
  else if ((setenv_nd_empty(env, s)) == 1)
    return (1);
  if ((setenv_not_empty(env, s)) == 1)
    return (1);
  return (1);
}
