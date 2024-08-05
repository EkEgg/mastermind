#include "console.h"
#include <stdio.h>
#include <stdlib.h>

void limparConsole(void)
{
    int systemReturnCode = 1;
    #ifdef __linux__
        systemReturnCode = system("clear");
    #elif _WIN32
        systemReturnCode = system("cls");
    #endif
    if (systemReturnCode != 0)
    {
        /* Do nothing. */
    }
}

void definirAtributoGrafico(unsigned codigo)
{
    printf("\033[%um", codigo);
}

void reposicionarCursor(unsigned nLinha, unsigned nColuna)
{
    printf("\033[%uH\033[%uG", nLinha, nColuna);
}