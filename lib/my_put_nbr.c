/*
** my_put_nbr.c for my_put_nbr in /home/ayasch_d/rendu/Piscine_C_J03
** 
** Made by Dan Ayasch
** Login   <ayasch_d@epitech.net>
** 
** Started on  Thu Oct  2 10:49:30 2014 Dan Ayasch
** Last update Wed Apr 29 13:32:45 2015 Dan Ayasch
*/

#include "list.h"

int	my_putnbr(int nb)
{
  int	nombre;

  if (nb >= 0)
    {
      nb = -nb;
    }
  else
    my_putchar('-');
  nombre = 1;
  while (nb / nombre < -9)
    nombre = nombre * 10;
  while (nombre != 0)
    {
      my_putchar('0' - nb / nombre % 10);
      nb = nb % nombre;
      nombre = nombre / 10;
    }
  return (0);
}
