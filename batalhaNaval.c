#include <stdio.h>
#include <stdlib.h> // <- necessário para abs()

#define N 10  // tamanho do tabuleiro
#define H 5   // tamanho da matriz da habilidade (use 5 ou 7)

/* --- Utilidades do tabuleiro --- */
void inicializarTabuleiro(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tabuleiro[i][j] = 0; // água
}

void imprimirTabuleiroNumeros(int tabuleiro[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/* --- Criação dinâmica das máscaras de habilidades (H x H) --- */
void criarCone(int m[H][H]) {
    int c = H / 2; // coluna central
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            // abre em direção à base (para baixo)
            m[i][j] = (j >= c - i && j <= c + i) ? 1 : 0;
        }
    }
}

void criarCruz(int m[H][H]) {
    int c = H / 2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            m[i][j] = (i == c || j == c) ? 1 : 0;
        }
    }
}

void criarOctaedro(int m[H][H]) {
    int c = H / 2;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            // losango usando distância Manhattan
            m[i][j] = (abs(i - c) + abs(j - c) <= c) ? 1 : 0;
        }
    }
}

/* --- Sobrepor máscara no tabuleiro, centrada em (x,y) --- */
void aplicarHabilidade(int tabuleiro[N][N], int m[H][H], int x, int y) {
    int c = H / 2; // deslocamento para centralizar
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < H; j++) {
            if (m[i][j] == 1) {
                int r = x + i - c; // linha no tabuleiro
                int s = y + j - c; // coluna no tabuleiro
                // respeitar limites do tabuleiro
                if (r >= 0 && r < N && s >= 0 && s < N) {
                    // marca 5 só se for água; não sobrescreve navio (3)
                    if (tabuleiro[r][s] == 0) tabuleiro[r][s] = 5;
                }
            }
        }
    }
}

int main(void) {
    int tab[N][N];
    int mask[H][H];

    inicializarTabuleiro(tab);

    // Exemplo: alguns navios
    tab[2][3] = 3;
    tab[3][4] = 3;
    tab[4][5] = 3;

    tab[9][8] = 3;
    tab[8][7] = 3;
    tab[7][6] = 3;

    tab[0][9] = 3;
    tab[1][8] = 3;
    tab[2][7] = 3;

    printf("Tabuleiro inicial:\n");
    imprimirTabuleiroNumeros(tab);

    // Cone centrado em (5,5)
    criarCone(mask);
    aplicarHabilidade(tab, mask, 5, 5);
    printf("Depois do CONE:\n");
    imprimirTabuleiroNumeros(tab);

    // Cruz centrada em (2,2)
    criarCruz(mask);
    aplicarHabilidade(tab, mask, 2, 2);
    printf("Depois da CRUZ:\n");
    imprimirTabuleiroNumeros(tab);

    // Octaedro (losango) centrado em (7,7)
    criarOctaedro(mask);
    aplicarHabilidade(tab, mask, 7, 7);
    printf("Depois do OCTAEDRO:\n");
    imprimirTabuleiroNumeros(tab);

    return 0;
}
