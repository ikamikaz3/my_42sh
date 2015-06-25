/*
** built_in2.c for built_in2 in /home/gizard_a/rendu/PSU_2014_42sh
** 
** Made by Claire Gizard
** Login   <gizard_a@epitech.net>
** 
** Started on  Wed May 13 14:17:49 2015 Claire Gizard
** Last update Sun May 24 14:17:46 2015 Dan Ayasch
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "list.h"

int		recup_pwd(char **env, t_param_env *param)
{
  int		y;

  y = 0;
  param->y_pwd = 0;
  param->y_old_pwd = 0;
  while (env[y] != NULL)
    {
      if (env[y][0] == 'P' && env[y][1] == 'W' && env[y][2] == 'D')
	param->y_pwd = y;
      if (env[y][0] == 'O' && env[y][1] == 'L' && env[y][2] &&
	  env[y][3] == 'P' && env[y][4] == 'W' && env[y][5] == 'D')
	param->y_old_pwd = y;
      ++y;
    }
  if (param->y_pwd == 0)
    return (0);
  return (1);
}

int		modif_cd(char **env, t_param_env *param, char **s)
{
  int		i;
  char		**save;

  i = 0;
  if (env[1] == NULL)
    return (1);
  save = my_str_to_wordtab(s[1], '/');
  while (save[i])
    {
      if (save[i][0] == '.' && save[i][1] == '.')
	{
	  modif(env, param);
	  ++i;
	}
      else
	{
	  modif_cd_norm(env, param, save[i]);
	  ++i;
	}
    }
  return (0);
}

int		fill_pwd(char **env, t_param_env *param, int lim)
{
  int		x;

  x = 0;
  while (env[param->y_pwd][x] != '\0')
    {
      if (x == lim)
	{
	  while (env[param->y_pwd][x] != '\0')
	    env[param->y_pwd][x++] = ' ';
	}
      if (env[param->y_pwd][x] == '\0')
	break;
      ++x;
    }
  return (0);
}

int		modif(char **env, t_param_env *param)
{
  int		taille;
  int		lim;

  if (param->y_pwd == 0)
    return (0);
  taille = my_strlen(env[param->y_pwd]);
  env[param->y_old_pwd] = cpy_str2("OLD", env[param->y_pwd]);
  while (taille >= 0)
    {
      if (env[param->y_pwd][taille] == '/')
  	{
  	  lim = taille;
  	  break;
  	}
      taille--;
    }
  fill_pwd(env, param, lim);
  return (0);
}

int		modif_oldpwd(char **env, t_param_env *param)
{
  if (param->y_pwd == 0)
    return (0);
  env[param->y_old_pwd] = " ";
  env[param->y_old_pwd] = cpy_str2("OL", "D");
  env[param->y_old_pwd] = cpy_str2(env[param->y_old_pwd], env[param->y_pwd]);
  return (0);
}
