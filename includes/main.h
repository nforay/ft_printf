#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <stdarg.h>

enum	e_state
{
	LETTER,
	FLAG,
	CONV,
	ERROR,
	END
};

# define FLAG_HH	"hh"
# define FLAG_LL	"ll"
# define FLAG_MINUS	"-"
# define FLAG_ZERO	"0"
# define FLAG_POINT	"."
# define FLAG_ASTER	"*"
# define FLAG_HASH	"#"
# define FLAG_SPACE	" "
# define FLAG_PLUS	"+"
# define FLAG_H		"h"
# define FLAG_L		"l"

# define ALLCONV	"cspdiuxX%nfge"

# define NB_FLAG	11
# define NB_CONV	13

# define TRUE	1
# define FALSE	0

# define HH			0x000001
# define LL			0x000002
# define MINUS		0x000004
# define ZERO		0x000008
# define POINT		0x000010
# define ASTER		0x000020
# define HASH		0x000040
# define SPACE		0x000080
# define PLUS		0x000100
# define H			0x000200
# define L			0x000400

# define C_CONV		0x0001000
# define S_CONV		0x0002000
# define P_CONV		0x0004000
# define D_CONV		0x0008000
# define I_CONV		0x0010000
# define U_CONV		0x0020000
# define X_CONV		0x0040000
# define XMAJ_CONV	0x0080000
# define PER_CONV	0x0100000
# define N_CONV		0x0200000
# define F_CONV		0x0400000
# define G_CONV		0x0800000
# define E_CONV		0x1000000

typedef struct		s_args
{
	char			c;
	char			*s;
	void			*p;
	int				d;
	int				i;
	unsigned int	u;
	char			*x;
	char			*xmaj;
}					t_args;

typedef struct	s_state_machine
{
	enum e_state	state;
	char			buffer[4096];
	int				len;
	char			*out;
	int				flag;
	t_args			args;
}				t_state_machine;

typedef int		(*t_function)(char *, t_state_machine *);

#endif
