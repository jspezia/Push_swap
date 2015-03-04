#ifndef STRUCT_OP_H
# define STRUCT_OP_H

typedef struct		s_op
{
	char		*name;
	void		(*f)(t_ps *ps);
}					t_op;

#endif
