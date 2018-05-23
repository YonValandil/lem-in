/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:14:32 by jjourne           #+#    #+#             */
/*   Updated: 2018/05/15 08:54:54 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"

# include <stdio.h> //

# define BUF_SIZE 4096

enum { ROOM_NORMAL, ROOM_START, ROOM_END };
enum { COMMAND_NO, COMMAND_START, COMMAND_END };

typedef enum				e_bool
{
	false = 0,
	true
}							t_bool;

typedef struct				s_result
{
	int						path;
	struct s_room			*room;
}							t_result;

typedef struct				s_room
{
	int						id;
	char					*name;
	int						x;
	int						y;
	int						dist;//
	int						path;//
	int						ant;//
	char					*source;//
	t_bool					is_ant;
	struct s_room			**links;
	struct s_room			*next;
}							t_room;

typedef struct				s_lemin
{
	int						init;
	int						nb_ants;
	int						nb_rooms;
	int						command;
	int						antnum;//
	int						ants_start;//
	int						ants_end;//
	int						paths;//
	int						sizepath;//
	char					*displayline;//
	struct s_room			*ptr_tab_link[2];
	struct s_room			*room_begin;
	struct s_room			*room_end;
}							t_lemin;

void						exit_error(const char *s);
char						**check_init_room(t_lemin *lemin, char *line,
	t_room *room);
int 						check_link_room(t_lemin *lemin, t_room *room);
void 						link_room(t_lemin *lemin);
void 						get_nb_ants(t_lemin *lemin, char *line);
void						get_command(t_lemin *lemin, char *line);
void						get_link(t_lemin *lemin, char *line, t_room **room);
t_room						*init_room(t_lemin *lemin, char *line,
	t_room **room);
void 						init(t_lemin *lemin, t_room *room, char **line);
t_room 						*parser(t_lemin *lemin, t_room *room);
void 						solver(t_lemin *lemin, t_room *first_room);
int		maxpath(t_lemin *core);
int		checkpath(t_lemin *core, t_room *room, int dist);
void	pathnumber(t_lemin *core, t_room *begin);
t_room	*findplace(t_room *from, int path);
void	moovefromstart(t_lemin *core);
void	moovefromrooms(t_lemin *core, t_room *begin);
void	mooveants(t_lemin *core, t_room *begin);
void	putdist(t_room *room, int dist);
void	cleardist(t_room *begin);
void	printmoove(t_lemin *core, t_room *dest, int ant);
char	*display_line(char *display, char *str);
void	init_vars(t_lemin *core, char *line);
void	free_list(t_room *begin);

#endif
