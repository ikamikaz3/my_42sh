/*
** my_puterr.c for puterr in /home/ayasch_d/Home/rendu/PSU_2014_42sh
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Sun May 24 15:48:05 2015 Dan Ayasch
** Last update Sun May 24 15:48:39 2015 Dan Ayasch
*/

#include <unistd.h>
#include "list.h"

void	my_puterr(char *str)
{
  write(2, str, my_strlen(str));
}
