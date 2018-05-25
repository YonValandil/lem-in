#include "lemin.h"

void	printmoove(t_lemin *lemin, t_room *dest, int ant)
{
	if (dest->id == lemin->room_end->id)
		lemin->ants_end++;
	if (!ant)
	{
		dest->ant = lemin->antnum;
		lemin->antnum++;
	}
	else
		dest->ant = ant;
	ft_printf("L%d-%s", dest->ant, dest->name);//
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
