/*
** tools.c for tools in /home/ayasch_d/Dan/rendu/minishell2
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Tue Feb 24 11:17:50 2015 Dan Ayasch
** Last update Sun May 24 11:37:43 2015 Dan Ayasch
*/

#include <stdlib.h>
#include <unistd.h>
#include "list.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

char	*my_strcpy(char *src)
{
  char	*dest;
  int	i;
  int	j;

  j = 0;
  i = 5;
  dest = NULL;
  if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}

char	*my_strcpy_pwd(char *src)
{
  char	*dest;
  int	i;
  int	j;

  j = 0;
  i = 7;
  dest = NULL;
  if ((dest = malloc(sizeof(char) * my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (src[i] != '\0')
    {
      dest[j] = src[i];
      i++;
      j++;
    }
  dest[j] = '\0';
  return (dest);
}
