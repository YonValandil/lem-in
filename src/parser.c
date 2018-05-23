#include "lemin.h"

void	init_vars(t_lemin *core, char *line)
{
	core->ants_start = core->nb_ants;
	core->ants_end = 0;
	// core->init = 1;
	// core->initlinks = 0;
	// core->i = 1;
	core->antnum = 1;
	core->room_begin = NULL;
	core->room_end = NULL;
	core->sizepath = 0;
	core->displayline = display_line(core->displayline, line);
}

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
	printf("\n----- nb_ants get = %d\n", lemin->nb_ants);
	init_vars(lemin, line);
	// ft_putendl(line);
	// lemin->displayline = display_line(lemin->displayline, line);//
}

void get_command(t_lemin *lemin, char *line)
{
	if(lemin->init == 0)
	{
		printf("\n----- %s : command invalid, ants pas encore init\n", line);
		return ;
	}
	else if (ft_strcmp(line, "##start") == 0 && lemin->init == 1)
	{
		lemin->command = COMMAND_START;
		printf("\n----- line get start : ");

	}
	else if (ft_strcmp(line, "##end") == 0 && lemin->init == 1)
	{
		lemin->command = COMMAND_END;
		printf("\n----- line get end : ");
	}
	else
	{
		printf("\n----- %s : command invalid\n", line);
		return ;
	}
	printf("----- command valid\n");
	// ft_putendl(line);
	lemin->displayline = display_line(lemin->displayline, line);//
}

void get_link(t_lemin *lemin, char *line, t_room **room)
{
	int		is_room_exist;
	t_room	*room_tmp;
	char 	**link_data; //free split

	room_tmp = *room;
	is_room_exist = 0;
	if (!(link_data = ft_strsplit(line, '-')))
		exit_error("Error: In get_link() ft_strsplit de link_data");
	if ((link_data[0] == NULL) || (link_data[1] == NULL) || (link_data[2] != NULL))
		exit_error("Error: In get_link() Parse error");
	printf("----- parcourt room:\n");
	while (room_tmp != NULL)
	{
		if ((ft_strcmp(link_data[0], room_tmp->name) == 0) && ++is_room_exist)
			lemin->ptr_tab_link[0] = room_tmp;
		else if ((ft_strcmp(link_data[1], room_tmp->name) == 0) && ++is_room_exist)
			lemin->ptr_tab_link[1] = room_tmp;
		printf("->%s", room_tmp->name);
		room_tmp = room_tmp->next;
	}
	printf("\n");
	if (is_room_exist == 2)
	{
		// lemin->displayline = display_line(lemin->displayline, line);//
		link_room(lemin); //putendl?
	}
	else
	{
		printf("\nsolver vient de => get_link (mauvais lien)\n");
		solver(lemin, *room);
	}
	lemin->displayline = display_line(lemin->displayline, line);//
}

t_room 	*parser(t_lemin *lemin, t_room *room)
{
	char *line;

	while ((get_next_line(0, &line)) > 0)
	{
		if(lemin->init == 0 && line[0] != '#')
			get_nb_ants(lemin, line);
		else if (line[0] == '#' && line[1] == '#')
			get_command(lemin, line);
		else if (line[0] == '#')
			// ft_putendl(line);
			lemin->displayline = display_line(lemin->displayline, line);
		else if (ft_strchr(line, '-'))
			get_link(lemin, line, &room);
		else
			room = init_room(lemin, line, &room);
		ft_memdel((void**)&line);
	}
	return (room);
}
