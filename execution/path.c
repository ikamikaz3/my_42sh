/*
** path.c for path in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Tue May  5 16:00:28 2015 Dan Ayasch
** Last update Sat May 23 15:50:34 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

char	*path(char **env)
{
  char	*name;
  int	x;
  int	y;

  x = 0;
  y = 0;
  while (env[y] != NULL)
    {
      if (env[y][x] == 'P' && env[y][x + 1] == 'A' && env[y][x + 2] == 'T'
          && env[y][x + 3] == 'H')
        name = my_strcpy(env[y]);
      y++;
    }
  return (name);
}
