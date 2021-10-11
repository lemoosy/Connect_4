#include <stdio.h>
#include <stdlib.h> /*for system("cls")*/


#define SIZE_MATRIX_X 8
#define SIZE_MATRIX_Y 8
#define TOKEN 4


void matrix_printf(int matrix[][SIZE_MATRIX_X])
{
    for (int y = 0; y < SIZE_MATRIX_Y; y++)
    {
        for (int x = 0; x < SIZE_MATRIX_X; x++)
            printf("%d", matrix[y][x]);

        printf("\n");
    }
}

int matrix_is_full(int matrix[][SIZE_MATRIX_X])
{
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
            if (matrix[y][x] == 0)
                return 0;

    return 1;
}

void matrix_fill(int matrix[][SIZE_MATRIX_X], int value)
{
    for (int y = 0; y < SIZE_MATRIX_Y; y++)
        for (int x = 0; x < SIZE_MATRIX_X; x++)
            matrix[y][x] = value;
}

int out_of_dimension(int x, int y)
{
    return x < 0 || x >= SIZE_MATRIX_X || y < 0 || y >= SIZE_MATRIX_Y;
}

int check_winner(int matrix[][SIZE_MATRIX_X])
{
    // position initial -> (x, y)
    for (int y = 0; y < SIZE_MATRIX_Y; y++)
        for (int x = 0; x < SIZE_MATRIX_X; x++)

            // vecteurs i & j
            for (int j = -1; j < 2; j++)
                for (int i = -1; i < 2; i++)

                    // alpha correspond au curseur
                    for (int a = 0; a < TOKEN; a++)

                        if (!out_of_dimension(x + a * i, y + a * j) && !(j == 0 && i == 0))

                            // S'il n'y a aucun jeton dans la case OU le jeton est différent du premier
                            if (matrix[y + a * j][x + a * i] == 0 || matrix[y + a * j][x + a * i] != matrix[y][x])
                                break;

                            // S'il y a X jetons alignés
                            else if (a == TOKEN - 1)
                                return matrix[y][x];

    return 0;
}

int main()
{
    int matrix[SIZE_MATRIX_Y][SIZE_MATRIX_X];
    int x = 0;
    int player = 1;
    int winner = 0;

    matrix_fill(matrix, 0);

    while (1)
        while (1)
        {
            if (matrix_is_full(matrix))
            {
                printf("\nPersonne n'a gagn%c :(\n\n", 130);
                system("pause");
                return 0;
            }

            system("cls");
            printf("Au tour du joueur %d de jouer :\n\n", player);
            matrix_printf(matrix);
            printf("\nChoisi une case : ");
            scanf_s("%d", &x);

            if (0 <= x < SIZE_MATRIX_X && matrix[0][x] == 0)
            {
                for (int y = SIZE_MATRIX_Y - 1; y >= 0; y--)
                    if (matrix[y][x] == 0)
                    {
                        matrix[y][x] = player;
                        break;
                    }

                winner = check_winner(matrix);

                if (winner)
                {
                    system("cls");
                    matrix_printf(matrix);
                    printf("\nLe joueur %d a gagn%c !\n\n", player, 130);
                    system("pause");
                    return 0;
                }

                player += 1;

                if (player == 3)
                    player = 1;

                break;
            }
        }
}