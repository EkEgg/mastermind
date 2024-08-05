#include "tela-vencedor.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include <stdio.h>

void imprimirTelaVencedor(ESTADO_TELA_VENCEDOR *estado)
{
    limparConsole();

    puts("");
    
    printf("    ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    printf("%s", estado->nomeDoVencedor);
    definirAtributoGrafico(ATR_REINICIAR);
    puts(" venceu!");

    puts("");

    printf("    Pressione ");
    definirAtributoGrafico(ATR_NEGRITO);
    printf("[ENTER]");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" para continuar. ");
}

void executarTelaVencedor(char *nomeDoVencedor)
{
    ESTADO_TELA_VENCEDOR estado;
    estado.nomeDoVencedor = nomeDoVencedor;
    imprimirTelaVencedor(&estado);
    pularLinha();
}