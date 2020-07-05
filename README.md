[![Codacy Badge](https://app.codacy.com/project/badge/Grade/8990d84117844fdcb01e555e822cca94)](https://www.codacy.com/manual/nforay/ft_printf?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=nforay/ft_printf&amp;utm_campaign=Badge_Grade)
# ft_printf
*This project is pretty straight forward. You will recode printf.*

## Note
***109/100*** :white_check_mark:

## Prototype
int ft_printf(char const *format, ...)

## Utilisation
Conversions : "%c %s %p %d %i %u %x %X %% %n" :white_check_mark:

Flags : "-0.\* *(space)* #+" :white_check_mark:

Modificateur de longueur : "hh ll h l" :white_check_mark:

Précision : :white_check_mark:

Largeur de champ : :white_check_mark:

Norme : :white_check_mark:

Gestion d'erreur : :white_check_mark:

## Testers

***100/100*** :white_check_mark:
Trace: https://gist.github.com/nforay/030700dc5705800084b808d584095ad8

https://github.com/jkgithubrep/42_printf_unit_tests

https://github.com/cclaude42/PFT_2019

https://github.com/t0mm4rx/ftprintfdestructor

https://github.com/hbaudet/Tests

# Deepthrought

= test_fields ==================================================================

-rw-r--r--  1 deepthought  deepthought  108056 Mar  9 22:12 libftprintf.a

clang -Wall -Wextra -Werror -g3   -c -o test_s.o test_s.c
clang -Wall -Wextra -Werror -g3   -c -o test_d.o test_d.c
clang -Wall -Wextra -Werror -g3   -c -o test_p.o test_p.c
clang -Wall -Wextra -Werror -g3   -c -o test_x.o test_x.c
clang -Wall -Wextra -Werror -g3   -c -o test_i.o test_i.c
clang -Wall -Wextra -Werror -g3   -c -o test_u.o test_u.c
clang -Wall -Wextra -Werror -g3   -c -o test_c.o test_c.c
clang -Wall -Wextra -Werror -g3   -c -o test_mix.o test_mix.c
clang -Wall -Wextra -Werror -g3   -c -o main.o main.c
clang -Wall -Wextra -Werror -g3 -o test_printf -L. -lftprintf test_s.o test_d.o test_p.o test_x.o test_i.o test_u.o test_c.o test_mix.o main.o

test_s: [ok]
test_d: [ok]
test_p: [ok]
test_x: [ok]
test_i: [ok]
test_u: [ok]
test_c: [ok]
test_mix: [ok]

8/8 correct functions
Grade: 50

= test_fields ==================================================================

-rw-r--r--  1 deepthought  deepthought  108056 Mar  9 22:12 libftprintf.a

clang -Wall -Wextra -Werror -g3   -c -o test_precision.o test_precision.c
clang -Wall -Wextra -Werror -g3   -c -o test_zero.o test_zero.c
clang -Wall -Wextra -Werror -g3   -c -o test_minus.o test_minus.c
clang -Wall -Wextra -Werror -g3   -c -o test_star.o test_star.c
clang -Wall -Wextra -Werror -g3   -c -o main.o main.c
clang -Wall -Wextra -Werror -g3 -o test_printf -L. -lftprintf test_precision.o test_zero.o test_minus.o test_star.o main.o

test_precision: [ok]
test_zero: [ok]
test_minus: [ok]
test_star: [ok]

4/4 correct functions
Grade: 50

= bonus_test ===================================================================

-rw-r--r--  1 deepthought  deepthought  108056 Mar  9 22:12 libftprintf.a

clang -Wall -Wextra -Werror -g3   -c -o test_n.o test_n.c
clang -Wall -Wextra -Werror -g3   -c -o test_f.o test_f.c
clang -Wall -Wextra -Werror -g3   -c -o test_e.o test_e.c
clang -Wall -Wextra -Werror -g3   -c -o test_g.o test_g.c
clang -Wall -Wextra -Werror -g3   -c -o test_l.o test_l.c
clang -Wall -Wextra -Werror -g3   -c -o test_ll.o test_ll.c
clang -Wall -Wextra -Werror -g3   -c -o test_h.o test_h.c
clang -Wall -Wextra -Werror -g3   -c -o test_hh.o test_hh.c
clang -Wall -Wextra -Werror -g3   -c -o test_space.o test_space.c
clang -Wall -Wextra -Werror -g3   -c -o test_plus.o test_plus.c
clang -Wall -Wextra -Werror -g3   -c -o test_hashtag.o test_hashtag.c
clang -Wall -Wextra -Werror -g3   -c -o main.o main.c
clang -Wall -Wextra -Werror -g3 -o test_printf -L. -lftprintf test_n.o test_f.o test_e.o test_g.o test_l.o test_ll.o test_h.o test_hh.o test_space.o test_plus.o test_hashtag.o main.o

test_n: [ok]
test_f: [ko]
test_g: [ko]
test_e: [ko]
test_l: [ok]
test_ll: [ok]
test_h: [ko]
test_hh: [ok]
test_hashtag: [ko]
test_space: [ok]
test_plus: [ok]

6/11 correct functions
Grade: 8

= Final grade: 108 =============================================================
