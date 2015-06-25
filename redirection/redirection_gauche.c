/*
** redirection_gauche.c for redirection_gauche in /home/billot_t/rendu/PSU_2014_42sh
** 
** Made by Thomas Billot
** Login   <billot_t@epitech.net>
** 
** Started on  Wed May  6 16:48:09 2015 Thomas Billot
** Last update Mon May 25 17:10:46 2015 Dan Ayasch
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "list.h"

int		open_tmp_file()
{
  int		fd;

  if ((fd = open("tmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR
		 | S_IWUSR)) == -1)
    {
      my_putstr("Error\n");
      return (-1);
    }
  else
    return (fd);
}

char		**init_rm(char **rm)
{
  if ((rm[0] = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  rm[0] = "rm";
  if ((rm[1] = malloc(sizeof(char) * 10)) == NULL)
    return (NULL);
  rm[1] = "tmp";
  return (rm);
}

int		s_arrow_exec(char **command, char **env)
{
  int		i;

  i = 0;
  if ((command[0][0] == 'c' && command[0][1] == 'a' && command[0][2] == 't')
      || (command[0][0] == 'w' && command[0][1] == 'c')
      || (my_strcmp2(command[0], "/bin/cat") == 0) ||
      (my_strcmp2(command[0], "/usr/bin/wc") == 0))
    {
      while (command[i])
  	i++;
      command[i++] = "tmp";
      command[i] = NULL;
      if (my_exec(env, command[0], command) == 1)
  	return (-1);
      my_putchar('\n');
    }
  else
    if (my_exec(env, command[0], command) == 1)
      return (-1);
  return (0);
}

int		read_file(int fd_file)
{
  char		*str;
  int		fd_output;

  fd_output = open_tmp_file();
  while ((str = get_next_line(fd_file)) != NULL)
    {
      if (str == NULL)
	return (-1);
      write(fd_output, str, my_strlen(str));
      write(fd_output, "\n", 1);
    }
  return (0);
}

int		s_arrow_left(char **command, char **file, char **env, int point)
{
  int		fd_file;
  char		**rm;

  (void)point;
  if ((rm = malloc(sizeof(char *) * 3)) == NULL)
    return (-1);
  if ((rm = init_rm(rm)) == NULL)
    return (-1);
  if (file == NULL)
    return (-1);
  if ((fd_file = open(file[0], O_RDONLY)) == -1)
    {
      my_putstr("The file doesn't exist\n");
      return (-1);
    }
  if ((read_file(fd_file)) == -1)
    return (-1);
  s_arrow_exec(command, env);
  if (my_exec(env, rm[0], rm) == 1)
    return (-1);
  free(rm);
  return (0);
}
