#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str);
void ft_putstr(char *str);
void ft_putchar(char c);
int	ft_strcmp(char *s1, char *s2);
int ft_calc_visibility(char *line);
int ft_is_valid(char **grid, int row, int col, char num);
int ft_solve_grid(char **grid, int row, int col);
int ft_check_visibility(char **matrix, char *views);

char **ft_crgrid(void)
{
    char    **matrix;
    int     i = 0, j;

    matrix = (char **)malloc(4 * sizeof(char *));
    if (matrix == NULL)
        return NULL;
    while (i < 4)
    {
        matrix[i] = (char *)malloc(4 * sizeof(char));
        if (matrix[i] == NULL)
            return NULL;
        j = 0;
        while (j < 4)
        {
            matrix[i][j] = '0';
            j++;
        }
        i++;
    }
    return matrix;
}

int ft_conditions(char *cu, char *cd, char *rl, char *rr)
{
    int i = 0;
    while (i < 4)
    {
        if ((cu[i] == '4' && cd[i] != '1') || (cd[i] == '4' && cu[i] != '1'))
            return 0;
        if ((rl[i] == '4' && rr[i] != '1') || (rr[i] == '4' && rl[i] != '1'))
            return 0;
        if ((cu[i] + cd[i] - '0' * 2) > 5 || (rl[i] + rr[i] - '0' * 2) > 5)
            return 0;
        i++;
    }
    return 1;
}

int ft_validate(char *str)
{
    char colup[4], coldwn[4], rowlt[4], rowrt[4];
    int i = 0;

    while (i < 16)
    {
        if (i < 4)
            colup[i] = str[i];
        else if (i < 8)
            coldwn[i % 4] = str[i];
        else if (i < 12)
            rowlt[i % 4] = str[i];
        else
            rowrt[i % 4] = str[i];
        i++;
    }
    return ft_conditions(colup, coldwn, rowlt, rowrt);
}

char *ft_extrval(char *str)
{
    int i = 0, j = 0;
    char *strex = (char *)malloc(16 * sizeof(char));

    if (!strex)
        return "Error";

    while (str[i])
    {
        if (str[i] >= '1' && str[i] <= '4')
        {
            strex[j] = str[i];
            j++;
        }
        i++;
    }
    if (ft_strlen(strex) != 16 || !ft_validate(strex))
    {
        free(strex);
        return "Error";
    }
    return strex;
}

void ft_print_matrix(char **matrix)
{
    int i = 0, j;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            ft_putchar(matrix[i][j]);
            if (j < 3)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int main(int ac, char **av)
{
    char    *views;
    char    **matrix;

    if (ac != 2)
    {
        ft_putstr("Error\n");
        return 0;
    }
    matrix = ft_crgrid();
    if (!matrix)
    {
        ft_putstr("Error\n");
        return 0;
    }
    views = ft_extrval(av[1]);
    if (ft_strcmp(views, "Error") == 0)
    {
        ft_putstr("Error\n");
        return 0;
    }
    if (ft_solve_grid(matrix, 0, 0))
        ft_print_matrix(matrix);
    else
    return 0;
}
