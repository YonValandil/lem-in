/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:02:07 by jjourne           #+#    #+#             */
/*   Updated: 2018/05/12 07:07:01 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	exit_error(const char *s)
{
	ft_putendl_fd(s, 2);
	exit(EXIT_FAILURE);
}

//display_line
	

void 	main_parser(t_lemin *lemin, t_room *room, char **line)
{
	if(lemin->init == 0) //-- if first time, init lemin
		init_lemin(lemin, line);
	else if //-- ##, init_startend
		init_start_end(lemin, line, &room);
	else if //-- -, init link
		init_link(lemin, line, &room);
	else if //-- #, afficher la ligne
		display_line(lemin, line);
	else //-- init_room
		init_room(lemin, line, &room);
}

int		main(int argc, char *argv[])
{
	t_lemin		lemin;
	t_room		*room;
	char		**line;

	(void)argv;
	if (argc != 1)
		exit_error("Error: nombre d'arguments incorrecte.");
	ft_bzero(&lemin, sizeof(lemin));
	while ((get_next_line(0, &line)) > 0)
	{
		main_parser(&lemin, room, line);
		ft_memdel((void**)line);
	}
	//solver
	return (0);
}

//------------------------------------------------------------------------------
//sauvegarder
	//rooms start / end (externe avec ptr sur room) (en interne, plusieurs type de room)
	//les chemins
	//parcourt profondeur/largeur, trouver un chemin, balancer

//-----main.c
//Main
	// boucle get_next_line
		//parsing
	//le solveur

//FUNC
	//main_parser

	//init_core

	//init_room

	//init_link

	//init_startend

	//solver

	//parcourt largeur

	//print_move



// TIPS
	// ne pas laisser les nom de salle avoir des tirets
	//interpretation: plusieurs start(error, le dernier?)
