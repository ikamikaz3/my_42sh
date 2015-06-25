/*
** cpy_str.c for cpy_str in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sun May 17 12:45:50 2015 Dan Ayasch
** Last update Wed May 20 16:07:55 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

char	*cpy_str(char *str, char *str2)
{
  int	i;
  int	j;
  char	*str3;
  int	k;

  k = 0;
  i = 0;
  j = 0;
  if ((str3 = malloc(sizeof(char) * 4096)) == NULL)
    return (0);
  while (str[i] != '\0')
    {
      str3[k] = str[i];
      i++;
      k++;
    }
  str3[k++] = '/';
  while (str2[j] != '\0')
    {
      str3[k] = str2[j];
      k++;
      j++;
    }
  str3[k] = '\0';
  return (str3);
}

char	*cpy_str2(char *str, char *str2)
{
  int	i;
  int	j;
  char	*str3;
  int	k;

  k = 0;
  i = 0;
  j = 0;
  if ((str3 = malloc(sizeof(char) * 4096)) == NULL)
    return (0);
  while (str[i] != '\0')
    {
      str3[k] = str[i];
      i++;
      k++;
    }
  while (str2[j] != '\0')
    {
      str3[k] = str2[j];
      k++;
      j++;
    }
  str3[k] = '\0';
  return (str3);
}
