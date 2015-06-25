/*
** builtin_alias.c for alias in /home/ayasch_d/Home/rendu/PSU_2014_42sh/alias
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sun May 24 17:07:22 2015 Dan Ayasch
** Last update Sun May 24 17:41:01 2015 Dan Ayasch
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "list.h"

int	built_alias(char **env, char **save)
{
  char	*str;
  int	fd;

  (void)env;
  if ((fd = open("alias/alias", O_RDWR | O_APPEND, S_IRUSR | S_IWUSR)) == -1)
    fd = create_file("alias/alias");
  if (save[1] == NULL)
    {
      while ((str = get_next_line(fd)))
	{
	  my_putstr(str);
	  my_putchar('\n');
	}
    }
  else
    {
      write(fd, save[1], my_strlen(save[1]));
      write(fd, "\n", my_strlen("\n"));
    }
  return (0);
}
