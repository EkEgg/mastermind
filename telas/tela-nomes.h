#pragma once
#include "../utilidades/tipos.h"

typedef struct
{
    byte nomeDoJogador1Preenchido;
    char *saidaNomeDoJogador1;

    byte nomeDoJogador2Preenchido;
    char *saidaNomeDoJogador2;

    byte haErro;
    char *erro;
}
ESTADO_TELA_NOMES;

void inicializarEstadoTelaNomes(ESTADO_TELA_NOMES *estado);

void imprimirTelaNomes(ESTADO_TELA_NOMES *estado);

void executarTelaNomes(char *saidaNomeDoJogador1, char *saidaNomeDoJogador2);