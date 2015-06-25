/*
** epur_str.c for epur_str in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Wed May 20 11:18:49 2015 Dan Ayasch
** Last update Sun May 24 17:55:18 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

char	*erase_tab(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == '\t')
	str[i] = ' ';
      i++;
    }
  return (str);
}

char	*epur_str(char *str)
{
  int	i;
  int	j;
  char	*dest;

  j = 0;
  i = 0;
  if ((dest = malloc(sizeof(char) * (my_strlen(str)) + 1)) == NULL)
    return (NULL);
  while (str[i] != '\0')
    {
      while (str[i] == ' ')
	i++;
      if (str[i] == '\0')
	{
	  dest[j] = '\0';
	  return (dest);
	}
      dest[j] = str[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
