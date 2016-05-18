/*
** remp_board.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Allum1
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Tue Feb  9 15:22:57 2016 Aurélien
** Last update Tue Feb  9 15:27:50 2016 Aurélien
*/

#include "my.h"

char    **alloc_2d_array_pyra(int nb_line)
{
  char  **array;
  int   i;

  if ((array = malloc(sizeof(char*) * nb_line)) == NULL)
    exit(1);
  i = -1;
  while (++i < nb_line)
    {
      if ((array[i] = malloc(sizeof(char) * (i + 2 + i))) == NULL)
	exit(1);
    }
  return (array);
}

char    **remp_pyra_array(int nb_line, char **array)
{
  int   i;
  int   j;

  i = -1;
  while (++i < nb_line)
    {
      j = -1;
      while (++j < (i + i + 1))
	array[i][j] = '|';
      array[i][j] = '\0';
    }
  return (array);
}
