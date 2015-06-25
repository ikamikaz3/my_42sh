/*
** fonctions.c for fonction in /home/hakim_s/rendu/PSU
** 
** Made by Sofiane HAKIM
** Login   <hakim_s@epitech.net>
** 
** Started on  Thu May  7 16:26:29 2015 Sofiane HAKIM
** Last update Sun May 17 12:08:14 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

char	*my_strcat(char *str)
{
  int	i;
  char	*ret;

  if (str == NULL)
    return (NULL);
  if ((ret = malloc(sizeof(char) * my_strlen(str))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      ret[i] = str[i];
      i = i + 1;
    }
  return (ret);
}

char	*env_name(char *env)
{
  int	i;
  char	*ret;

  i = 0;
  if ((ret = malloc(sizeof(char) * my_strlen(env))) == NULL)
    return (NULL);
  while (env[i] != '=')
    {
      ret[i] = env[i];
      i++;
      if (env[i] == '\0')
        return (ret);
    }
  return (ret);
}

char	*my_strcomp(char *str1, char *str2, int c)
{
  char	*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((str = malloc(my_strlen(str1) + my_strlen(str2) + 1)) == NULL)
    return (NULL);
  while (str1[i] != 0)
    {
      str[i] = str1[i];
      i = i + 1;
    }
  if (c == 1)
    str[i++] = '/';
  else if (c == 2)
    str[i++] = '=';
  else if (c == 0)
    str[i++] = ':';
  while (str2[j] != 0)
    str[i++] = str2[j++];
  return (str);
}
