#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_putstr(char *str) {
    while (*str) {
        ft_putchar(*str);
        str++;
    }
}

char **ft_crgrid(void) {
    char **matrix = malloc(4 * sizeof(char *));
    for (int i = 0; i < 4; i++) {
        matrix[i] = malloc(4 * sizeof(char));
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = '0'; // Imposta le celle iniziali a '0'
        }
    }
    return matrix;
}

int ft_calc_visibility(char **grid, int row) {
    int visibility = 0;
    int max_height = 0;
    for (int col = 0; col < 4; col++) {
        int current_height = grid[row][col] - '0'; // Converti char a int
        if (current_height > max_height) {
            max_height = current_height;
            visibility++;
        }
    }
    return visibility;
}

int ft_is_valid(char **grid, char *views, int row, int col, char num) {
    // Controllo duplicati
    for (int i = 0; i < 4; i++) {
        if (grid[row][i] == num || grid[i][col] == num) return 0;
    }
    // Controllo visibilità
    if (ft_calc_visibility(grid, row) != (views[row] - '0')) return 0;
    return 1;
}

int ft_solve_grid(char **grid, char *views, int row, int col) {
    if (row == 4) return 1;
    int next_row = col == 3 ? row + 1 : row;
    int next_col = col == 3 ? 0 : col + 1;

    for (char num = '1'; num <= '4'; num++) {
        if (ft_is_valid(grid, views, row, col, num)) {
            grid[row][col] = num; // Assegna il numero
            if (ft_solve_grid(grid, views, next_row, next_col)) return 1;
            grid[row][col] = '0'; // Backtrack
        }
    }
    return 0; // Nessuna soluzione trovata
}

void ft_print_matrix(char **matrix) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ft_putchar(matrix[i][j]);
            if (j < 3) ft_putchar(' ');
        }
        ft_putchar('\n');
    }
}

int main(int ac, char **av) {
    if (ac != 2) {
        ft_putstr("Error\n");
        return 0;
    }

    char *views = av[1];
    if (strlen(views) != 16) {
        ft_putstr("Error\n");
        return 0;
    }

    char **grid = ft_crgrid();
    if (!ft_solve_grid(grid, views, 0, 0)) {
        ft_putstr("Error\n");
    } else {
        ft_print_matrix(grid);
    }

    // Free memory
    for (int i = 0; i < 4; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

