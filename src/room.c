/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 03:25:21 by jjourne           #+#    #+#             */
/*   Updated: 2018/06/04 01:06:36 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**check_init_room(t_lemin *lemin, char *line, t_room *room)
{
	int		i;
	t_room	*room_i;
	char	**room_data;

	i = 0;
	room_i = room;
	if (*line == 'L')
		solver(lemin, room);
	if (!(room_data = ft_strsplit(line, ' ')))
		exit_error("Error: In init_room() ft_strsplit de room_data");
	while (room_data[i] != NULL)
		++i;
	if (i != 3)
		exit_error("In check_room() : Parse error");
	if (ft_strlen(room_data[0]) > 100)
		exit_error("In check room() : Name of the room too long");
	while (room_i != NULL)
	{
		if (!(ft_strcmp(room_data[0], room_i->name)))
			exit_error("Error parsing: 2 rooms with the same name");
		room_i = room_i->next;
	}
	return (room_data);
}

int		check_link_room(t_lemin *lemin, t_room *room)
{
	int	i;
	int	k;

	i = 0;
	if (!(room->links))
		if (!(room->links = (t_room**)ft_memalloc(sizeof(t_room*)
			* (lemin->nb_rooms))))
			exit(EXIT_FAILURE);
	while (room->links[i] != NULL)
	{
		k = 0;
		while (k < i)
		{
			if (room->links[i]->id == room->links[k]->id)
				exit_error("In link_room(): Parse error > multiple same links");
			++k;
		}
		++i;
	}
	return (i);
}

void	link_room(t_lemin *lemin)
{
	int		i;
	int		j;
	t_room	*ptr_room1;
	t_room	*ptr_room2;

	ptr_room1 = lemin->ptr_tab_link[0];
	ptr_room2 = lemin->ptr_tab_link[1];
	i = check_link_room(lemin, ptr_room1);
	ptr_room1->links[i] = ptr_room2;
	check_link_room(lemin, ptr_room1);
	j = check_link_room(lemin, ptr_room2);
	ptr_room2->links[j] = ptr_room1;
	check_link_room(lemin, ptr_room2);
}

t_room	*init_room(t_lemin *lemin, char *line, t_room **room)
{
	t_room	*room_new;
	char	**room_data;

	room_new = *room;
	if (!(room_new = (t_room*)ft_memalloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	room_data = check_init_room(lemin, line, *room);
	room_new->id = lemin->nb_rooms++;
	room_new->name = ft_strdup(room_data[0]);
	room_new->x = ft_atoi(room_data[1]);
	room_new->y = ft_atoi(room_data[2]);
	room_new->dist = -1;
	room_new->next = *room;
	if (lemin->command == COMMAND_START)
		lemin->room_begin = room_new;
	else if (lemin->command == COMMAND_END)
		lemin->room_end = room_new;
	if (lemin->command == COMMAND_END || lemin->command == COMMAND_START)
		lemin->command = COMMAND_NO;
	free_room(room_data);
	ft_putendl(line);
	return (room_new);
}
