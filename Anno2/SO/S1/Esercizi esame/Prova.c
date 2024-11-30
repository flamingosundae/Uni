#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>

#define PIPE_WR 1
#define PIPE_RD 0

pid_t child1, child2;
int pipe1[2];
int pipe2[2];

int **define_matrix(int n, int m)
{
    int i, j;
    int **mat = malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++)
    {
        mat[i] = malloc(sizeof(int) * m);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            mat[i][j] = rand() % 10;
        }
    }
    return mat;
}

void print_matrix(int **mat, int n, int m)
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf(" %d ", mat[i][j]);
            if(j == m-1)
            {
                printf("\n");
            }
        }
    }
}

int *ottieni_colonna(int **mat1, int **mat2, int r, int c, int col)
{
    int *res = malloc(sizeof(int) * c);
    int i, k;
    for(i = 0; i < c; i++)
    {
        res[i] = 0;
        for(k = 0; k < r; k++)
        {
            res[i] += mat1[i][k] * mat2[k][col];
        }
    }
    return res;
}

void init_colonna(int **mat, int *col, int num_col, int r)
{
    int i;
    for(i = 0; i < r; i++)
    {
        mat[i][num_col] = col[i];
    }
}

int main()
{
    srand(time(NULL));
    if(pipe(pipe1) == -1 || pipe(pipe2) == -1)
    {
        perror("Errore creazione pipeline.");
        exit(1);
    }

    int **matA = define_matrix(3, 3);
    print_matrix(matA, 3, 3);
    int **matB = define_matrix(3, 3);
    print_matrix(matB, 3, 3);

    child1 = fork();
    if(child1 == 0)
    {
        int *prima_colonna = ottieni_colonna(matA, matB, 3, 3, 0);
        close(pipe1[PIPE_RD]);
        write(pipe1[PIPE_WR], prima_colonna, sizeof(int) * 3);
        free(prima_colonna);
        exit(0);
    }
    else
    {
        child2 = fork();
        if(child2 == 0)
        {
            int *seconda_colonna = ottieni_colonna(matA, matB, 3, 3, 1);
            close(pipe2[PIPE_RD]);
            write(pipe2[PIPE_WR], seconda_colonna, sizeof(int) * 3);
            free(seconda_colonna);
            exit(0);
        }
        else
        {
            int col1[3];
            int col2[3];
            int col3[3];

            close(pipe1[PIPE_WR]);
            close(pipe2[PIPE_WR]);

            read(pipe1[PIPE_RD], col1, sizeof(int) * 3);
            read(pipe2[PIPE_RD], col2, sizeof(int) * 3);

            int res_matrix[3][3];

            init_colonna((int **)res_matrix, col1, 0, 3);
            init_colonna((int **)res_matrix, col2, 1, 3);

            // Calcolare la terza colonna direttamente senza utilizzare una funzione separata
            for (int i = 0; i < 3; i++) {
                col3[i] = 0;
                for (int k = 0; k < 3; k++) {
                    col3[i] += matA[i][k] * matB[k][2];
                }
            }

            init_colonna((int **)res_matrix, col3, 2, 3);

            print_matrix((int **)res_matrix, 3, 3);

            // Deallocazione della memoria
            for (int i = 0; i < 3; i++)
            {
                free(matA[i]);
                free(matB[i]);
            }
            free(matA);
            free(matB);
        }
    }

    return 0;
}
