/*
** my_getenv.c for getenv in /home/chuong_a/rendu/PSU_2014_minishell1
** 
** Made by Alex Chuong
** Login   <chuong_a@epitech.net>
** 
** Started on  Tue May  5 16:19:47 2015 Alex Chuong
** Last update Sun May 24 13:16:11 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

char	*my_getenv(char **envp, char *str)
{
  int	i;
  char	*env;

  i = 0;
  env = NULL;
  while (envp[i] != NULL)
    {
      if (my_strcmp(envp[i], str) == 0)
        {
          env = my_strcpy(envp[i]);
          return (env);
        }
      i++;
    }
  return (NULL);
}

char	*my_getenv_pwd(char **envp, char *str)
{
  int	i;
  char	*env;

  i = 0;
  env = NULL;
  while (envp[i] != NULL)
    {
      if (my_strcmp(envp[i], str) == 0)
        {
          env = my_strcpy_pwd(envp[i]);
          return (env);
        }
      i++;
    }
  return (NULL);
}
