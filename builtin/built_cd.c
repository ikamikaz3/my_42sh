/*
** built_cd.c for built_cd in /home/gizard_a/rendu/PSU_2014_42sh
** 
** Made by Claire Gizard
** Login   <gizard_a@epitech.net>
** 
** Started on  Tue May 19 11:36:52 2015 Claire Gizard
** Last update Sun May 24 16:29:46 2015 Dan Ayasch
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "list.h"

char	**cd_minus(char **env, t_param_env param, char **s, int a)
{
  char	*str;

  if ((str = my_getenv_pwd(env, "OLDPWD")) == NULL)
    return (NULL);
  if (chdir(str) == -1)
    my_putstr("Not a directory\n");
  my_putstr(str);
  my_putchar('\n');
  if (a == 1)
    {
      modif_oldpwd(env, &param);
      modif_cd(env, &param, s);
    }
  return (env);
}

int	modif_cd_norm(char **env, t_param_env *param, char *s)
{
  int	taille;
  int	j;
  int	i;

  i = 0;
  j = 0;
  taille = my_strlen(env[param->y_pwd]);
  while (i <= taille)
    {
      if (env[param->y_pwd][i] == ' ')
	{
	  env[param->y_pwd][i] = '/';
	  i++;
	  while (s[j] != '\0')
	    {
	      env[param->y_pwd][i] = s[j];
	      i++;
	      j++;
	    }
	  return (0);
	}
      i++;
    }
  return (0);
}
