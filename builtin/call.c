/*
** call.c for call in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Thu May  7 16:13:43 2015 Dan Ayasch
** Last update Sun May 24 17:08:02 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

const t_tab	g_tab[] =
  {
    {&my_cd, "cd"},
    {&my_cd, ".."},
    {&my_env, "env"},
    {&my_exit, "exit"},
    {&my_setenv, "setenv"},
    {&my_unsetenv, "unsetenv"},
    {&my_echo, "echo"},
    {&built_alias, "alias"}
  };

int		checker(char **save, char **env)
{
  int		i;
  char		**tab1;
  char		*str;

  if (save[0] == NULL)
    return (0);
  str = "cd .. env exit setenv unsetenv echo alias";
  tab1 = my_str_to_wordtab(str, ' ');
  i = 0;
  while (tab1[i])
    {
      if ((my_strncmp(tab1[i], save[0])) == 0)
	{
	  if ((g_tab[i].fct(env, save)) == -2)
	    {
	      free(tab1);
	      return (-2);
	    }
	  free(tab1);
	  return (1);
	}
      i++;
    }
  free(tab1);
  return (0);
}
