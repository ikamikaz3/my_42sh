/*
** echo_sign.c for echo in /home/ayasch_d/Home/rendu/PSU_2014_42sh/builtin
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sat May 23 18:39:33 2015 Dan Ayasch
** Last update Sat May 23 18:43:15 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

char	*exec_echo$(char **s, char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s[1] != NULL)
    {
      if (s[1][i] == '$')
        {
          i++;
          while (s[1][i] != '\0')
            {
              str[j] = s[1][i];
              i++;
              j++;
            }
          str[j] = '\0';
          return (str);
        }
      ++i;
    }
  return (NULL);
}

int	echo_$(char **s, char **env)
{
  char	*str;
  char	*str2;

  if ((str = malloc(sizeof(char) * my_strlen(s[1]))) == NULL)
    return (1);
  str = exec_echo$(s, str);
  if ((str2 = my_getenv(env, str)) == NULL)
    return (1);
  my_putstr(str2);
  my_putchar('\n');
  return (0);
}
