#ifndef STRUCT_OP_H
# define STRUCT_OP_H

typedef struct		s_op
{
	char		*name;
	void		(*f)(struct s_ps *ps);
}					t_op;

#endif
