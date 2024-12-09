#include <stdlib.h>

char dest[] = "pippo";

char **fnc(void)
{
    int i;
    char **mtx;
    mtx = (char **)malloc((3 + 1) * sizeof(char *));
    while( i < 3)
    {
    char *dest;
    dest = (char *)malloc((5 + 1) * sizeof(char));
     if (dest == NULL)
     {
        while (i > 0)
        {
            free(mtx[i]);
            i--;
        }
        free(mtx);
     }
    mtx[i] = dest;
    }
    mtx[i] = NULL;
    return dest;
}

int main()
{
    char **str;

    str = fnc();
    
    return 0;
}

while

free(mtx [0], 1, 2, 3)
free(mtx)
mtx[0] = *dest1
mtx[1] = *dest2
mtx[2] = *dest3
mtx[3] = NULL;