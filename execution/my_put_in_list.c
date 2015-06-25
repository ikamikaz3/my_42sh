/*
** my_put_in_list.c for my_put_in_list in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Mon May 18 14:20:50 2015 Dan Ayasch
** Last update Sat May 23 14:58:22 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int		init_root(t_chaine **root, char *str, int i)
{
  if ((*root = malloc(sizeof(t_chaine))) == NULL)
    return (-1);
  (*root)->str = str;
  (*root)->i = i;
  (*root)->prev = NULL;
  (*root)->next = NULL;
  return (0);
}

int		my_put_in_list(t_chaine **root, char *str, int i)
{
  t_chaine	*elem;
  t_chaine	*tmp;

  if ((*root) == NULL)
    {
      if ((init_root(root, str, i)) == -1)
	return (-1);
    }
  else
    {
      if ((elem = malloc(sizeof(t_chaine))) == NULL)
        return (-1);
      elem->str = str;
      elem->i = i;
      elem->prev = NULL;
      elem->next = NULL;
      tmp = *root;
      while (tmp->next != NULL)
        tmp = tmp->next;
      tmp->next = elem;
      elem->prev = tmp;
    }
  return (0);
}
