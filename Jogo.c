#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// -------------------------------------------------------------
// Estrutura que representa um território
// -------------------------------------------------------------
typedef struct {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército (representa o dono)
    int tropas;      // Quantidade de tropas
} Territorio;

// -------------------------------------------------------------
// Função para cadastrar os territórios
// -------------------------------------------------------------
void cadastrarTerritorios(Territorio *mapa, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\n--- Cadastro do território %d ---\n", i + 1);
        printf("Nome do território: ");
        scanf(" %[^\n]", mapa[i].nome);

        printf("Cor do exército: ");
        scanf(" %[^\n]", mapa[i].cor);

        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }
}

// -------------------------------------------------------------
// Função para exibir todos os territórios cadastrados
// -------------------------------------------------------------
void exibirTerritorios(Territorio *mapa, int qtd) {
    printf("\n=== ESTADO ATUAL DOS TERRITÓRIOS ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. Nome: %s | Cor: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// -------------------------------------------------------------
// Função que simula o ataque entre dois territórios
// -------------------------------------------------------------
void atacar(Territorio *atacante, Territorio *defensor) {
    printf("\n--- ATAQUE INICIADO ---\n");
    printf("%s (%s) está atacando %s (%s)!\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    // Gera dados aleatórios entre 1 e 6
    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);

    // Resultado da batalha
    if (dadoAtacante > dadoDefensor) {
        printf("Resultado: O atacante venceu a batalha!\n");

        // Transferência de controle do território
        strcpy(defensor->cor, atacante->cor);

        // Metade das tropas do atacante ocupam o território conquistado
        defensor->tropas = atacante->tropas / 2;

        // O atacante perde metade das tropas usadas
        atacante->tropas /= 2;
    } else {
        printf("Resultado: O defensor resistiu ao ataque!\n");

        // O atacante perde uma tropa
        if (atacante->tropas > 0)
            atacante->tropas -= 1;
    }

    printf("--- Fim do ataque ---\n");
}

// -------------------------------------------------------------
// Função para liberar a memória alocada dinamicamente
// -------------------------------------------------------------
void liberarMemoria(Territorio *mapa) {
    free(mapa);
    printf("\nMemória liberada com sucesso!\n");
}

// -------------------------------------------------------------
// Função principal (main)
// -------------------------------------------------------------
int main() {
    srand(time(NULL)); // Garante aleatoriedade nos ataques

    int qtd;
    printf("=== SISTEMA WAR ESTRUTURADO ===\n");
    printf("Informe o número de territórios: ");
    scanf("%d", &qtd);

    // Alocação dinâmica de memória
    Territorio *mapa = (Territorio *) calloc(qtd, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Cadastro inicial
    cadastrarTerritorios(mapa, qtd);
    exibirTerritorios(mapa, qtd);

    // Loop de ataques (interatividade)
    int opcao;
    do {
        printf("\n=== MENU DE AÇÕES ===\n");
        printf("1 - Realizar um ataque\n");
        printf("2 - Exibir territórios\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int idAtacante, idDefensor;

            exibirTerritorios(mapa, qtd);
            printf("\nEscolha o número do território atacante: ");
            scanf("%d", &idAtacante);
            printf("Escolha o número do território defensor: ");
            scanf("%d", &idDefensor);

            // Valida índices
            if (idAtacante < 1 || idAtacante > qtd || idDefensor < 1 || idDefensor > qtd) {
                printf("Opção inválida! Tente novamente.\n");
                continue;
            }

            Territorio *atacante = &mapa[idAtacante - 1];
            Territorio *defensor = &mapa[idDefensor - 1];

            // Impede atacar território da mesma cor
            if (strcmp(atacante->cor, defensor->cor) == 0) {
                printf("Você não pode atacar um território da mesma cor!\n");
                continue;
            }

            atacar(atacante, defensor);
            exibirTerritorios(mapa, qtd);
        }

    } while (opcao != 0);

    liberarMemoria(mapa);

    printf("\nJogo encerrado. Obrigado por jogar!\n");
    return 0;
}
