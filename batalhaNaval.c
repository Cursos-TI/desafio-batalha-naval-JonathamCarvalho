#include <stdio.h>
#include <stdlib.h>

#define TABULEIRO 10
#define AGUA 0
#define TAMNAVIO 3
#define NAVIO 3
#define LINHA 10
#define AREA_AFETADA 5
#define HABILIDADE 5

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
    // 3. Navios no tabuleiro

    int linhaH = 0, colunaH = 5;
    int linhaJ = 7, colunaJ = 9;

    for (int j = 0; j < TAMNAVIO; j++)
        tabuleiro[linhaH][colunaH + j] = NAVIO;

    for (int j = 0; j < TAMNAVIO; j++)
        tabuleiro[linhaJ + j][colunaJ] = NAVIO;

    int linhaD = 7, colunaD = 5;
    int linhaF = 7, colunaF = 2;

    for (int i = 0; i < TAMNAVIO; i++)
        if (tabuleiro[linhaD + i][colunaD + i] == AGUA)
            tabuleiro[linhaD + i][colunaD + i] = NAVIO;

    for (int j = 0; j < TAMNAVIO; j++)
        if ((linhaF + j) < TABULEIRO && (colunaF - j) >= 0)
            tabuleiro[linhaF + j][colunaF - j] = NAVIO;

    // 4. Matrizes de habilidade

    int cone[HABILIDADE][HABILIDADE];
    int cruz[HABILIDADE][HABILIDADE];
    int octaedro[HABILIDADE][HABILIDADE];

    int centro = HABILIDADE / 2;

    // Cone (forma triangular)
    for (int i = 0; i < HABILIDADE; i++)
    {
        for (int j = 0; j < HABILIDADE; j++)
        {
            if (i <= centro && j >= centro - i && j <= centro + i)
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // Cruz (forma de cruz)
    for (int i = 0; i < HABILIDADE; i++)
        for (int j = 0; j < HABILIDADE; j++)
            cruz[i][j] = (i == centro || j == centro) ? 1 : 0;

    // octaedro (forma de losango)
    for (int i = 0; i < HABILIDADE; i++)
        for (int j = 0; j < HABILIDADE; j++)
            octaedro[i][j] = (abs(i - centro) + abs(j - centro) <= centro) ? 1 : 0;

    // 4. Aplicar habilidades

    int coneL = 2, coneC = 2;
    int cruzL = 4, cruzC = 7;
    int octL = 6, octC = 2;

    for (int i = 0; i < HABILIDADE; i++)
    {
        for (int j = 0; j < HABILIDADE; j++)
        {
            int l, c;

            // Cone
            l = coneL + i - centro;
            c = coneC + j - centro;
            if (l >= 0 && l < TABULEIRO && c >= 0 && c < TABULEIRO)
                if (cone[i][j] && tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = AREA_AFETADA;

            // Cruz
            l = cruzL + i - centro;
            c = cruzC + j - centro;
            if (l >= 0 && l < TABULEIRO && c >= 0 && c < TABULEIRO)
                if (cruz[i][j] && tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = AREA_AFETADA;

            // Octaedro
            l = octL + i - centro;
            c = octC + j - centro;
            if (l >= 0 && l < TABULEIRO && c >= 0 && c < TABULEIRO)
                if (octaedro[i][j] && tabuleiro[l][c] == AGUA)
                    tabuleiro[l][c] = AREA_AFETADA;
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
