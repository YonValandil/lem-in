#include "lemin.h"

void get_nb_ant(t_lemin *lemin, char **line)
{
	//si line exist
	//si le 1 caractere n'est pas #
	//TANT QUE c'est un chiffre, on continu a parcourir la ligne FIN
	//alors recuperer le nombre de fourmis = atoi();

	//si le nombre de fourmis est positif
	//init_vars

}

void get_start_end(t_lemin *lemin, char **line, t_room **room)
{
	//si debut (flag) == ft_strcmp(##start)
	// mettre room_begin sur le debut de la chaine (flag)
	//si fin (flag)
	// mettre room_end sur la fin de la chaine (flag)
	//si c'est rien return
	//
	//afficher la line = display_line();
	//get_next_line();
	//initialiser la room
	//
	// mettre room_begin sur le debut de la chaine = lemin->room_start = new;
	// mettre room_end sur la fin de la chaine = lemin->room_end = new;
}

void get_link(t_lemin *lemin, char **line, t_rom **room)
{
	//recupere et check les salles a mettre en liens
	//et si tout est ok appel (link_room) pour appliquer le lien

	//ft_strsplit() sur le - pour recup les valeurs
	//boucle pour parcourir les rooms et 
}

void init_room(t_lemin *lemin, char **line, t_room **room)
{

}

void 	parser(t_lemin *lemin, t_room *room, char **line)
{
	while ((get_next_line(0, line)) > 0)
	{
		if(lemin->init == 0) //-- if first time
			get_nb_ant(lemin, line);
		else if //-- if line == ##start or ##end
			get_start_end(lemin, line, &room);
		else if //-- if line link
			init_link(lemin, line, &room);
		else if //-- #, afficher la ligne
			display_line(lemin, line);
		else //-- init_room
			init_room(lemin, line, &room);
		ft_memdel((void**)line);
	}
}
