#pragma once
#include "../fluxos/estruturas.h"

typedef struct
{
    JOGADOR *jogador1;
    JOGADOR *jogador2;
    ushort pontuacaoMaxima;
}
ESTADO_TELA_PLACAR;

void imprimirTelaPlacar(ESTADO_TELA_PLACAR *estado);

void executarTelaPlacar(JOGADOR *jogador1, JOGADOR *jogador2, ushort pontuacaoMaxima);