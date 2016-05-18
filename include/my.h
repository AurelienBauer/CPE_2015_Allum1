/*
** my.h for my_h_ in /home/bauer_b/rendu/Piscine_C_infinadd/include
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Mon Oct 26 19:04:41 2015 Aurélien BAUER
** Last update Mon Feb 15 16:43:07 2016 Aur�lien
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>

/*
***
fonction lib
***
*/

typedef	struct	s_ia
{
  int		line;
  int		matches;
}		t_ia;

int		my_power_it(int nb, int power);
void		my_putchar(char c);
char		my_putnbr(int nbr);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_nbrlen(int nbr);
char		*my_revstr(char *str);
int		my_put_unsignednbr(unsigned int nbr);
int		my_printf(const char *str, ...);
int		put_convert_to_nbase(unsigned int nbr, int base, char b);
int		put_convert_to_oct(char rest);
int		maj_S(const char *str);
int		make_d_i(int nbr);
int		make_c(int c);
int		make_s(char *str);
int		make_u(unsigned int nbr);
int		make_p(long long nbr);
int		my_getnbr(char  *str);
int		my_nbrlen_array(int *array);
char		*my_clchar_in_str(char *str, char car);
char		*my_strcat(char *data, char *add);
char		*uint_to_char(unsigned int nbr);
int		fs_open_file(char *filepath);
void		fs_understand_return_of_read(int fd, char *buffer, int size);
char		*get_next_line(const int fd);
char		**my_str_to_wordtab(char *str);
char		**my_str_to_wordtab(char *str);
char		*my_strcpy(char *str, char *dest);

/*
***
parc_board.c
***
*/
int		nb_matches_in_line(char **board, int line);
int		pilenb(char **board);
int		*number_allum(char **board);
int		end_of_game(char **board, int line);

/*
***
remp_board.c
***
*/
char		**alloc_2d_array_pyra(int nb_line);
char		**remp_pyra_array(int nb_line, char **array);

/*
***
Print_udated_board_game.c
***
*/
void		print_board(char **allum);
char		**print_updated_board_game(int line, int nb_matches, char **allum);

/*
***
main.c
***
*/
int		check_line();
int		check_matches(int nb_line, char **board);

/*
***
ia.c
***
*/
t_ia            ia_turn(char **board);

#endif /* !MY_H_ */
