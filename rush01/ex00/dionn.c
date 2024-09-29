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
    int i = 0;
    int j;

    matrix = (char **)malloc(4 * sizeof(char *));
    if (matrix == NULL)
        return 0;
    while (i < 4)
    {
        matrix[i] = (char *)malloc(4 * sizeof(char));
        if (matrix[i] == NULL)
            return 0;
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

int is_valid(char **grid, int row, int col, char num)
{
    int i = 0;
    while (i < 4)
    {
        if (grid[row][i] == num || grid[i][col] == num)
            return 0;
        i++;
    }
    return 1;
}
void print_grid(char **grid)
{
    int i = 0;
    int j;

    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            write(1, &grid[i][j], 1);  // Stampa il numero
            if (j < 3)
                write(1, " ", 1);     // Aggiungi uno spazio tranne per l'ultimo numero
            j++;
        }
        write(1, "\n", 1);  // Vai a capo dopo ogni riga
        i++;
    }
}

int vis_ltor(char **grid, int r)
{
    int hmax = 0;
    int visible = 0;
    int i = 0;
    while (i < 4)
    {
        if (grid[r][i] - '0' > hmax)
        {
            visible++;
            hmax = grid[r][i] - '0';
        }
        i++;
    }
    return visible;
}

int vis_rtol(char **grid, int r)
{
    int hmax = 0;
    int visible = 0;
    int i = 3;
    while (i >= 0)
    {
        if (grid[r][i] - '0' > hmax)
        {
            visible++;
            hmax = grid[r][i] - '0';
        }
        i--;
    }
    return visible;
}

int vis_utod(char **grid, int c)
{
    int hmax = 0;
    int visible = 0;
    int i = 0;
    while (i < 4)
    {
        if (grid[i][c] - '0' > hmax)
        {
            visible++;
            hmax = grid[i][c] - '0';
        }
        i++;
    }
    return visible;
}

int vis_dtou(char **grid, int c)
{
    int hmax = 0;
    int visible = 0;
    int i = 3;
    while (i >= 0)
    {
        if (grid[i][c] - '0' > hmax)
        {
            visible++;
            hmax = grid[i][c] - '0';
        }
        i--;
    }
    return visible;
}

int check_visibility(char **grid, char *views)
{
    int i = 0;
    while (i < 4)
    {
        if (vis_utod(grid, i) != views[i] - '0')
            return 0;
        if (vis_dtou(grid, i) != views[i + 4] - '0')
            return 0;
        if (vis_ltor(grid, i) != views[i + 8] - '0')
            return 0;
        if (vis_rtol(grid, i) != views[i + 12] - '0')
            return 0;
        i++;
    }
    return 1;
}

int solve_grid(char **grid, char *views)
{
    int row = 0;
    int col;
    char num;

    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            if (grid[row][col] == '0') // Cerca cella vuota
            {
                num = '1';
                while (num <= '4') // Prova numeri da 1 a 4
                {
                    if (is_valid(grid, row, col, num)) // Valida inserimento
                    {
                        grid[row][col] = num;
                        if (solve_grid(grid, views)) // Chiamata ricorsiva
                            return 1;
                        grid[row][col] = '0'; // Backtrack
                    }
                    num++;
                }
                return 0; // Se nessun numero va bene, ritorna 0
            }
            col++;
        }
        row++;
    }

    // Se griglia completa, controlla visibilità
    if (check_visibility(grid, views))
    {
        print_grid(grid);
        return 1; // Soluzione valida trovata
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
        write(1, "Error\n", 6);
    }

    // Libera la memoria
    int i = 0;
    while (i < 4)
    {
        free(matrix[i]);
        i++;
    }
    free(matrix);
    free(views);

    return 0;
}

