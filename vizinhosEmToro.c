#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 15

int contarVizinhos(int grade[2][M][N], int m, int n, int plano, int i, int j)
{
    int ki0, kj0, ki1, kj1, vivas = 0;
    for (ki0 = i - 1; ki0 <= i + 1; ki0++)
    {
        ki1 = ki0 == -1 ? m - 1 : (ki0 == m ? 0 : ki0);
        for (kj0 = j - 1; kj0 <= j + 1; kj0++)
        {
            kj1 = kj0 == -1 ? n - 1 : (kj0 == n ? 0 : kj0);
            if (grade[plano][ki1][kj1]) vivas++;
        }
    }
    if (grade[plano][i][j]) vivas--;
    return vivas;
}

int main(void)
{
    int i, j, grade[2][M][N];
    srand(time(NULL));
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            grade[0][i][j] = rand() % 4 == 0;
            printf("%2d", grade[0][i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++) printf("%2d", contarVizinhos(grade, M, N, 0, i, j));
        putchar('\n');
    }
    return 0;
}
