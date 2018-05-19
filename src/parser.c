#include "lemin.h"

void get_nb_ants(t_lemin *lemin, char *line)
{
	int i;

	i = 0;
	if (!line)
		exit_error("Error: In get_nb_ants() line not found");
	while (line[i])
	{
		if (!(ft_isdigit(line[i])))
		{
			ft_memdel((void**)&line);
			exit_error("Error: In get_nb_ant() line is not a number");
		}
		++i;
	}
	lemin->nb_ants = ft_atoi(line);
	if (lemin->nb_ants <= 0)
		exit_error("Error: In get_nb_ants() ants not found");
	lemin->init = 1;
	ft_putendl("tmp debug nb_ants real :"); //display line?
	ft_putendl(line); //display line?
	printf("get_nb_ants done, nb_ants get = %d", lemin->nb_ants);
}

void get_command(t_lemin *lemin, char *line)
{
	if (ft_strcmp(line, "##start") == 0)
		lemin->command = COMMAND_START;
	else if (ft_strcmp(line, "##end") == 0)
		lemin->command = COMMAND_END;
	else
		return ;
	ft_putendl(line); //display line?
}

void get_link(t_lemin *lemin, char *line, t_room **room)
{
	int		is_room_exist;
	t_room	*room_tmp;
	char 	**link_data; //free split

	room_tmp = *room;
	is_room_exist = 0;
	if (!(link_data = ft_strsplit(line, '-')) && !(link_data[0]) && !(link_data[1]))
		exit_error("Error: In get_link() ft_strsplit de link_data");
	while (room_tmp != NULL)
	{
		if ((ft_strcmp(link_data[0], room_tmp->name) == 0) && ++is_room_exist)
			lemin->ptr_tab_link[0] = room_tmp;
		if ((ft_strcmp(link_data[1], room_tmp->name) == 0) && ++is_room_exist)
			lemin->ptr_tab_link[1] = room_tmp;
		room_tmp = room_tmp->next;
	}
	if (is_room_exist == 2)
		// link_room(lemin);
		exit_error("connection des deux room. pas encore de link_room()");
	else
		exit_error("pas encore de solver, get_link() faux"); // solver();
	ft_putendl(line);
	//init_link?
}

void 	parser(t_lemin *lemin, t_room *room)
{
	char *line;

	while ((get_next_line(0, &line)) > 0)
	{
		if(lemin->init == 0 && line[0] != '#')
			get_nb_ants(lemin, line);
		else if (lemin->init == 1 && line[0] == '#' && line[1] == '#')
			get_command(lemin, line);
		else if (*line == '#')
			ft_putendl(line);
		else if (ft_strchr(line, '-'))
			get_link(lemin, line, &room);
		else
			room = init_room(lemin, line, &room);
		ft_memdel((void**)&line);
	}
}
