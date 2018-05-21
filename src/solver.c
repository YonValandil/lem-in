#include "lemin.h"

////////////////////////////////////////PATH////////////////////////////////////
int		maxpath(t_lemin *core)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (!core->room_end->links || !core->room_begin->links)
		exit_error("In maxpath : not link on room_begin or room_end");
	while (core->room_end->links[a])
		++a;
	while (core->room_begin->links[b])
		++b;
	return (a < b ? a : b);
}

int		checkpath(t_lemin *core, t_room *room, int dist)
{
	int		a;
	t_room	*path;
	t_room	*tmp;

	while (room->links && (room->id != core->room_end->id))
	{
		path = NULL;
		a = 0;
		dist = -1;
		while (room->links && room->links[a])
		{
			tmp = room->links[a++];
			if ((dist == -1 || tmp->dist <= dist) && !tmp->path)
			{
				path = tmp;
				dist = tmp->dist;
			}
		}
		if (!path)
			return (0);
		path->path = core->paths;
		core->sizepath++;
		room = path;
	}
	return (1);
}

void	pathnumber(t_lemin *core, t_room *begin)
{
	int	max;

	max = maxpath(core);
	core->paths = 1;
	core->room_end->path = 0;
	core->room_begin->path = 1;
	checkpath(core, core->room_begin, 0);
	cleardist(begin);
	putdist(core->room_end, 1);
	core->paths++;
	while (core->paths <= max && (core->nb_ants > core->sizepath))
	{
		core->room_end->path = 0;
		core->room_begin->path = 1;
		if (checkpath(core, core->room_begin, 0))
			core->paths++;
		else
			max--;
		cleardist(begin);
		putdist(core->room_end, 1);
	}
}
/////////////////////////////MOVE///////////////////////////////////////////////
t_room	*findplace(t_room *from, int path)
{
	int		a;
	int		dist;
	t_room	*tmp;
	t_room	*dest;

	a = 0;
	dist = -1;
	while (from->links[a])
	{
		tmp = from->links[a];
		if ((tmp->path == path || tmp->path == -1) &&
		(dist < 0 || tmp->dist < dist))
		{
			dist = tmp->dist;
			dest = tmp;
		}
		++a;
	}
	return (dest);
}

void	moovefromstart(t_lemin *core)
{
	int		path;
	t_room	*dest;

	path = 1;
	while (core->ants_start && path != core->paths)
	{
		dest = findplace(core->room_begin, path);
		printmoove(core, dest, 0);
		core->ants_start--;
		path++;
		if (path != core->paths)
			printf(" ");//
	}
	printf("\n");//
}

void	moovefromrooms(t_lemin *core, t_room *begin)
{
	int		a;
	int		flag;
	t_room	*room;
	t_room	*dest;

	a = 1;
	while (a <= ((core->nb_ants - core->ants_start) + core->ants_end))
	{
		room = begin;
		flag = 0;
		while (room && !flag)
		{
			if (room->ant == a && (room->id != core->room_end->id))
			{
				dest = findplace(room, room->path);
				printmoove(core, dest, room->ant);
				if (a != core->nb_ants)
					printf(" ");//
				room->ant = 0;
				++flag;
			}
			room = room->next;
		}
		++a;
	}
}

void	mooveants(t_lemin *core, t_room *begin)
{
	core->room_end->path = -1;
	core->room_begin->path = 0;
	while (core->ants_end != core->nb_ants)
	{
		moovefromrooms(core, begin);
		moovefromstart(core);
	}
}

//////////////////////////////////////////DIST//////////////////////////////////
void	putdist(t_room *room, int dist)
{
	int		a;
	t_room	*tmp;
	char	*source;

	a = 0;
	source = ft_strdup(room->name);
	while (room->links && room->links[a])
	{
		tmp = room->links[a];
		if (tmp && !tmp->path && (tmp->dist == -1 || dist < tmp->dist))
		{
			tmp->dist = dist;
			if (tmp->source)
				free(tmp->source);
			tmp->source = ft_strdup(source);
			if (ft_strcmp(tmp->name, room->source))
				putdist(tmp, dist + 1);
		}
		++a;
	}
	free(source);
}

void	cleardist(t_room *begin)
{
	t_room	*tmp;

	tmp = begin;
	while (tmp)
	{
		if (!tmp->path)
			tmp->dist = -1;
		tmp = tmp->next;
	}
}

///////////////////////////////PRINT////////////////////////////////////////////
void	printmoove(t_lemin *core, t_room *dest, int ant)
{
	if (dest->id == core->room_end->id)
		core->ants_end++;
	if (!ant)
	{
		dest->ant = core->antnum;
		core->antnum++;
	}
	else
		dest->ant = ant;
	printf("L%d-%s", dest->ant, dest->name);//
}

char	*display_line(char *display, char *str)
{
	char	*new;

	new = NULL;
	if (!display)
	{
		display = ft_strnew(ft_strlen(str) + 1);
		display = ft_strcpy(display, str);
		display = ft_strcat(display, "\n");
	}
	else
	{
		if (!(new = (char*)malloc(sizeof(char) * ft_strlen(display) +
		ft_strlen(str) + 2)))
			exit_error("In display_line() : malloc");
		new[ft_strlen(display + ft_strlen(str))] = '\n';
		new[ft_strlen(display + ft_strlen(str) + 1)] = '\0';
		new = ft_strcpy(new, display);
		new = ft_strcat(new, str);
		new = ft_strcat(new, "\n");
		free(display);
		display = ft_strdup(new);
		free(new);
	}
	return (display);
}
////////////////////////////SOLVER//////////////////////////////////////////////
void solver(t_lemin *lemin, t_room *first_room)
{
	// if (!lemin->room_begin || !lemin->room_end || !first_room ||
		// (!(ft_strcmp(lemin->room_begin->name, lemin->room_end->name))))
		// exit_error("In solver() : Impossible to start solver");
	if (!lemin->room_begin)
		exit_error("In solver() : Pas de room_begin");
	if (!lemin->room_end)
		exit_error("In solver() : Pas de room_end");
	if (!first_room)
		exit_error("In solver() : Pas de first_room");

 // 	exit_error("solver imcomplet pour l'instant");//////////////
	lemin->room_end->source = ft_strdup(lemin->room_end->name);
	lemin->room_end->dist = 0;
	putdist(lemin->room_end, 1);
	if (lemin->room_begin->dist == -1)
		exit_error("In solver() : room_begin->dist == -1");
	printf("%s\n", lemin->displayline);//
	// ft_putendl("afficher displayline ici si necessaire");
	// free(lemin->displayline);
	pathnumber(lemin, first_room);
	mooveants(lemin, first_room);
	printf("test/////////////////////////////////////////\n");
	// free_list(first_room);
	exit(1);
}
