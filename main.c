/*
** main.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Allum1
** 
** Made by Aur¨¦lien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Tue Feb  9 15:32:41 2016 Aur¨¦lien
** Last update Tue Feb 16 14:11:35 2016 Aurélien
*/

#include "my.h"

int	check_str(char *str)
{
  while (*str)
    {
      if (*str < '0' || *str > '9')
	return (-1);
      str++;
    }
  return (0);
}

int	check_line()
{
  int	nb;
  char	*buff;

  my_printf("Line: ");
  if ((buff = get_next_line(0)) == NULL)
    {
      my_printf("get_next_line_error\n");
      exit(0);
    }
  if (check_str(buff) == -1)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  nb = my_getnbr(buff);
  if (nb < 1 || nb > 4)
    {
      my_printf("Error: this line is out of range\n");
      return (-1);
    }
  return (nb);
}

int	check_matches(int nb_line, char **board)
{
  int	nb;
  char	*buff;

  my_printf("Matches: ");
  if ((buff = get_next_line(0)) == NULL)
      exit(0);
  if (check_str(buff) == -1)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (-1);
    }
  nb = my_getnbr(buff);
  if (nb > nb_matches_in_line(board, nb_line - 1))
    {
      my_printf("Error: not enough matches on this line\n");
      return (-1);
    }
  else if (nb < 1)
    {
      my_printf("Error: you have to remove at least one match\n");
      return (-1);
    }
  return (nb);
}

int	main()
{
  int	nb_line;
  int	nb_matches;
  t_ia	pr_ia;
  char	**board;

  board = alloc_2d_array_pyra(4);
  board = remp_pyra_array(4, board);
  print_board(board);
  while (end_of_game(board, 4) != -1)
    {
      my_printf("\nYour turn:\n");
      while ((nb_line = check_line()) == -1 ||
	     (nb_matches = check_matches(nb_line, board)) == -1);
      my_printf("Player removed %d match(es) form line %d\n",
	     nb_matches, nb_line);
      board = print_updated_board_game(nb_line, nb_matches, board);
      if (end_of_game(board, 4) == -1)
	return (my_printf("You lost, too bad..\n"));
      my_printf("\nAI's turn...\n");
      pr_ia = ia_turn(board);
      board = print_updated_board_game(pr_ia.line, pr_ia.matches, board);
    }
  my_printf("I lost.. snif.. but I'll get you next time!!\n");
  return (0);
}
