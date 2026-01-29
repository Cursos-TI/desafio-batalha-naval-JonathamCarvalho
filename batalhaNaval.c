#include <stdio.h>

int main()
{
    // Letras representando a linha do tabuleiro

    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Números representando a coluna do tabuleiro

    int coluna[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 1. Criando o tabuleiro 10x10 (Matriz 10x10)

    int tabuleiro[10][10];

    // 2. Iniciando o tabuleiro com 0 representando a água

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {

            tabuleiro[i][j] = 0; // Inicializando todas as posições com 0
        }
    }
    // 3. Definir posições dos navios

    int navioHorizontal[3] = {3, 3, 3}; // Navio de tamanho 3 ocupando 3 posições horizontais
    int navioVertical[3] = {3, 3, 3};   // Navio de tamanho 3 ocupando 3 posições verticais

    // 4. Posições iniciais dos navios no tabuleiro

    int linhaNavioI = 1, colunaNavioI = 2; // Posição inicial do navio horizontal
    int linhaNavioJ = 3, colunaNavioJ = 3; // Posição inicial do navio vertical

    // 5. Utilizando loop aninhado para posição horizontal e vercical dos navios

    for (int j = 0; j < navioHorizontal[0]; j++)
    {
        tabuleiro[linhaNavioI][colunaNavioI + j] = 3; // Marcando a posição do navio com 3

        for (int i = 0; i < navioVertical[0]; i++)
        {
            tabuleiro[linhaNavioJ + i][colunaNavioJ] = 3; // Marcando a posição do navio com 3
        }
    }

    // 6. Exibindo as coordenadas do tabuleiro

    printf("Tabuleiro batalha naval\n");

    // Exibir letras

    printf("   ");
    for (int j = 0; j < 10; j++)
    {
        printf(" %c", linha[j]);
    }
    
    // Exibir números

    for (int i = 0; i < 10; i++)
    {
        printf("\n %2d", coluna[i]);
        for (int j = 0; j < 10; j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }
    }

    return 0;
}
