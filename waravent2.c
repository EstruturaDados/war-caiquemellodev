#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void imprimirMapa(Territorio *mapa) {
    printf("\n=== MAPA ATUAL ===\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%d] %s | %s | Tropas: %d\n",
            i+1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

void atacar(Territorio *mapa, int atk, int def) {
    int dadoAtk = rand() % 6 + 1;
    int dadoDef = rand() % 6 + 1;

    printf("\nBatalha: %s (A) vs %s (D)\n", mapa[atk].nome, mapa[def].nome);
    printf("Ataque rolou: %d\n", dadoAtk);
    printf("Defesa rolou: %d\n", dadoDef);

    if (dadoAtk > dadoDef) {
        mapa[def].tropas--;
        printf("Ataque venceu! Defesa perde 1 tropa.\n");

        if (mapa[def].tropas <= 0) {
            printf("Território conquistado!\n");
            strcpy(mapa[def].cor, mapa[atk].cor);
            mapa[def].tropas = 1;
        }

    } else {
        printf("Defesa resistiu!\n");
    }
}

int main() {
    srand(time(NULL));

    Territorio *mapa = calloc(MAX, sizeof(Territorio));

    printf("=== Cadastro dos Territorios ===\n");
    for (int i = 0; i < MAX; i++) {
        printf("\nTerritorio %d:\n", i + 1);

        printf("Nome: ");
        fgets(mapa[i].nome, 50, stdin);
        mapa[i].nome[strcspn(mapa[i].nome, "\n")] = '\0';

        printf("Cor: ");
        fgets(mapa[i].cor, 20, stdin);
        mapa[i].cor[strcspn(mapa[i].cor, "\n")] = '\0';

        printf("Tropas: ");
        scanf("%d", &mapa[i].tropas);
        limparEntrada();
    }

    int opc, atk, def;
    while (1) {
        imprimirMapa(mapa);

        printf("\nEscolha (1=Atacar, 0=Sair): ");
        scanf("%d", &opc);
        if (opc == 0) break;

        printf("Território atacante (1-5): ");
        scanf("%d", &atk);
        printf("Território defensor (1-5): ");
        scanf("%d", &def);

        atacar(mapa, atk-1, def-1);
    }

    free(mapa);
    return 0;
}
