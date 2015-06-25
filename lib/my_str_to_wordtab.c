/*
** my_str_to_wordpoint.c for wordtab in /home/ayasch_d/Dan/rendu/PSU_2014_minishell1
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Fri Jan 30 17:55:13 2015 Dan Ayasch
** Last update Sun May 24 18:14:08 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int	character(char *str, char str2)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] != '\0' && str[i] == str2)
	return (i);
      i++;
    }
  return (i);
}

int	word(char *str, char str2)
{
  int	i;
  int	a;

  a = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\0')
	break;
      else if (str[i] != '\0' && str[i] == str2)
	a++;
      i++;
    }
  a = a + 1;
  return (a);
}

char	**my_str_to_wordtab(char *str, char str2)
{
  char	**tab;
  int	i;
  int	j;

  i = 0;
  tab = NULL;
  if ((tab = malloc(sizeof(*tab) * (word(str, str2) + 1))) == NULL)
    return (NULL);
  while (*str != '\0')
    {
      j = 0;
      while (*str != '\0' && *str == str2)
  	str = str + 1;
      if (*str == '\0')
	break;
      if ((tab[i] = malloc(sizeof(*tab[i])
			   * (character(str, str2) + 3))) == NULL)
	return (NULL);
      while (str && *str != '\0' && *str != str2)
	tab[i][j++] = *(str++);
      tab[i++][j] = '\0';
    }
  tab[i] = NULL;
  return (tab);
}
