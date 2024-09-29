#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_visibility(char **grid, char *views);
int solve_grid(char **grid, char *views);
void print_grid(char **grid);

int ft_strlen(char *str)
{
    int c = 0;
    while (*str != '\0')
    {
        str++;
        c++;
    }
    return c;
}

char **crgrid(void)
{
    char **matrix;
    int i, j;

    matrix = (char **)malloc(4 * sizeof(char *));
    if (matrix == NULL)
        return 0;
    for (i = 0; i < 4; i++)
    {
        matrix[i] = (char *)malloc(4 * sizeof(char));
        if (matrix[i] == NULL)
            return 0;
        for (j = 0; j < 4; j++)
            matrix[i][j] = '0';
    }
    return matrix;
}

int is_valid(char **grid, int row, int col, char num)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
    }
    return 1;
}

void print_grid(char **grid)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        write(1, grid[i], 4);
        write(1, "\n", 1);
    }
}

int vis_ltor(char **grid, int r)
{
    int hmax = 0;
    int visible = 0;
    for (int i = 0; i < 4; i++)
    {
        if (grid[r][i] - '0' > hmax)
        {
            visible++;
            hmax = grid[r][i] - '0';
        }
    }
    return visible;
}

int vis_rtol(char **grid, int r)
{
    int hmax = 0;
    int visible = 0;
    for (int i = 3; i >= 0; i--)
    {
        if (grid[r][i] - '0' > hmax)
        {
            visible++;
            hmax = grid[r][i] - '0';
        }
    }
    return visible;
}

int vis_utod(char **grid, int c)
{
    int hmax = 0;
    int visible = 0;
    for (int i = 0; i < 4; i++)
    {
        if (grid[i][c] - '0' > hmax)
        {
            visible++;
            hmax = grid[i][c] - '0';
        }
    }
    return visible;
}

int vis_dtou(char **grid, int c)
{
    int hmax = 0;
    int visible = 0;
    for (int i = 3; i >= 0; i--)
    {
        if (grid[i][c] - '0' > hmax)
        {
            visible++;
            hmax = grid[i][c] - '0';
        }
    }
    return visible;
}

int check_visibility(char **grid, char *views)
{
    for (int i = 0; i < 4; i++)
    {
        if (vis_utod(grid, i) != views[i] - '0')
            return 0;
        if (vis_dtou(grid, i) != views[i + 4] - '0')
            return 0;
        if (vis_ltor(grid, i) != views[i + 8] - '0')
            return 0;
        if (vis_rtol(grid, i) != views[i + 12] - '0')
            return 0;
    }
    return 1;
}

int solve_grid(char **grid, char *views)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (grid[row][col] == '0')
            {
                for (char num = '1'; num <= '4'; num++)
                {
                    if (is_valid(grid, row, col, num))
                    {
                        grid[row][col] = num;
                        if (solve_grid(grid, views))
                            return 1;
                        grid[row][col] = '0';
                    }
                }
                return 0;
            }
        }
    }
    if (check_visibility(grid, views))
    {
        print_grid(grid); // Mostra la soluzione trovata
        return 1;         // Soluzione valida trovata
    }
    return 0;
}

char *extract_views(char *str, char **matrix)
{
    int i = 0, j = 0;
    char *views = (char *)malloc(16 * sizeof(char));
    if (!views)
        return NULL;

    while (str[i])
    {
        if (str[i] >= '1' && str[i] <= '4')
        {
            views[j++] = str[i];
        }
        i++;
    }

    if (j != 16)
        return "Error";

    return views;
}

int main(int ac, char **av)
{
    if (ac != 2)
    {
        write(1, "Error\n", 6);
        return 1;
    }

    char **matrix = crgrid();
    if (!matrix)
    {
        write(1, "Error\n", 6);
        return 1;
    }

    char *views = extract_views(av[1], matrix);
    if (*views == 'E')
    {
        write(1, "Error\n", 6);
        return 1;
    }

    if (!solve_grid(matrix, views))
    {
        write(1, "No solution found\n", 18);
    }

    // Free memory
    for (int i = 0; i < 4; i++)
        free(matrix[i]);
    free(matrix);
    free(views);

    return 0;
}

