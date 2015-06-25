/*
** get_next_line.c for get_next_line in /home/ayasch_d/Dan/rendu/elcrypt
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sun Mar  1 13:45:53 2015 Dan Ayasch
** Last update Wed May  6 14:25:39 2015 Dan Ayasch
*/

#include <stdlib.h>
#include <unistd.h>
#include "list.h"

int		get_line(const int fd, char *line)
{
  static int	nb = LEN;
  static int	k = 0;
  static char	buff[LEN];

  if (k == 0 || k >= nb)
    {
      k = 0;
      if ((nb = read(fd, buff, LEN)) < 0)
	return (0);
    }
  if (nb == 0)
    {
      line[0] = '\0';
      k = -1;
    }
  else
    if (buff[k] == '\n')
      line[0] = '\0';
    else
      line[0] = buff[k];
  k = k + 1;
  return (nb);
}

char		*get_next_line(const int fd)
{
  char		*line;
  int		i;
  int		nb;

  i = 0;
  nb = 1;
  if ((line = malloc(sizeof(char) * 8096)) == NULL)
    return (NULL);
  nb = get_line(fd, line);
  if (nb == 0)
    return (NULL);
  while (line[i] != '\0')
      nb = get_line(fd, &line[++i]);
  line[++i] = '\0';
  return (line);
}
