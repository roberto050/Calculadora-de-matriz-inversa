#include <stdio.h>

// Função para calcular a matriz inversa
void calcular_matriz_inversa(float matriz[][3], int tamanho) {
    float determinante;

    if (tamanho == 1) {
        determinante = matriz[0][0];
        
        if (determinante == 0) {
            printf("A matriz não tem inversa.\n");
            return;
        }
        
        printf("A matriz inversa é:\n");
        printf("%.2f\n", 1 / determinante);
    } else if (tamanho == 2) {
        determinante = (matriz[0][0] * matriz[1][1]) - (matriz[0][1] * matriz[1][0]);
        
        if (determinante == 0) {
            printf("A matriz não tem inversa.\n");
            return;
        }
        
        printf("A matriz inversa é:\n");
      printf("|");
        printf("%.2f %.2f\n", matriz[1][1] / determinante, -matriz[0][1] / determinante);
        printf("%.2f %.2f\n", -matriz[1][0] / determinante, matriz[0][0] / determinante);
    } else if (tamanho == 3) {
        determinante = 
            (matriz[0][0] * (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1])) -
            (matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[1][2] * matriz[2][0])) +
            (matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]));

        if (determinante == 0) {
            printf("A matriz não tem inversa.\n");
            return;
        }
        
        printf("A matriz inversa é:\n");
        printf("%.2f %.2f %.2f\n", (matriz[1][1] * matriz[2][2] - matriz[1][2] * matriz[2][1]) / determinante, (matriz[0][2] * matriz[2][1] - matriz[0][1] * matriz[2][2]) / determinante, (matriz[0][1] * matriz[1][2] - matriz[0][2] * matriz[1][1]) / determinante);
        printf("%.2f %.2f %.2f\n", (matriz[1][2] * matriz[2][0] - matriz[1][0] * matriz[2][2]) / determinante, (matriz[0][0] * matriz[2][2] - matriz[0][2] * matriz[2][0]) / determinante, (matriz[0][2] * matriz[1][0] - matriz[0][0] * matriz[1][2]) / determinante);
        printf("%.2f %.2f %.2f\n", (matriz[1][0] * matriz[2][1] - matriz[1][1] * matriz[2][0]) / determinante, (matriz[0][1] * matriz[2][0] - matriz[0][0] * matriz[2][1]) / determinante, (matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0]) / determinante);
    } else {
        printf("Opção inválida.\n");
        return;
    }
}

// Função para verificar se o usuário deseja continuar
int continuar() {
    char resposta;
    printf("Deseja continuar? (s/n): ");
    scanf(" %c", &resposta);
    return resposta == 's' || resposta == 'S';
}

int main() {
  printf("|Calculadora de matriz inversa|\n");
    printf("\n");
    int continuar_calculando = 1;

    while (continuar_calculando) {
        int opcao;
        printf("Digite o tamanho da matriz (1 - 1x1, 2 - 2x2, 3 - 3x3): ");
        scanf("%d", &opcao);

        float matriz[3][3];
        int tamanho = opcao;

        printf("Digite os elementos da matriz %dx%d:\n", tamanho, tamanho);
        for (int i = 0; i < tamanho; i++) {
            for (int j = 0; j < tamanho; j++) {
                printf("Digite o elemento [%d][%d]: ", i+1, j+1);
                scanf("%f", &matriz[i][j]);
            }
        }

        calcular_matriz_inversa(matriz, tamanho);

        continuar_calculando = continuar();
    }

    printf("Programa encerrado.\n");

    return 0;
}
