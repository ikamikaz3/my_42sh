/*
** separator_pipe.c for pipe in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Fri May 22 11:03:25 2015 Dan Ayasch
** Last update Sun Jun  7 15:43:33 2015 Dan Ayasch
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "list.h"

int	exec_path(char **env, char **tab, char **path)
{
  int	i;
  char	*str;

  i = 0;
  if ((check_slash(tab, env) == 0))
    return (0);
  if (path == NULL)
    return (1);
  while (path[i] != NULL)
    {
      str = cpy_str(path[i], tab[0]);
      if ((my_access(str)) == 2)
	{
	  execve(str, tab, env);
          return (0);
	}
      i++;
    }
  my_putstr("42sh : Command not found1\n");
  free(str);
  return (i);
}

int	wait_father(int p[2], char **env, char **s2, char **path)
{
  int	status;

  wait(&status);
  close(p[1]);
  if ((dup2(p[0], 0)) == -1)
    return (-1);
  if ((setsid()) == -1)
    return (-1);
  if ((exec_path(env, s2, path)) == -1)
    return (-1);
  return (0);
}

int	execution_pipe(char **s1, char **s2, char **env, char **path)
{
  int	p[2];
  int	pid;

  if ((pipe(p)) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    {
      my_putstr("Fork is dead\n");
      return (1);
    }
  if (pid == 0)
    {
      if ((setsid() == -1))
	return (-1);
      close(p[0]);
      if ((dup2(p[1], 1)) == -1)
	return (-1);
      if ((exec_path(env, s1, path)) == -1)
	return (-1);
    }
  else
    if ((wait_father(p, env, s2, path)) == -1)
      return (-1);
  return (0);
}

int	separator_pipe(char **s1, char **s2, char **env, int point)
{
  char	**path;
  int	a;

  a = 0;
  (void)point;
  if ((s1 == NULL || s2 == NULL))
    return (-1);
  path = check_path(env);
  if ((check_built(s1)) == 1)
    {
      my_exec(env, s2[0], s2);
      return (0);
    }
  if ((check_built(s2)) == 1)
    {
      if ((a = checker(s2, env)) == -2)
  	return (-2);
      else if (a == 1)
  	return (1);
    }
  if ((call_checker(s1, path, env, s2)) == -1)
    return (-1);
  return (0);
}

int	pipe_fork(char **s1, char **s2, char **env, char **path)
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
      execution_pipe(s1, s2, env, path);
      free(path);
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
  free(path);
  return (0);
}
