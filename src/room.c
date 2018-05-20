/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 03:25:21 by jjourne           #+#    #+#             */
/*   Updated: 2018/05/12 07:06:47 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**check_room(char *line, t_room *room)
{
	int i;
	t_room *room_i;
	char **room_data;

	i = 0;
	room_i = room;
	if (*line == 'L')
		exit_error("pas encore de solver, init_room() faux"); // solver();
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

void check_link_room(t_lemin *lemin, t_room *room)
{
	
}

void link_room(t_lemin *lemin)
{
	int i;
	int j;
	int k;
	t_room *ptr_room1;
	t_room *ptr_room2;

	i = -1;
	j = -1;
	ptr_room1 = lemin->ptr_tab_link[0];
	ptr_room2 = lemin->ptr_tab_link[1];
	if (!(ptr_room1->links))
		if (!(ptr_room1->links = (t_room**)ft_memalloc(sizeof(t_room*) * (lemin->nb_rooms))))
			exit(EXIT_FAILURE);
	if (!(ptr_room2->links))
		if (!(ptr_room2->links = (t_room**)ft_memalloc(sizeof(t_room*) * (lemin->nb_rooms))))
			exit(EXIT_FAILURE);
	while (ptr_room1->links[++i] != NULL)
	{
		k = -1;
		while (++k < i)
			if (ptr_room1->links[i]->id == ptr_room1->links[k]->id)
				exit_error("In link_room() : Parse error -> multiple same links");
	}
	while (ptr_room2->links[++j] != NULL)
	{
		k = -1;
		while (++k < j)
			if (ptr_room2->links[j]->id == ptr_room2->links[k]->id)
				exit_error("In link_room() : Parse error -> multiple same links");
	}
	ptr_room1->links[i] = ptr_room2;
	ptr_room2->links[j] = ptr_room1;
	printf("\n----- [%s]-[%s]\n", ptr_room2->links[j]->name, ptr_room1->links[i]->name);
}

t_room *init_room(t_lemin *lemin, char *line, t_room **room)
{
	t_room	*room_new;
	char	**room_data;

	room_new = *room;
	if (!(room_new = (t_room*)ft_memalloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	room_data = check_room(line, *room);
	room_new->id = lemin->nb_rooms++;
	room_new->name = ft_strdup(room_data[0]); //free
	room_new->x = ft_atoi(room_data[1]);
	room_new->y = ft_atoi(room_data[2]);
	room_new->next = *room;
	if (lemin->command == COMMAND_START)
	{
		lemin->room_begin = room_new;
		printf("\n-----room start: %s\n", room_new->name);
	}
	else if (lemin->command == COMMAND_END)
	{
		lemin->room_end = room_new;
		printf("\n-----room end: %s\n", room_new->name);
	}
	if (lemin->command == COMMAND_END || lemin->command == COMMAND_START)
		lemin->command = COMMAND_NO;
	//free et free split
	ft_putendl((const char *)line);
	return (room_new);
}
