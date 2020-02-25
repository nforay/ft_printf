#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>

enum	e_state
{
	LETTER,
	FLAG,
	CONV,
	ERROR,
	END
};

# define DEBUG		0

# define FLAG_HH	"hh"
# define FLAG_LL	"ll"
# define FLAG_MINUS	"-"
# define FLAG_ZERO	"0"
# define FLAG_ASTER	"*"
# define FLAG_HASH	"#"
# define FLAG_SPACE	" "
# define FLAG_PLUS	"+"
# define FLAG_H		"h"
# define FLAG_L		"l"
# define FLAG_POINT	"."

# define ALLCONV	"cspdiuxX%nfge"

# define NB_FLAG	11
# define NB_CONV	13

# define TRUE	1
# define FALSE	0

# define HH			0x000001
# define LL			0x000002
# define MINUS		0x000004
# define ZERO		0x000008
# define ASTER		0x000010
# define HASH		0x000020
# define SPACE		0x000040
# define PLUS		0x000080
# define H			0x000100
# define L			0x000200
# define POINT		0x000400

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

/*
	ajout		flag |= HH
	enleve		flag &= ~HH
​
	test		if (flag & HH)
*/

typedef struct				s_args
{
	int						c;
	char					*s;
	void					*p;
	int						d;
	int						i;
	unsigned int			u;
	unsigned int			x;
	unsigned int			xmaj;
	int						*n;
	double					f;
	double					g;
	double					e;
	signed char				hhd;
	signed char				hhi;
	unsigned char			hhu;
	unsigned char			hhx;
	unsigned char			hhxmaj;
	signed char				*hhn;
	long long int			lld;
	long long int			lli;
	unsigned long long int	llu;
	unsigned long long int	llx;
	unsigned long long int	llxmaj;
	long long int			*lln;
	short int				hd;
	short int				hi;
	unsigned short int		hu;
	unsigned short int		hx;
	unsigned short int		hxmaj;
	short int				*hn;
	wchar_t					lc;
	wchar_t					*ls;
	long int				ld;
	long int				li;
	unsigned long int		lu;
	unsigned long int		lx;
	unsigned long int		lxmaj;
	long int				*ln;
}							t_args;

typedef struct				s_state_machine
{
	enum e_state			state;
	char					buffer[4096];
	int						len;
	char					*out;
	int						flag;
	int						fwidth;
	int						preci;
	t_args					args;
	va_list					params;
}							t_state_machine;

typedef int		(*t_function)(char *, t_state_machine *);

#endif
