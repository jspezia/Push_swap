#include "push_swap.h"

void			DBG(t_dlist *stack_a, t_dlist *stack_b)
{
	ft_putstr("a: ");
	ft_print_dlist(stack_a);
	ft_putstr("b: ");
	ft_print_dlist(stack_b);
}

typedef stuct		s_op
{
	char		*name;
	void		*op;
}					t_op;

int				main(int ac, char *av[])
{
	t_dlist		*stack_a;
	t_dlist		*stack_b;

	if (ac == 1)
		error_msg_exit("./push_swap <int> <int> <...>");
	stack_a = dlist_create();
	stack_b = dlist_create();
	fill_stack(stack_a, ++av);


	//DBG
	DBG(stack_a, stack_b);
	rotate(stack_a);
	DBG(stack_a, stack_b);
	reverse(stack_a);
	DBG(stack_a, stack_b);
	rotate(stack_b);
	DBG(stack_a, stack_b);
	//

	// exemples(list_ps);
	return (0);
}
