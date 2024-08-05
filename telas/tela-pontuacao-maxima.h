#pragma once
#include "../utilidades/tipos.h"

typedef struct
{
    ushort *saidaPontuacaoMaxima;

    byte haErro;
    char *erro;
}
ESTADO_TELA_PONTUACAO_MAXIMA;

void inicializarEstadoTelaPontuacaoMaxima(ESTADO_TELA_PONTUACAO_MAXIMA *estado);

void imprimirTelaPontuacaoMaxima(ESTADO_TELA_PONTUACAO_MAXIMA *estado);

void executarTelaPontuacaoMaxima(ushort *saidaPontuacaoMaxima);