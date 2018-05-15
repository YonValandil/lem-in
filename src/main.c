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

//display_move

int		main(int argc, char *argv[])
{
	t_lemin		lemin;
	t_room		*room;
	char		**line;

	(void)argv;
	if (argc != 1)
		exit_error("Error: nombre d'arguments incorrecte.");
	ft_bzero(&lemin, sizeof(lemin));
	parser(&lemin, room, line);
	// solver(&lemin, room); //pas besoin de la ligne
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
