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

void init_nb_ant(t_lemin *lemin, char **line)
{
	//si line exist
	//si le 1 caractere n'est pas #
	//TANT QUE c'est un chiffre, on continu a parcourir la ligne FIN
	//alors recuperer le nombre de fourmis = atoi();

	//si le nombre de fourmis est positif
	//init_vars

}

void init_start_end(t_lemin *lemin, char **line, t_room **room)
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

void init_link(t_lemin *lemin, char **line, t_rom **room)
{

}

void init_room(t_lemin *lemin, char **line, t_room **room)
{

}

void 	init(t_lemin *lemin, t_room *room, char **line)
{
	if(lemin->init == 0) //-- if first time, init lemin
		init_nb_ant(lemin, line);
	else if //-- ##, init_startend
		init_start_end(lemin, line, &room);
	else if //-- -, init link
		init_link(lemin, line, &room);
	else if //-- #, afficher la ligne
		display_line(lemin, line);
	else //-- init_room
		init_room(lemin, line, &room);
}
