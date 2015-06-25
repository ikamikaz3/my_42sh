/*
** wait_file.c for wait in /home/ayasch_d/Home/rendu/PSU_2014_42sh/redirection
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sun Jun  7 14:52:03 2015 Dan Ayasch
** Last update Sun Jun  7 15:53:21 2015 Dan Ayasch
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "list.h"

int	process_son(int p[2])
{
  if ((setsid()) == -1)
    return (-1);
  if ((close(p[0])) == -1)
    return (-1);
  if ((dup2(p[1], 1)) == -1)
    return (-1);
  return (0);
}

int	wai_father(int pid, int p[2], int status)
{
  waitpid(pid, &status, WNOHANG);
  close(p[1]);
  dup2(p[0], 0);
  close(p[0]);
  return (0);
}

int	wait_exec_red(pid_t pid, int statue, int fd)
{
  waitpid(pid, &statue, WCONTINUED);
  if (WIFSIGNALED(statue))
    {
      if (WTERMSIG(statue) == 11)
        my_putstr("Segmentation Fault (Core dumped)\n");
    }
  if ((dup2(1, fd)) == -1)
    return (-1);
  return (0);
}
