#include "lemin.h"

// 3
// ##start
// 0 1 0
// ##end
// 1 5 0
// 2 9 0
// 3 13 0
// 0-2
// 2-3
// 3-1

void get_nb_ants(t_lemin *lemin, char *line)
{
	//si line exist
	//si le 1 caractere n'est pas # (commentaire)
	//TANT QUE c'est un chiffre, on continu a parcourir la ligne
	//SI la ligne ne contient que des chiffre
	//ALORS recuperer le nombre de fourmis => atoi();
	//CHECK si le nombre de fourmis est positif
	//init_vars

	int i;

	i = 0;
	if (!line)
		exit_error("Error: In get_nb_ants() line not found");
	// if (*line[0] != '#')
	// {
		while (line[i])
		{
			if (ft_isdigit(line[i]))
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
	// }
	// else if (*line[0] == '#' && *line[1] == '#')
		//display line
}

t_room *get_start_end(t_lemin *lemin, char *line, t_room **room)
{
	//si debut (flag) == ft_strcmp(##start)
	// mettre room_begin sur le debut de la chaine (flag)
	//si fin (flag)
	// mettre room_end sur la fin de la chaine (flag)
	//si c'est rien return
	//
	//afficher la line = display_line();
	//get_next_line(); //lire la ligne d'apres pour get la room du start/end
	//initialiser la room
	//
	// mettre room_begin sur le debut de la chaine = lemin->room_start = new;
	// mettre room_end sur la fin de la chaine = lemin->room_end = new;

	int flag;
	t_room *new_room;

	new_room = NULL;
	if (ft_strcmp(line, "##start") == 0)
		flag = START;
	else if (ft_strcmp(line, "##end") == 0)
		flag = END;
	else
		return (*room); //?
	//afficher la ligne
	//
	if (get_next_line(fd, &line) <= 0)
		exit_error("Error: In get_start_end() get_next_line failed");
	//initialiser la room
	//
	//l'associer au start ou au endif
	if (flag == START)
		lemin->room_begin = new_room;
	else
		lemin->room_end = new_room;
	//free et return
	ft_memdel((void**)&line);
	return (new_room);
}

void get_link(t_lemin *lemin, char **line, t_rom **room)
{
	//recupere et check les salles a mettre en liens
	//et si tout est ok appel (link_room) pour appliquer le lien

	//ft_strsplit() sur le - pour recup les valeurs
	//boucle pour parcourir les rooms
	//strcmp() entre le nom du lien et de la boucle
	//et next pour continuer la boucle
}

void init_room(t_lemin *lemin, char **line, t_room **room)
{
	//initialiser les variables pour une room,
	//ft_strsplit() => le nombre//les coordonnees x y (facultatif)
	//les liens
	//si c'est une room de start ou de end

}

void 	parser(t_lemin *lemin, t_room *room, char *line)
{
	while ((get_next_line(0, line)) > 0)
	{
		if(lemin->init == 0 && line[0] != '#') //-- if first time
			get_nb_ant(lemin, line);
		else if (lemin->init == 1 && line[0] == '#' && line[1] == '#')//-- check if line == ##start or ##end
			get_start_end(lemin, line, &room);
		else if (*line == '#')//-- #, afficher la ligne
			//lemin->display_line = display_line(lemin, line);
		else if (ft_strchr(line, "-"))//-- if line link *****a check
			get_link(lemin, line, &room);
		else //-- init_room
			init_room(lemin, line, &room);
		ft_memdel((void**)line);
	}
}
