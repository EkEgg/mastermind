#pragma once

#include "../utilidades/tipos.h"

#define TAM_MAX_NOME 30

#define TAMANHO_DA_SENHA_PADRAO 4
#define MAXIMO_DE_TENTATIVAS_PADRAO 10
#define PERMITIR_ALFABETO_INTEIRO_PADRAO 0
#define PERMITIR_LETRAS_REPETIDAS_PADRAO 0
#define DICAS_ESPECIFICAM_POSICAO_PADRAO 0

typedef struct
{
    ushort tamanhoDaSenha;
    ushort maximoDeTentativas;
    byte permitirAlfabetoInteiro;
    byte permitirLetrasRepetidas;
    byte dicasEspecificamPosicao;
}
CONFIGURACAO;

void definirConfiguracaoPadrao(CONFIGURACAO *saidaConfiguracao);

typedef struct
{
    char nome[TAM_MAX_NOME+1];
    ushort pontuacao;
}
JOGADOR;

void trocarPonteirosDeJogadores(JOGADOR **a, JOGADOR **b);

typedef struct
{
    JOGADOR jogador1;
    JOGADOR jogador2;
    ushort pontuacaoMaxima;
    JOGADOR *criador;
    JOGADOR *quebrador;
}
ESTADO_PARTIDA;

typedef struct _TENTATIVA
{
    char *tentativa;
    char *dicas;
    struct _TENTATIVA *proxima;
}
TENTATIVA;

TENTATIVA *novaTentativa(ushort tamanhoDaSenha);
void excluirTentativa(TENTATIVA *tentativa);

typedef struct
{
    TENTATIVA *primeira;
    TENTATIVA *ultima;
    ushort tamanho;
}
LISTA_DE_TENTATIVAS;

void inicializarListaDeTentativas(LISTA_DE_TENTATIVAS *lista);
void adicionarTentativaNoInicio(LISTA_DE_TENTATIVAS *lista, TENTATIVA *tentativa);
void adicionarTentativaNoFinal(LISTA_DE_TENTATIVAS *lista, TENTATIVA *tentativa);
void removerTentativaNoInicio(LISTA_DE_TENTATIVAS *lista);
void removerTodasAsTentativas(LISTA_DE_TENTATIVAS *lista);
int possuiTentativas(LISTA_DE_TENTATIVAS *lista);

typedef struct
{
    char *senha;
    LISTA_DE_TENTATIVAS tentativas;
}
ESTADO_RODADA;