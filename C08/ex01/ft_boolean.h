// ft_boolean.h
#ifndef FT_BOOLEAN_H
#define FT_BOOLEAN_H

#include <unistd.h>

// Boolean type definition
typedef enum {
    FALSE = 0,
    TRUE = 1
} t_bool;

// Macros
#define SUCCESS 0
#define EVEN(nbr) (nbr % 2 == 0)
#define EVEN_MSG "I have an even number of arguments.\n"
#define ODD_MSG "I have an odd number of arguments.\n"

// Function prototypes
void ft_putstr(char *str);
t_bool ft_is_even(int nbr);

#endif // FT_BOOLEAN_H

