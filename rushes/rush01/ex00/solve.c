#include <unistd.h>

int check_visibility(char **m, char *views);

int is_valid(char **grid, int row, int col, int num)
{
    int i = 0;

    // Controlla se il numero esiste già nella riga o nella colonna
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

    while (i < 4)
    {
        write(1, grid[i], 4);
        write(1, "\n", 1);
        i++;
    }
}

int solve(char **matrix, char *views, int row, int col)
{
    int num;

    if (row == 4)
        return check_visibility(matrix, views);
    if (matrix[row][col] != '0')
        return solve(matrix, views, row + (col + 1) / 4, (col + 1) % 4);
    num = '1';
    while (num <= '4')
    {
        matrix[row][col] = num;
        if (solve(matrix, views, row + (col + 1) / 4, (col + 1) % 4))
            return 1;
        matrix[row][col] = '0'; // Backtrack
        num++;
    }
    return 0;
}

