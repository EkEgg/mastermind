#include "tela-configuracao.h"
#include "../utilidades/console.h"
#include "../utilidades/entrada.h"
#include <stddef.h>
#include <stdio.h>

void imprimirTelaConfiguracao(ESTADO_TELA_CONFIGURACAO *estado)
{
    limparConsole();
    puts("");

    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    puts("    CONFIGURAÇÕES");
    definirAtributoGrafico(ATR_REINICIAR);

    puts("");

    printf("    1. Tamanho da senha: ");
    definirAtributoGrafico(ATR_NEGRITO);
    printf("%hu", estado->configuracao->tamanhoDaSenha);
    definirAtributoGrafico(ATR_REINICIAR);
    puts("");

    printf("    ");
    definirAtributoGrafico(ATR_CIANO);
    puts("Número de caracteres que compõem uma senha.");
    definirAtributoGrafico(ATR_REINICIAR);

    puts("");

    printf("    2. Máximo de tentativas: ");
    definirAtributoGrafico(ATR_NEGRITO);
    printf("%hu", estado->configuracao->maximoDeTentativas);
    definirAtributoGrafico(ATR_REINICIAR);
    puts("");

    printf("    ");
    definirAtributoGrafico(ATR_CIANO);
    puts("Número máximo de tentativas que o quebrador pode fazer antes de terminar a rodada.");
    definirAtributoGrafico(ATR_REINICIAR);

    puts("");

    printf("    3. [");
    definirAtributoGrafico(ATR_NEGRITO);
    putchar(estado->configuracao->dicasEspecificamPosicao ? 'X' : ' ');
    definirAtributoGrafico(ATR_REINICIAR);
    puts("] Dicas especificam posição");

    printf("    ");
    definirAtributoGrafico(ATR_CIANO);
    puts("Faz as dicas serem mostradas na mesma ordem dos caracteres da tentativa.");
    definirAtributoGrafico(ATR_REINICIAR);

    puts("");

    printf("    4. [");
    definirAtributoGrafico(ATR_NEGRITO);
    putchar(estado->configuracao->permitirLetrasRepetidas ? 'X' : ' ');
    definirAtributoGrafico(ATR_REINICIAR);
    puts("] Permitir letras repetidas");

    printf("    ");
    definirAtributoGrafico(ATR_CIANO);
    puts("Permite o uso de letras repetidas na mesma senha.");
    definirAtributoGrafico(ATR_REINICIAR);

    puts("");

    if(!estado->configuracao->permitirLetrasRepetidas) definirAtributoGrafico(ATR_MEIO_BRILHO);
    printf("    5. [");
    definirAtributoGrafico(ATR_NEGRITO);
    putchar(estado->configuracao->permitirAlfabetoInteiro ? 'X' : ' ');
    definirAtributoGrafico(ATR_REINICIAR);
    if(!estado->configuracao->permitirLetrasRepetidas) definirAtributoGrafico(ATR_MEIO_BRILHO);
    puts("] Permitir alfabeto inteiro.");

    printf("    ");
    definirAtributoGrafico(ATR_CIANO);
    puts("Permite o uso do alfabeto inteiro [A, Z] em vez de [A, F]. Só pode ser habilitado com letras repetidas.");
    definirAtributoGrafico(ATR_REINICIAR);
    puts("");

    puts("    6. Restaurar configurações padrões");
    puts("");

    puts("    7. Voltar");
    puts("");

    printf("    Escolha: ");

    if(estado->haErro)
    {
        puts("");
        puts("");
        definirAtributoGrafico(ATR_VERMELHO);
        definirAtributoGrafico(ATR_NEGRITO);
        printf("    * %s\n", estado->erro);
        definirAtributoGrafico(ATR_REINICIAR);
        reposicionarCursor(23, 14);
    }
}

void executarTelaConfiguracao(CONFIGURACAO *configuracao, char *erroPrevio, ushort *saidaOpcao)
{
    ESTADO_TELA_CONFIGURACAO estado;
    int diagnostico;
    estado.haErro = erroPrevio != NULL;
    estado.erro = erroPrevio;
    estado.configuracao = configuracao;
    estado.saidaOpcao = saidaOpcao;
    while(1)
    {
        imprimirTelaConfiguracao(&estado);
        diagnostico = lerUShort(saidaOpcao);
        estado.haErro = 1;
        if(diagnostico == 1)
        {
            estado.erro = "Entrada muito grande. Insira uma entrada menor.";
        }
        else if(diagnostico == 2)
        {
            estado.erro = "Entrada inválida. Insira um número inteiro sem sinal.";
        }
        else if(*saidaOpcao < 1 || *saidaOpcao > 7)
        {
            estado.erro = "Entrada inválida. Insira uma das opções.";
        }
        else
        {
            estado.haErro = 0;
            break;
        }
    }
}