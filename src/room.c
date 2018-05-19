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

// int	check_room(char *line)
// {
	//test apres le split de init_room
	//longueur des nb_rooms
	//coordonnees chiffre
	//les noms en double
	//free
	//autres 'L'
// }

void link_room(t_lemin *lemin) //lst chainee de liens? ou ptr de ptr ?
{
	int i;
	int j;
	t_room *ptr_room1;
	t_room *ptr_room2;

	i = 0;
	j = 0;
	ptr_room1 = lemin->ptr_tab_link[0];
	ptr_room2 = lemin->ptr_tab_link[1];
	while (ptr_room1->links[i] != NULL)
		++i;
	while (ptr_room2->links[j] != NULL)
		++j;
	ptr_room1->links[i] = ptr_room2;
	ptr_room2->links[j] = ptr_room1;
}

t_room *init_room(t_lemin *lemin, char *line, t_room **room)
{
	t_room	*room_tmp;
	char	**room_data;

	room_tmp = *room;
	if (*line == 'L')
		exit_error("pas encore de solver, init_room() faux"); // solver();
	if (!(room_tmp = (t_room*)ft_memalloc(sizeof(t_room))))
		exit(EXIT_FAILURE);
	//pas de room avec le nom 0?
	if (!(room_data = ft_strsplit(line, ' ')) && !(room_data[0]))
		exit_error("Error: In init_room() ft_strsplit de room_data");
	room_tmp->name = ft_strdup(room_data[0]); //free
	room_tmp->next = *room;
	if (lemin->command == COMMAND_START)
		lemin->room_begin = room_tmp;
	else if (lemin->command == COMMAND_END)
		lemin->room_end = room_tmp;
	if (lemin->command == COMMAND_END || lemin->command == COMMAND_START)
		lemin->command = COMMAND_NO;
	room_tmp->id = lemin->nb_rooms++;
	//free split
	ft_putendl((const char *)line);
	return (room_tmp);
}
