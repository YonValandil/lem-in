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
	struct s_room			*ptr_tab_link[2];
	struct s_room			*room_begin;
	struct s_room			*room_end;
}							t_lemin;

void						exit_error(const char *s);
void 						get_nb_ants(t_lemin *lemin, char **line);
void						*get_command(t_lemin *lemin, char **line,
	t_room **room, int *room_state);
void						get_link(t_lemin *lemin, char **line, t_rom **room);
t_room						*init_room(t_lemin *lemin, char **line,
	t_room **room, int room_state);
void 						init(t_lemin *lemin, t_room *room, char **line);
void 						parser(t_lemin *lemin, t_room *room, char **line);

#endif
