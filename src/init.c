#include "libft.h"
#include "dlist.h"
#include <stdlib.h>
#include "push_swap.h"
#include <unistd.h>

t_dlist			*parse(char **av, t_dlist *dlist)
{
	int			*nb;

	while (*av)
	{
		if (!ft_str_isint(*av))
			error_msg_exit(ft_strjoin(*(av), " is not an int."));
		nb = (int *)malloc((sizeof(int)));
		*nb = ft_atoi(*av++);
		dlist_push_back(dlist, nb);
	}
	return (dlist);
}

t_list_ps		*init_list(void)
{
	t_list_ps		*list_ps;


	if (!(list_ps = malloc(sizeof(t_list_ps))))
		error_msg_exit("malloc t_list_ps fail");
	list_ps->a = dlist_create();
	list_ps->b = dlist_create();
	return (list_ps);
}
