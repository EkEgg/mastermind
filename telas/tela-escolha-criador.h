#pragma once
#include "../utilidades/tipos.h"

typedef struct
{
    char *nomeDoJogador1;
    char *nomeDoJogador2;

    ushort *saidaOpcao;

    byte haErro;
    char *erro;
}
ESTADO_TELA_ESCOLHA_CRIADOR;

void inicializarEstadoTelaEscolhaCriador(ESTADO_TELA_ESCOLHA_CRIADOR *estado);

void imprimirTelaEscolhaCriador(ESTADO_TELA_ESCOLHA_CRIADOR *estado);

void executarTelaEscolhaCriador(char *nomeDoJogador1, char *nomeDoJogador2, ushort *saidaOpcao);