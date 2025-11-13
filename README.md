# 🧩 WAR ESTRUTURADO – Versão Final com Missões Estratégicas
## 📚 Descrição Geral

Este projeto implementa uma versão simplificada e estruturada em C do jogo WAR, com funcionalidades de cadastro de territórios, simulação de ataques e missões estratégicas para cada jogador.

O objetivo é demonstrar o uso de structs, ponteiros, alocação dinâmica de memória, modularização, passagem de parâmetros por referência e valor, e controle de fluxo com interação no terminal.

## 🎯 Objetivos do Projeto

Criar um sistema que gerencie territórios, exércitos e ataques entre eles.

Simular batalhas usando números aleatórios (rolagem de dados).

Permitir que cada jogador receba uma missão secreta sorteada automaticamente.

Verificar, a cada turno, se algum jogador cumpriu sua missão.

Aplicar boas práticas de programação estruturada, clareza de código e documentação interna.

## ⚙️ Funcionalidades Implementadas
Funcionalidade	Descrição
🏗️ Cadastro de Territórios	O usuário informa nome, cor e tropas de cada território.
🎲 Sistema de Ataque	Simula uma batalha entre dois territórios com rolagem de dados (1–6).
⚔️ Resultado do Combate	O vencedor pode conquistar o território inimigo e transferir tropas.
🧠 Missões Estratégicas	Cada jogador recebe aleatoriamente uma missão secreta no início.
🏁 Verificação de Vitória	Após cada turno, o sistema checa se algum jogador completou sua missão.
🧹 Liberação de Memória	Ao final do jogo, toda memória alocada dinamicamente é liberada.

## 🔧 Principais Funções
Função	Propósito
void cadastrarTerritorios(Territorio *mapa, int qtd)	Lê e armazena os dados dos territórios.
void exibirTerritorios(Territorio *mapa, int qtd)	Mostra todos os territórios com cor e tropas.
void atacar(Territorio *atacante, Territorio *defensor)	Simula uma batalha entre dois territórios usando dados aleatórios.
void atribuirMissao(char *destino, char *missoes[], int total)	Sorteia uma missão para um jogador.
void exibirMissao(const char *missao, const char *cor)	Mostra a missão do jogador (somente uma vez).
int verificarMissao(char *missao, Territorio *mapa, int tamanho, const char *cor)	Avalia se o jogador cumpriu sua missão.
void liberarMemoria(Territorio *mapa, char *m1, char *m2)	Libera toda memória alocada dinamicamente.

## 🎮 Como o Jogo Funciona

O jogador define o número total de territórios.

O sistema solicita o nome, cor e número de tropas de cada território.

Cada jogador recebe automaticamente uma missão secreta (exibida uma única vez).

O jogo exibe um menu interativo:

1 → Realizar um ataque

2 → Exibir territórios

0 → Encerrar o jogo

Durante um ataque:

O jogador escolhe o território atacante e o defensor.

São rolados dois dados (valores aleatórios entre 1 e 6).

O vencedor conquista ou defende o território conforme as regras.

Após cada turno, o sistema verifica se algum jogador completou sua missão.

Quando um jogador vence, o jogo é encerrado e a memória é liberada.

## 🧠 Conceitos Praticados

Structs para agrupamento de dados compostos.
Ponteiros e passagem por referência para modificar diretamente os dados.
Alocação dinâmica com malloc() e calloc().
Gerenciamento de memória com free().
Geradores de números aleatórios (rand() e srand(time(NULL))).
Modularização com funções bem definidas e responsabilidades separadas.
Verificação de condições lógicas e strings dinâmicas (strcpy, strcmp, strstr).

## 🖥️ Requisitos Técnicos

Compilador C (GCC ou Clang).

Bibliotecas padrão:
stdio.h
stdlib.h
string.h
time.h

## 🏁 Considerações Finais

### Este projeto representa a conclusão da jornada do WAR Estruturado, unindo técnicas fundamentais da linguagem C com uma abordagem lúdica e interativa.

O código demonstra:
Organização modular.
Uso avançado de ponteiros e structs.
Lógica condicional baseada em missões.
Interface textual clara e intuitiva.

📘 Autor: Daniel Bruno Freitas da Silva
🕹️ Versão: 3.0 (Final – Missões Estratégicas)
📅 Ano: 2025
