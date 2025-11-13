#include <stdio.h>
#include <string.h>

// -------------------------------------------------------
// Estrutura que representa um território no sistema
// -------------------------------------------------------
struct Territorio {
    char nome[30];      // Nome do território
    char cor[10];       // Cor do exército associado
    int tropas;         // Quantidade de tropas no território
};

int main() {
    struct Territorio territorios[5];  // Vetor para armazenar 5 territórios
    int i; // variável de controle do laço

    printf("=== SISTEMA DE CADASTRO DE TERRITÓRIOS ===\n\n");

    // -------------------------------------------------------
    // Entrada de dados: o usuário cadastra os 5 territórios
    // -------------------------------------------------------
    for (i = 0; i < 5; i++) {
        printf("Cadastro do território %d:\n", i + 1);

        printf("-> Nome do território: ");
        scanf(" %[^\n]", territorios[i].nome); // lê string com espaços

        printf("-> Cor do exército: ");
        scanf(" %[^\n]", territorios[i].cor); // lê string com espaços

        printf("-> Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);

        printf("\n");
    }

    // -------------------------------------------------------
    // Exibição dos dados cadastrados
    // -------------------------------------------------------
    printf("\n=== TERRITÓRIOS CADASTRADOS ===\n\n");
    for (i = 0; i < 5; i++) {
        printf("Território %d:\n", i + 1);
        printf(" Nome: %s\n", territorios[i].nome);
        printf(" Cor do exército: %s\n", territorios[i].cor);
        printf(" Tropas: %d\n", territorios[i].tropas);
        printf("------------------------------\n");
    }

    printf("Cadastro concluído com sucesso!\n");
    return 0;
}
