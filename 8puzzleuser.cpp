#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#define r 3
#define c 3
char matrix[r][c];
char old[r][c];
int count;
char final[r][c] = {{'1', '2', '3'}, {'8', ' ', '4'}, {'7', '6', '5'}};
int i, j,p, q, x, y,t,result=0;
char z;

void load()
{
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (old[i][j] == '0'){
                matrix[i][j] = ' ';
                continue;
            }
            matrix[i][j] = old[i][j];
        }
    }
}

void blank()
{
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            old[i][j] = ' ';
        }
    }
}

int main()
{
    time_t T = time(NULL);
    struct tm tm = *localtime(&T);
    char f[4];
    int rsl;
    int random, t;
    int randvalues[9];
	main:
    count = 0;
    blank();
    T = time(NULL);
    tm = *localtime(&T);
    srand(tm.tm_sec);
    while (count != 9)
    {
        rsl = rand() % 9;
        sprintf(f, "%d", rsl);
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if ((old[i][j]) == f[0])
                {
                    i = 4;
                    j = 4;
                    continue;
                } else if ((old[i][j]) == ' ')
                {
                    old[i][j] = f[0];
                    i = 4;
                    j = 4;
                    count++;
                }
            }
        }
    }
    load();
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("|%c|", matrix[i][j]);
        }
        printf("\n");
    }

    while (1) {
        printf("enter value to change its position to blank space\n");
        scanf(" %c", &z);
        if (z == 'q') {
            printf("\n*****You Quit*****\n");
            goto main;
        }
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if ((matrix[i][j]) == z) {
                    p = i;
                    q = j;
                } else if ((matrix[i][j]) == ' ')
                {
                    x = i;
                    y = j;
                }
            }
        }
        t = 0;
        int m, n;
        m = p - 1;
        n = q;
        if (m >= 0)
        {
            if ((matrix[m][n]) == ' ') t = 1;
        }
        m = p + 1;
        if (m <= 2)
        {
            if ((matrix[m][n]) == ' ') t = 1;
        }
        m = p;
        n = q - 1;
        if (n >= 0)
        {
            if ((matrix[m][n]) == ' ') t = 1;
        }
        n = q + 1;
        if (n <= 2)
        {
            if ((matrix[m][n]) == ' ') t = 1;
        }
        if (t == 1)
        {
            matrix[x][y] = z;
            matrix[p][q] = ' ';
        }
        t = 0;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                if ((matrix[i][j]) == final[i][j])
                {
                    t++;
                }
            }
        }
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                printf("|%c|", matrix[i][j]);
            }
            printf("\n");
        }
        if (t == 9)
        {
            printf("\n****you Win****\n");
            break;
        }
    }
    return 1;
}
