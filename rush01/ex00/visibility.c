int vis_ltor(char **grid, int r)
{
    int hmax;
    int visible;
    int i;

    i = 0;
    visible = 1;
    hmax = grid[r][0];
    while(i < 4)
    {
        if(grid[r][i] > hmax)
        {
            visible++;
            hmax = grid[r][i];
        }
    i++;
    }
    return visible;
}

int vis_rtol(char **grid, int r)
{
    int hmax;
    int visible;
    int i;

    i = 3;
    visible = 1;
    hmax = grid[r][3];
    while(i >= 0 )
    {
        if(grid[r][i] > hmax)
        {
            visible++;
            hmax = grid[r][i];
        }
    i--;
    }
    return visible;
}


int vis_dtou(char **grid, int r)
{
    int hmax;
    int visible;
    int i;

    i = 3;
    visible = 1;
    hmax = grid[3][i];
    while(i >= 0 )
    {
        if(grid[i][r] > hmax)
        {
            visible++;
            hmax = grid[i][r];
        }
    i--;
    }
    return visible;
}

int vis_utod(char **grid, int r)
{
    int hmax;
    int visible;
    int i;

    i = 0;
    visible = 1;
    hmax = grid[0][i];
    while(i < 3)
    {
        if(grid[i][r] > hmax)
        {
            visible++;
            hmax = grid[i][r];
        }
    i++;
    }
    return visible;
}

int check_visibility(char **m, char *views)
{
    int i = 0;
    while (i < 4)
    {
        if (vis_utod(m, i) != views[i] - '0' || vis_dtou(m, i) != views[i + 4] - '0')
            return 0;
        if (vis_ltor(m, i) != views[i + 8] - '0' || vis_rtol(m, i) != views[i + 12] - '0')
            return 0;
        i++;
    }
    return 1;
}
