#include <stdio.h>

#define TABULEIRO 10
#define AGUA 0
#define TAMNAVIO 3
#define NAVIO 3
#define LINHA 10

int main()
{
    // Letras representando a linha do tabuleiro e números representando a coluna

    char linha[TABULEIRO] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    int coluna[TABULEIRO] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // 1. Criando o tabuleiro 10x10 (Matriz 10x10)

    int tabuleiro[TABULEIRO][TABULEIRO];

    // 2. Iniciando o tabuleiro com 0 representando a água

    for (int i = 0; i < TABULEIRO; i++)
    {
        for (int j = 0; j < TABULEIRO; j++)
        {

            tabuleiro[i][j] = AGUA;
        }
    }
    // 3. Definir posições dos navios na posição horizontal, vertical e diagonal

    // Navio horizontal
    int linhaH = 1, colunaH = 2;
    int linhaI = 2, colunaI = 8;
    for (int j = 0; j < TAMNAVIO; j++)
    {
        tabuleiro[linhaH][colunaH + j] = NAVIO;
    }
    for (int j = 0; j < TAMNAVIO; j++)
    {
        tabuleiro[linhaI + j][colunaI] = NAVIO;
    }

    // Navio diagonal para baixo à direita e para baixo à esquerda
    int linhaD = 3, colunaD = 3;
    int linhaF = 7, colunaF = 5;

    for (int i = 0; i < TAMNAVIO; i++)
    {
        if (tabuleiro[linhaD + i][colunaD + i] == AGUA)
        {
            tabuleiro[linhaD + i][colunaD + i] = NAVIO;
        }
    }

    for (int j = 0; j < TAMNAVIO; j++)
    {

        if ((linhaF + j) < TABULEIRO && (colunaF - j) >= 0)
        {
            tabuleiro[linhaF + j][colunaF - j] = NAVIO;
        }
    }

    printf("Tabuleiro batalha naval\n");

    // Exibir letras

    printf("   ");
    for (int j = 0; j < TABULEIRO; j++)
    {
        printf(" %c", linha[j]);
    }

    // Exibir números

    for (int i = 0; i < TABULEIRO; i++)
    {
        printf("\n %2d", coluna[i]);
        for (int j = 0; j < TABULEIRO; j++)
        {
            printf(" %d", tabuleiro[i][j]);
        }
    }

    return 0;
}
