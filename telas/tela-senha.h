#pragma once
#include "../fluxos/estruturas.h"
#include "../utilidades/tipos.h"

typedef struct
{
    char *nomeDoCriador;
    CONFIGURACAO *configuracao;

    char *saidaSenha;

    byte tipoDeErro;
}
ESTADO_TELA_SENHA;

void inicializarEstadoTelaSenha(ESTADO_TELA_SENHA *estado);

void imprimirTelaSenha(ESTADO_TELA_SENHA *estado);

void executarTelaSenha(CONFIGURACAO *configuracao, char *nomeDoCriador, char *saidaSenha);