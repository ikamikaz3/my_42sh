/*
** built_in.c for built_in in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Thu May  7 16:45:25 2015 Dan Ayasch
** Last update Sun May 24 16:30:23 2015 Dan Ayasch
*/

#include <unistd.h>
#include <stdlib.h>
#include "list.h"

int		my_exit(char **env, char **s)
{
  (void)env;
  (void)s;
  return (-2);
}

int		my_env(char **env, char **s)
{
  int		i;

  i = 0;
  (void)s;
  while (env[i] != NULL)
    {
      my_putstr(env[i]);
      my_putstr("\n");
      i = i + 1;
    }
  return (1);
}

int		my_unsetenv(char **env, char **s)
{
  int		i;
  int		j;
  char		*str;

  i = 0;
  j = 0;
  if (s[1] == NULL)
    {
      my_putstr("Unsetenv need 1 arg\n");
      return (1);
    }
  while (env[i])
    {
      str = env_name(env[i]);
      if (my_strcmp(s[1], str) == 0)
        j = j + 1;
      env[i++] = my_strcat(env[j++]);
      if (env[j] == NULL)
        env[i] = NULL;
    }
  return (1);
}

char		**my_cd2(char **env, char **s, t_param_env param)
{
  char		*str1;
  int		a;

  a = 0;
  a = recup_pwd(env, &param);
  if (my_strcmp(s[1], "-") == 0)
    env = cd_minus(env, param, s, a);
  else if (my_strcmp(s[1], "~") == 0)
    {
      if ((str1 = my_getenv(env, "HOME")) == NULL)
  	return (NULL);
      if (chdir(str1) == -1)
  	my_putstr("Not a directory\n");
    }
  else
    {
      if (chdir(s[1]) == -1)
  	my_putstr("Not a directory\n");
      if (a == 1)
  	{
  	  modif_oldpwd(env, &param);
  	  modif_cd(env, &param, s);
  	}
    }
  return (env);
}

int		my_cd(char **env, char **s)
{
  t_param_env	param;
  int		a;

  a = 0;
  a = recup_pwd(env, &param);
  if (s[1] == NULL)
    {
      if (my_strcmp(s[0], "..") == 0)
	{
	  if (chdir("../") == -1)
	    my_putstr("Not a directory\n");
	  if (a == 1)
	    {
	      modif_oldpwd(env, &param);
	      modif(env, &param);
	    }
	}
      else if (my_getenv(env, "HOME") == NULL)
        my_putstr("'HOME' doesn't existe anymore, you can't go there\n");
      else if (chdir(my_getenv(env, "HOME")) == -1)
        my_putstr("Not a directory\n");
    }
  else
    env = my_cd2(env, s, param);
  return (1);
}
