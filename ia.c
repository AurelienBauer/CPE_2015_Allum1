/*
** ia.c for  in /home/aurelien/rendu/Cycle_CPE/CPE_2015_Allum1
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Mon Feb 15 15:49:00 2016 Aurélien
** Last update Sun Feb 21 17:02:10 2016 Aurélien
*/

#include "my.h"

t_ia		found_first_pos(int *allum)
{
  t_ia		ia;

  ia.line = -1;
  while (++ia.line < 4)
    {
      if (allum[ia.line] > 0)
	{
	  ia.matches = rand() % allum[ia.line];
	  if (ia.matches == 0)
	    ia.matches++;
	  ia.line++;
	  return (ia);
	}
    }
}

t_ia		rm_all_allum_exep_one(int *allum)
{
  t_ia		ia;
  int		i;

  i = 0;
  while (allum[i] <= 0)
    i++;
  ia.line = i;
  if (allum[i] > 1)
    ia.matches = allum[i] - 1;
  else
    ia.matches = allum[i];
  return (ia);
}

t_ia		equil_line(t_ia *ia)
{
  t_ia		ia_ret;

  if (ia[0].matches == 1)
    ia_ret = ia[1];
  else if (ia[1].matches == 1)
    ia_ret = ia[0];
  else if (ia[0].matches > ia[1].matches)
    {
      ia_ret.line = ia[0].line;
      ia_ret.matches = ia[0].matches - ia[1].matches;
    }
  else if (ia[0].matches < ia[1].matches)
    {
      ia_ret.line = ia[1].line;
      ia_ret.matches = ia[1].matches - ia[0].matches;
    }
  else
    {
      ia_ret.line = ia[0].line + 1;
      ia_ret.matches = 1;
    }
  ia_ret.line++;
  return (ia_ret);
}

t_ia		egal_allum_towline(int *allum)
{
  t_ia		*ia;
  int		i;
  int		j;

  j = 0;
  i = -1;
  if ((ia = malloc(sizeof(t_ia) * 2)) == NULL)
    exit(1);
  while (++i < 4)
    {
      if (allum[i] > 0)
	{
	  ia[j].line = i;
	  ia[j].matches = allum[i];
	  j++;
	}
    }
  return (equil_line(ia));
}

t_ia		ia_turn(char **board)
{
  t_ia		ia;
  int		*allum;

  allum = number_allum(board);
  if (pilenb(board) == 1)
    ia = rm_all_allum_exep_one(allum);
  else if (pilenb(board) == 2)
    ia = egal_allum_towline(allum);
  else
    ia = found_first_pos(allum);
  my_printf("AI removed %d match(es) from line %d\n",
	    ia.matches, (ia.line));
  return (ia);
}
