#include <stdio.h>
#include <string.h>

#define MAX 5

typedef struct {
    char nome[50];
    char cor[20];
    int tropas;
} Territorio;

void limparEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    Territorio mapa[MAX];

    printf("=== Cadastro dos Territorios ===\n");

    for (int i = 0; i < MAX; i++) {
        printf("\nTerritorio %d:\n", i + 1);

        printf("Nome: ");
        fgets(mapa[i].nome, 50, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Cor do exercito: ");
        fgets(mapa[i].cor, 20, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Numero de tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparEntrada();
    }

    printf("\n=== Estado Atual do Mapa ===\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%d] %s | Cor: %s | Tropas: %d\n",
            i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }

    return 0;
}

