#pragma once
#include "../utilidades/tipos.h"

typedef struct
{
    ushort *saidaOpcao;

    byte haErro;
    char *erro;
}
ESTADO_TELA_PRINCIPAL;

void inicializarEstadoTelaPrincipal(ESTADO_TELA_PRINCIPAL *estado);

void imprimirTelaPrincipal(ESTADO_TELA_PRINCIPAL *estado);

void executarTelaPrincipal(ushort *saidaOpcao);