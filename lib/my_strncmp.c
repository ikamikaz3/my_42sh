/*
** my_strcmp.c for my_strcmp in /home/ayasch_d/recode
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Thu Oct 23 17:07:52 2014 Dan Ayasch
** Last update Sun May 17 12:07:33 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int	my_strncmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  return (0);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  while (s1[i] == s2[i])
    {
      i++;
      if (s1[i] == '\0' || s2[i] == '\0')
        return (0);
    }
  return (1);
}

int	my_strcmp2(char *s1, char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (1);
  while (s1[i] == s2[i])
    {
      i++;
      if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    }
  return (1);
}
