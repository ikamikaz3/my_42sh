/*
** my_exec.c for exec in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Tue May  5 15:57:57 2015 Dan Ayasch
** Last update Sun Jun  7 14:42:53 2015 Dan Ayasch
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"

char	**read_path(char **env)
{
  char	*str;
  char	**tab;

  if ((str = malloc(sizeof(char) * 4096)) == NULL)
    return (0);
  if ((str = path(env)) == 0)
    {
      my_puterr("No PATH detected\n");
      return (0);
    }
  else
    tab = my_str_to_wordtab(str, ':');
  free(str);
  return (tab);
}

int	my_do(char *tub, char **env, char **save)
{
  pid_t	pid;
  int	statue;

  if ((pid = fork()) == -1)
    {
      my_putstr("Fork is dead\n");
      return (1);
    }
  if (pid == 0)
    {
      if ((setsid() == -1))
	return (-1);
      execve(tub, save, env);
      return (0);
    }
  else
    {
      waitpid(pid, &statue, WCONTINUED);
      if (WIFSIGNALED(statue))
	{
	  if (WTERMSIG(statue) == 11)
	    my_puterr("Segmentation Fault (Core dumped)\n");
	}
    }
  return (0);
}

int	my_access(char *str)
{
  if ((access(str, X_OK) == 0))
    {
      return (2);
    }
  return (0);
}

int	my_exec(char **env, char *exec, char **save)
{
  int	i;
  char	*str;
  char	**tab;

  i = 0;
  if ((slash(env, save) == 0))
    return (0);
  if ((tab = read_path(env)) != 0)
    {
      while (tab[i])
	{
	  str = cpy_str(tab[i], exec);
	  if ((my_access(str)) == 2)
	    {
	      my_do(str, env, save);
	      return (0);
	    }
	  i++;
	}
    }
  free(str);
  free(tab);
  return (1);
}

int	slash(char **env, char **save)
{
  if (save[0] == NULL || save == NULL)
    return (1);
  if (save[0][0] == '/')
    {
      if ((my_access(save[0])) == 2)
	{
	  my_do(save[0], env, save);
	  return (0);
	}
      else
	my_putstr("42sh : Command not found\n");
      return (1);
    }
  else if (save[0][0] == '.' && save[0][1] == '/')
    {
      if ((my_access(save[0])) == 2)
	{
	  my_do(save[0], env, save);
	  return (0);
	}
      my_putstr("42sh : Command not found\n");
    }
  else
    return (1);
  return (0);
}
