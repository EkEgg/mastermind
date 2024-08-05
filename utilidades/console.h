#pragma once

#define ATR_REINICIAR 0

#define ATR_NEGRITO 1
#define ATR_MEIO_BRILHO 2
#define ATR_PRETO 30
#define ATR_VERMELHO 31
#define ATR_VERDE 32
#define ATR_MARROM 33
#define ATR_AZUL 34
#define ATR_MAGENTA 35
#define ATR_CIANO 36
#define ATR_BRANCO 37

void limparConsole(void);

void definirAtributoGrafico(unsigned codigo);

void reposicionarCursor(unsigned linha, unsigned coluna);