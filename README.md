# ft_printf

42 school project: recoding of the printf function (libc)

## Setup

Launch the Makefile command in the root repository : make

When libftprintf.a is ready, you can use ft_printf as printf, compiling with gcc : `-L'path to libftprintf.a' -lftprintf`.

### Prototypes

```c
int ft_printf(const char *format, ...);
int ft_dprintf(int fd, const char *format, ...);
```

### Feature

Conversions:
  - Numerical : dDioOuUxXp b(binary conversion)
  - Literal : cCsS

Conversion flags : h, hh, l, ll, j, z

Format flags : #0-+*
