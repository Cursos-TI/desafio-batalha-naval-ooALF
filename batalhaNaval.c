#include <stdio.h>

#define linha  10
#define coluna 10


int main ()
{
    int tabuleiro[linha][coluna];
    char letras[linha] = {'A','B','C','D','E','F','G','H','I','J'};
    int valor = 0;
    

    // ---- Cabeçalho com letras ----
    printf("   "); // espaço para alinhar com os números da lateral
    for (int k = 0; k < linha; k++)
    {   
        printf("%c  ", letras[k]);
    }
    printf("\n");

    // ---- Tabuleiro ----
    for (int i = 0; i < linha; i++)
    {
        printf("%d ", i+1);  // imprime número na lateral ESQUERDA


        

        for (int j = 0; j < coluna; j++) 
        {
    
       tabuleiro[i][j] = valor; // preenche com valores com 0
            if (tabuleiro[i][j] == 0 )
        {
          tabuleiro[0][9] = 3;
          tabuleiro[1][8] = 3;
          tabuleiro[2][7] = 3;

          tabuleiro[0][4] = 3;
          tabuleiro[1][3] = 3;
          tabuleiro[2][2] = 3;
           
          tabuleiro[5][5] = 3;
          tabuleiro[6][6] = 3;
          tabuleiro[7][7] = 3;


           printf("%2d ", tabuleiro[i][j]);

        }
          
        }

        printf("\n");
    }

    return 0;
}
