/*
** history.c for history in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Mon May 18 14:16:07 2015 Dan Ayasch
** Last update Sat May 23 17:52:01 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int		history(t_chaine **list, char *str)
{
  static int	i;

  if ((my_put_in_list(list, str, i)) == -1)
    return (-1);
  i++;
  return (0);
}
