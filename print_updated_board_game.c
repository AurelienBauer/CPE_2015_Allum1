/*
** print_updated_board_game.c for  in /home/aurelien/rendu/Bootstrap/CPE_2015_allum1_bootstrap
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Tue Feb  9 08:47:15 2016 Aurélien
** Last update Tue Feb  9 15:24:24 2016 Aurélien
*/

#include "my.h"

void	print_board(char **allum)
{
  int	i;
  int	nb_space;

  i = -1;
  my_printf("*********\n");
  while (++i < 4)
    {
      nb_space = -1;
      my_printf("*");
      while (++nb_space < ((7 - (i + i + 1)) / 2))
	my_printf(" ");
      my_printf("%s", allum[i]);
      while (--nb_space > -1)
	my_printf(" ");
      my_printf("*\n");
    }
  my_printf("*********\n");
}

char 	**print_updated_board_game(int line, int nb_matches, char **allum)
{
  int	i;
  int	j;

  i = -1;
  j = 0;
  while (allum[line - 1][j] != '|')
    j++;
  while (++i < nb_matches)
    allum[line - 1][i + j] = ' ';
  print_board(allum);
  return (allum);
}
