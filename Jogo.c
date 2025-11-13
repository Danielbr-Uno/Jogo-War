#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// -------------------------------------------------------------
// Estrutura que representa um território
// -------------------------------------------------------------
typedef struct {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército (quem controla)
    int tropas;      // Número de tropas
} Territorio;

// -------------------------------------------------------------
// Função: Cadastrar os territórios dinamicamente
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
// Função: Exibir todos os territórios
// -------------------------------------------------------------
void exibirTerritorios(Territorio *mapa, int qtd) {
    printf("\n=== ESTADO ATUAL DOS TERRITÓRIOS ===\n");
    for (int i = 0; i < qtd; i++) {
        printf("%d. Nome: %s | Cor: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// -------------------------------------------------------------
// Função: Simular ataque entre dois territórios
// -------------------------------------------------------------
void atacar(Territorio *atacante, Territorio *defensor) {
    printf("\n--- ATAQUE INICIADO ---\n");
    printf("%s (%s) está atacando %s (%s)!\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    int dadoAtacante = rand() % 6 + 1;
    int dadoDefensor = rand() % 6 + 1;

    printf("Dado do atacante: %d\n", dadoAtacante);
    printf("Dado do defensor: %d\n", dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        printf("Resultado: O atacante venceu a batalha!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2;
        atacante->tropas /= 2;
    } else {
        printf("Resultado: O defensor resistiu!\n");
        if (atacante->tropas > 0)
            atacante->tropas -= 1;
    }
    printf("--- Fim do ataque ---\n");
}

// -------------------------------------------------------------
// Função: Atribuir missão a um jogador (sorteio aleatório)
// -------------------------------------------------------------
void atribuirMissao(char *destino, char *missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    strcpy(destino, missoes[indice]);
}

// -------------------------------------------------------------
// Função: Exibir missão de um jogador (passagem por valor)
// -------------------------------------------------------------
void exibirMissao(const char *missao, const char *cor) {
    printf("\nMissão secreta do jogador %s:\n", cor);
    printf("👉 %s\n\n", missao);
}

// -------------------------------------------------------------
// Função: Verificar se a missão foi cumprida
// -------------------------------------------------------------
// Lógica simplificada de verificação:
//  - "Conquistar 3 territorios" → jogador deve possuir 3 ou mais territórios.
//  - "Eliminar cor vermelha" → nenhum território vermelho deve restar.
//  - Outras missões retornam 0 (não cumpridas).
// -------------------------------------------------------------
int verificarMissao(char *missao, Territorio *mapa, int tamanho, const char *corJogador) {
    if (strstr(missao, "Conquistar 3 territorios") != NULL) {
        int count = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0)
                count++;
        }
        return (count >= 3);
    }

    if (strstr(missao, "Eliminar cor vermelha") != NULL) {
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, "Vermelho") == 0)
                return 0;
        }
        return 1;
    }

    return 0;
}

// -------------------------------------------------------------
// Função: Liberar memória alocada dinamicamente
// -------------------------------------------------------------
void liberarMemoria(Territorio *mapa, char *missaoJogador1, char *missaoJogador2) {
    free(mapa);
    free(missaoJogador1);
    free(missaoJogador2);
    printf("\nMemória liberada com sucesso!\n");
}

// -------------------------------------------------------------
// Função principal (main)
// -------------------------------------------------------------
int main() {
    srand(time(NULL)); // garante aleatoriedade

    int qtd;
    printf("=== SISTEMA WAR ESTRUTURADO FINAL ===\n");
    printf("Informe o número de territórios: ");
    scanf("%d", &qtd);

    // Alocação dinâmica do mapa
    Territorio *mapa = (Territorio *) calloc(qtd, sizeof(Territorio));
    if (!mapa) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Cadastro dos territórios
    cadastrarTerritorios(mapa, qtd);

    // Vetor de missões pré-definidas
    char *missoes[] = {
        "Conquistar 3 territorios",
        "Eliminar cor vermelha",
        "Dominar metade do mapa",
        "Ter mais de 20 tropas",
        "Controlar todos os territórios azuis"
    };
    int totalMissoes = sizeof(missoes) / sizeof(missoes[0]);

    // Missões dos dois jogadores
    char *missaoJogador1 = (char *) malloc(100 * sizeof(char));
    char *missaoJogador2 = (char *) malloc(100 * sizeof(char));

    atribuirMissao(missaoJogador1, missoes, totalMissoes);
    atribuirMissao(missaoJogador2, missoes, totalMissoes);

    // Exibição inicial das missões (uma vez só)
    exibirMissao(missaoJogador1, "Jogador 1 (Azul)");
    exibirMissao(missaoJogador2, "Jogador 2 (Vermelho)");

    int opcao;
    do {
        printf("\n=== MENU DE AÇÕES ===\n");
        printf("1 - Realizar ataque\n");
        printf("2 - Exibir territórios\n");
        printf("0 - Encerrar jogo\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int idAtacante, idDefensor;

            exibirTerritorios(mapa, qtd);
            printf("\nEscolha o número do território atacante: ");
            scanf("%d", &idAtacante);
            printf("Escolha o número do território defensor: ");
            scanf("%d", &idDefensor);

            if (idAtacante < 1 || idAtacante > qtd || idDefensor < 1 || idDefensor > qtd) {
                printf("Entrada inválida.\n");
                continue;
            }

            Territorio *atacante = &mapa[idAtacante - 1];
            Territorio *defensor = &mapa[idDefensor - 1];

            if (strcmp(atacante->cor, defensor->cor) == 0) {
                printf("Não é possível atacar território da mesma cor!\n");
                continue;
            }

            atacar(atacante, defensor);
            exibirTerritorios(mapa, qtd);

            // Verificação de vitória
            if (verificarMissao(missaoJogador1, mapa, qtd, "Azul")) {
                printf("\n🎉 Jogador 1 (Azul) cumpriu sua missão!\n");
                printf("Missão: %s\n", missaoJogador1);
                break;
            }

            if (verificarMissao(missaoJogador2, mapa, qtd, "Vermelho")) {
                printf("\n🎉 Jogador 2 (Vermelho) cumpriu sua missão!\n");
                printf("Missão: %s\n", missaoJogador2);
                break;
            }
        }
        else if (opcao == 2) {
            exibirTerritorios(mapa, qtd);
        }

    } while (opcao != 0);

    liberarMemoria(mapa, missaoJogador1, missaoJogador2);
    printf("\nJogo encerrado. Até a próxima batalha!\n");

    return 0;
}
