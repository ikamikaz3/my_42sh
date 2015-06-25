/*
** my_prompt.c for prompt in /home/chuong_a/rendu/PSU_2014_minishell1
** 
** Made by Alex Chuong
** Login   <chuong_a@epitech.net>
** 
** Started on  Tue May  5 15:55:13 2015 Alex Chuong
** Last update Tue May  5 17:22:55 2015 Dan Ayasch
*/

#include <stdlib.h>
#include "list.h"

char	*my_prompt(char **env)
{
  char	*str;

  if (env[0] == NULL)
    return ("$> ");
  if ((str = my_getenv(env, "USER")) != NULL)
    {
      str = cpy_str2(str, "--> ");
      return (str);
    }
  else
    return ("$> ");
  return ("$> ");
}
