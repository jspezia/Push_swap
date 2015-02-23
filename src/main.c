#include "libft.h"
#include "dlist.h"
#include <stdlib.h>
#include "push_swap.h"
#include <unistd.h>

void			exemples(t_list_ps *list)
{
	ft_print_dlist2(list);
	sa(list->a);
	ft_print_dlist2(list);
	ft_putendl("ok");
}

int				main(int ac, char **av)
{
	t_list_ps		*list_ps;

	list_ps = init_list();
	if (ac == 1)
		error_msg_exit("./push_swap [list int]");
	list_ps->a = parse(++av, list_ps->a);
	exemples(list_ps);
	return (0);
}
