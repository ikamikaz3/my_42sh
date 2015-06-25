/*
** my_alias2.c for my_alias in /home/ayasch_d/Home/rendu/PSU_2014_42sh/alias
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sun May 24 11:24:16 2015 Dan Ayasch
** Last update Sun May 24 14:35:35 2015 Dan Ayasch
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "list.h"

char	**reverse_tab(char **tab)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (tab[i])
    {
      if (tab[i + 1] != NULL)
      	{
      	  tab[i] = tab[i + 1];
      	  tab[i + 1] = NULL;
      	}
      j++;
      i++;
    }
  return (tab);
}

int	stack_alias(t_list **list, int i, char **save)
{
  int	a;
  int	j;

  j = 0;
  a = 0;
  if ((*list)[i].option[1] != NULL)
    {
      (*list)[i].option = reverse_tab((*list)[i].option);
      while ((*list)[i].option[a])
	a++;
      while (save[j])
	{
	  (*list)[i].option[a] = save[j];
	  a++;
	  j++;
	}
    }
  else
    {
      if (((*list)[i].option = malloc(sizeof(char *) * 4096)) == NULL)
	return (-1);
      (*list)[i].option = save;
    }
  return (0);
}

int	comp_alias(t_list **list, int i, char **tab)
{
  char	**save;

  if (my_strcmp2((*list)[i].command, tab[0]) == 0)
    {
      if (tab[1] == NULL)
	return (-1);
      save = my_str_to_wordtab(tab[1], ' ');
      if (((*list)[i].command = malloc(sizeof(char) * 4096)) == NULL)
	return (-1);
      (*list)[i].command = save[0];
      if ((stack_alias(list, i, save)) == -1)
	return (-1);
    }
  return (0);
}

int	alias(t_list **list)
{
  int	fd;
  char	*name;
  char	**tab;
  int	i;

  i = 0;
  if ((fd = open("alias/alias", O_RDONLY)) == -1)
    return (-1);
  while ((name = get_next_line(fd)))
    {
      tab = my_str_to_wordtab(name, '=');
      i = 0;
      while ((*list)[i].command != NULL)
        {
	  if ((comp_alias(list, i, tab)) == -1)
	    return (-1);
          i++;
        }
    }
  close(fd);
  return (0);
}
