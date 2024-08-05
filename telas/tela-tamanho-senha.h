#pragma once
#include "../utilidades/tipos.h"

typedef struct
{
    ushort *saidaTamanhoDaSenha;

    byte haErro;
    char *erro;
}
ESTADO_TELA_TAMANHO_SENHA;

void inicializarEstadoTelaTamanhoSenha(ESTADO_TELA_TAMANHO_SENHA *estado);

void imprimirTelaTamanhoSenha(ESTADO_TELA_TAMANHO_SENHA *estado);

void executarTelaTamanhoSenha(ushort *saidaTamanhoDaSenha);