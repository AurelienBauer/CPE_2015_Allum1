/*
** parc_board.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Allum1
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Tue Feb  9 15:20:22 2016 Aurélien
** Last update Mon Feb 15 16:42:01 2016 Aurélien
*/

#include "my.h"

int	nb_matches_in_line(char **board, int line)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (board[line][i])
    {
      if (board[line][i] == '|')
	count++;
      i++;
    }
  return (count);
}

int	pilenb(char **board)
{
  int	line;
  int	count;

  line = -1;
  count = 0;
  while (++line < 4)
    {
      if (nb_matches_in_line(board, line) > 0)
	count++;
    }
  return (count);
}

int	*number_allum(char **board)
{
  int	*allum;

  if ((allum = malloc(sizeof(int) * 4)) == NULL)
    exit (0);
  allum[0] = nb_matches_in_line(board, 0);
  allum[1] = nb_matches_in_line(board, 1);
  allum[2] = nb_matches_in_line(board, 2);
  allum[3] = nb_matches_in_line(board, 3);
  return (allum);
}

int	end_of_game(char **board, int line)
{
  int	i;
  int	j;

  i = -1;
  while (++i < line)
    {
      j = 0;
      while (board[i][j])
	{
	  if (board[i][j] == '|')
	    return (0);
	  j++;
	}
    }
  return (-1);
}
