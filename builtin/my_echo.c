/*
** main.c for main in /home/gizard_a/rendu/systeme-unix/42sh/echo
** 
** Made by Claire Gizard
** Login   <gizard_a@epitech.net>
** 
** Started on  Tue May  5 14:30:45 2015 Claire Gizard
** Last update Sun May 24 20:02:48 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

int	echo_e(char **tab)
{
  int	i;

  i = 2;
  while (tab[i] != NULL)
    {
      if (!(tab[i][0] == 92))
	my_putstr(tab[i++]);
    }
  my_putchar('\n');
  return (0);
}

int	simple_echo(char **s)
{
  int	n;

  n = 2;
  while (s[n] != NULL)
    {
      my_putstr(s[n]);
      if (s[n + 1] == NULL)
	break;
      n++;
      my_putchar(' ');
    }
  return (0);
}

int	call_echo(char **s, char **env)
{
  if (s[1][0] == '-' && s[1][1] == 'n')
    simple_echo(s);
  else if (s[1][0] == '-' && s[1][1] == 'e')
    echo_e(s);
  else if (s[1][0] ==  '$')
    echo_$(s, env);
  else
    return (1);
  return (0);
}

int	my_echo(char **env, char **s)
{
  int	n;

  (void)env;
  n = 0;
  if (s[1] == NULL)
    {
      my_putchar('\n');
      return (1);
    }
  if (call_echo(s, env) == 1)
    {
      n = 1;
      while (s[n] != NULL)
  	{
  	  my_putstr(s[n++]);
  	  my_putchar(' ');
  	}
      my_putchar('\n');
    }
  return (0);
}
