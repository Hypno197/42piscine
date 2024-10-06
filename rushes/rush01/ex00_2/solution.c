/*int ft_calc_visibility(char *line)
{
    int visible_count = 1;
    int max_height = line[0] - '0';
    int i = 1;

    while (i < 4)
    {
        if (line[i] - '0' > max_height)
        {
            visible_count++;
            max_height = line[i] - '0';
        }
        i++;
    }
    return visible_count;
}
*/

int ft_calc_visibility(char **grid, int row)
{
    int visibility = 0;
    int max_height = 0;

    for (int col = 0; col < 4; col++)
    {
        int current_height = grid[row][col] - '0'; // Converti char a int
        if (current_height > max_height)
        {
            max_height = current_height;
            visibility++;
        }
    }
    return visibility;
}

/*
int ft_is_valid(char **grid, int row, int col, char num)
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

int ft_solve_grid(char **grid, int row, int col)
{
    int next_row;
    int next_col;
    char num = '1';

	if (row == 4)
		return 1;
	if (col == 3)
    {
        next_row = row + 1;
        next_col = 0;
    }
    else
    {
        next_row = row;
        next_col = col + 1;
    }

    while (num <= '4')
    {
        if (ft_is_valid(grid, row, col, num))
        {
            grid[row][col] = num;

            if (ft_solve_grid(grid, next_row, next_col))
                return 1;

            grid[row][col] = '0';
        }
        num++;
    }
    return 0;
}
*/
int ft_check_visibility(char **matrix, char *views)
{
    int i = 0;
    while (i < 4)
    {
        char col[4] = { matrix[0][i], matrix[1][i], matrix[2][i], matrix[3][i] };
        if (ft_calc_visibility(col) != views[i] - '0')
            return 0;
        i++;
    }
    return 1;
}
int ft_is_valid(char **grid, int row, int col, char num)
{
    // Controllo riga
    for (int i = 0; i < 4; i++)
    {
        if (grid[row][i] == num)
            return 0;
    }
    
    // Controllo colonna
    for (int i = 0; i < 4; i++)
    {
        if (grid[i][col] == num)
            return 0;
    }
    
    return 1;
}

int ft_solve_grid(char **grid, int row, int col)
{
    if (row == 4) // Tutti i livelli sono riempiti
        return 1;

    // Calcola la prossima cella
    int next_row = col == 3 ? row + 1 : row;
    int next_col = col == 3 ? 0 : col + 1;

    char num = '1';
    while (num <= '4')
    {
        if (ft_is_valid(grid, row, col, num))
        {
            grid[row][col] = num; // Assegna il numero
            
            if (ft_solve_grid(grid, next_row, next_col)) // Prova la prossima cella
                return 1;

            grid[row][col] = '0'; // Backtrack
        }
        num++; // Prova il prossimo numero
    }

    return 0; // Nessuna soluzione trovata
}

