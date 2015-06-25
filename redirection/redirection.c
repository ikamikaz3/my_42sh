/*
** redirection.c for redirection in /home/hakim_s/rendu/PSU/PSU_2014_minishell1
** 
** Made by Sofiane HAKIM
** Login   <hakim_s@epitech.net>
** 
** Started on  Wed May  6 11:15:27 2015 Sofiane HAKIM
** Last update Sun Jun  7 14:52:47 2015 Dan Ayasch
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include "list.h"

int	create_file(char *str)
{
  int	fd;

  if ((fd = open(str, O_CREAT | O_WRONLY | O_RDONLY
		 | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
    my_putstr("Error Open New File\n");
  return (fd);
}

int	call_exec(char **arg, char **env, char **tab)
{
  int	i;
  char	*way;

  i = 0;
  if ((check_slash(arg, env)) == 0)
    return (0);
  if (tab[i] == NULL)
    {
      my_putstr("No path detected\n");
      return (-1);
    }
  while (tab[i])
    {
      way = my_strcomp(tab[i], arg[0], 1);
      if (execve(way, arg, env) == -1)
	i++;
    }
  return (-1);
}

/* int	wait_exec_red(pid_t pid, int statue, int fd) */
/* { */
  /* waitpid(pid, &statue, WCONTINUED); */
  /* if (WIFSIGNALED(statue)) */
  /*   { */
  /*     if (WTERMSIG(statue) == 11) */
  /* 	my_putstr("Segmentation Fault (Core dumped)\n"); */
  /*   } */
  /* if ((dup2(1, fd)) == -1) */
  /*   return (-1); */
  /* return (0); */
/* } */

int	my_exec_red(char **arg, char **env, char **tab, int fd)
{
  pid_t	pid;
  int	statue;

  statue = 0;
  if ((pid = fork()) == -1)
    {
      my_putstr("Fork is dead\n");
      return (-1);
    }
  if (pid == 0)
    {
      if ((setsid() == -1))
	return (-1);
      if ((dup2(fd, 1)) == -1)
	return (-1);
      if ((call_exec(arg, env, tab)) == -1)
	return (-1);
    }
  else
    if (wait_exec_red(pid, statue, fd) == -1)
      return (-1);
  return (0);
}

int	d_arrow_right(char **comand, char **file, char **env, int point)
{
  int	fd;
  char	**way;

  (void)point;
  if ((check_built(comand)) == 0)
    {
      way = check_path(env);
      if (file == NULL)
	{
	  my_putstr("bash: syntax error near unexpected token `newline'\n");
	  return (0);
	}
      if ((fd = open(file[0], O_RDWR | O_APPEND,
		     S_IRUSR | S_IWUSR)) == -1)
	fd = create_file(file[0]);
      if (comand == NULL)
	return (0);
      if (my_exec_red(comand, env, way, fd) == -1)
	return (-1);
    }
  return (0);
}

int	s_arrow_right(char **comand, char **file, char **env, int point)
{
  int	fd;
  char	**way;

  (void)point;
  if ((check_built(comand)) == 0)
    {
      way = check_path(env);
      if (file == NULL)
	{
	  my_putstr("bash: syntax error near unexpected token `newline'\n");
	  return (0);
	}
      if ((fd = open(file[0], O_WRONLY | O_TRUNC)) == -1)
	fd = create_file(file[0]);
      if (comand == NULL)
	return (0);
      if (my_exec_red(comand, env, way, fd) == -1)
	return (-1);
    }
  return (0);
}
