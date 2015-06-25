/*
** parseur.c for parseur in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Tue May  5 13:48:54 2015 Dan Ayasch
** Last update Sun May 24 17:50:13 2015 Dan Ayasch
*/

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int		first_elem(char **save, int i)
{
  if (save[0][0] == '|' || save[0][0] == ';' ||
      save[0][0] == '&')
    {
      my_putstr("42sh: syntax error near unexpected token ");
      my_putstr(save[0]);
      my_putchar('\n');
      return (1);
    }
  else if (!(save[0][0] == '|' || save[0][0] == ';' ||
	     save[0][0] == '&' || save[0][0] == '<'
	     || save[0][0] == '>') && i == 0)
    return (2);
  return (0);
}

int		filling_list_operator(char **save, t_list **list, t_var *var)
{
  if (save[var->j] != NULL && (save[var->j][0] == '|' ||
			       save[var->j][0] == ';' ||
			       save[var->j][0] == '&' || save[var->j][0] == '<'
			       || save[var->j][0] == '>'))
    {
      (*list)[var->x].token = 3;
      (*list)[var->x++].operand = epur_str(save[var->j]);
    }
  return (var->x);
}

int		filling_command(t_list *list, char **save, t_var *var)
{
  if (var->a == 0)
    {
      list[var->x].command = (save[var->j]);
      if ((list[var->x].option = malloc(sizeof(char) * 4096)) == NULL)
	return (-1);
    }
  return (0);
}

t_list		*filling_list(char **save, t_list *list, t_var var)
{
  while (save[var.j] != NULL)
    {
      if (first_elem(save, var.j) == 1)
  	return (list);
      var.a = 0;
      while (save[var.j] && (save[var.j][0] != '|' && save[var.j][0] != ';' &&
      			 save[var.j][0] != '&' && save[var.j][0] != '<' &&
      			 save[var.j][0] != '>'))
      	{
      	  if ((filling_command(list, save, &var)) == -1)
      	    return (NULL);
      	  if ((list[var.x].option[var.a] = malloc(sizeof(char) * 4096)) == NULL)
      	    return (NULL);
      	  list[var.x].option[var.a++] = epur_str(save[var.j++]);
      	}
      if (var.a != 0)
	list[var.x].option[var.a] = NULL;
      var.x = filling_list_operator(save, &list, &var);
      if (save[var.j] != NULL)
      	++var.j;
    }
  return (list);
}

t_list		*parseur(char *str, t_list *list)
{
  t_var		var;
  char		**save;

  var.x = 0;
  var.j = 0;
  if ((list = malloc(sizeof(*list) * 4096)) == NULL)
    return (NULL);
  str = erase_tab(str);
  save = my_str_to_wordtab(str, ' ');
  list = filling_list(save, list, var);
  free(save);
  return (list);
}
