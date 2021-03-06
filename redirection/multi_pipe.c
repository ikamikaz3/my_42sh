/*
** multi_pipe.c for multi_pipe in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sat Jun  6 13:45:53 2015 Dan Ayasch
** Last update Tue Jun  9 15:10:34 2015 Dan Ayasch
*/

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"

int	check_nb_pipe(t_list *list)
{
  int	i;
  int	nb;

  nb = 0;
  i = 0;
  if (list[0].operand[0] != '|')
    return (0);
  while (list[i].operand != NULL)
    {
      while (list[i].operand[0] == '|')
	{
	  nb++;
	  i++;
	  if (list[i].operand == NULL)
	    return (nb);
	}
      if (nb != 0)
	return (nb);
      i++;
    }
  return (0);
}

int	re_fork(t_list *list, int i, char **env, char **path)
{
  other_pipe(list, env, path, i);
  return (0);
}

int	exec_end(t_list *list, int i, char **path, char **env)
{
  if (list[i].command == NULL)
    return (1);
  if (list[i].operand == NULL)
    {
      exec_path(env, list[i].option, path);
      return (1);
    }
  return (0);
}

int	other_pipe(t_list *list, char **env, char **path, int i)
{
  int	p[2];
  int	pid;
  int	status;

  status = 0;
  if (exec_end(list, i, path, env) == 1)
    return (1);
  if ((pipe(p)) == -1)
    return (-1);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    {
      if ((process_son(p)) == -1)
      	return (-1);
      exec_path(env, list[i].option, path);
    }
  else
    {
      wai_father(pid, p, status);
      if ((list[i].operand[0] == '|'))
	re_fork(list, i + 1 , env, path);
    }
  return (0);
}

int	multi_pipe(t_list *list, char **env)
{
  char	**path;
  int	nb;
  pid_t	pid;
  int	status;

  if (list[0].operand == NULL)
    return (-1);
  if ((nb = check_nb_pipe(list)) <= 1)
    return (-1);
  path = check_path(env);
  if ((pid = fork()) == -1)
    return (-1);
  if (pid == 0)
    other_pipe(list, env, path, 0);
  else
    {
      waitpid(-1, &status, 0);
      if (WIFSIGNALED(status))
      	{
      	  if (WTERMSIG(status) == 11)
      	    my_puterr("Segmentation Fault (Core dumped)\n");
      	}
    }
  return (0);
}
