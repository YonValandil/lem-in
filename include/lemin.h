/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjourne <jjourne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 16:14:32 by jjourne           #+#    #+#             */
/*   Updated: 2018/05/01 12:06:09 by jjourne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>
# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"

# include <stdio.h> //

# define BUF_SIZE 4096

typedef enum				e_bool
{
	false = 0,
	true
}							t_bool;

typedef struct				s_lemin
{
	int						tmp;
}							t_filler;

void						exit_error(const char *s);

#endif
