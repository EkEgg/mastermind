#include <stdio.h>
#include <stdlib.h>
#include "../utilidades/console.h"
#include "tela-instrucoes.h"
#include "../utilidades/entrada.h"

void imprimirTelaInstrucoes(void){
    limparConsole();
    puts("");
    definirAtributoGrafico(ATR_VERDE);
    definirAtributoGrafico (ATR_NEGRITO);
    puts("    INSTRUÇÕES");
    definirAtributoGrafico(ATR_REINICIAR);

    puts("");

    printf("    ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    printf("Master");
    definirAtributoGrafico(ATR_AZUL);
    printf("mind");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(", ou ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    printf("Senha");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(", como é conhecido no Brasil, é um jogo de quebra-cabeça jogado por du-\n");
    printf("    as pessoas. No início do jogo, ambos os jogadores começam com pontuações  zeradas  e  esco-\n");
    printf("    lhem uma pontuação máxima para terminar o jogo. Então, eles escolhem quem começará em qual\n");
    printf("    função na primeira rodada. Há duas funções: o ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_AZUL);
    printf("criador");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" e o ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    printf("quebrador");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(".\n");

    puts("");

    printf("    No início de uma rodada, o ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_AZUL);
    printf("criador");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" insere uma senha sem que o quebrador a veja. Por padrão,\n");
    printf("    a senha é formada por 4 letras distintas entre A e F.\n");

    puts("");

    printf("    Então, o ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    printf("quebrador");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" tenta acertar a senha com várias tentativas. Por padrão, ele possui  10\n");
    printf("    tentativas. A cada tentativa feita, ele recebe dicas sobre a similaridade da tentativa com\n");
    printf("    a senha, formada por caracteres ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    printf("*");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(", ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_AZUL);
    printf("~");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" e ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    printf(".");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(":\n");

    puts("");

    printf("    ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERDE);
    printf("*");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" significa que uma letra está presente na senha na mesma posição em que foi inserida.\n");

    puts("");

    printf("    ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_AZUL);
    printf("~");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" significa que uma letra está presente na senha, mas em outra posição.\n");

    puts("");

    printf("    ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    printf(".");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" significa que uma letra não está presente na senha.\n");

    puts("");

    printf("    As dicas não aparecem em nenhuma ordem especifica. O ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    printf("quebrador");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" deve usar as dicas para adi-\n");
    printf("    vinhar a senha dentro das tentativas restantes.\n");

    puts("");

    printf("    Caso o ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_VERMELHO);
    printf("quebrador");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" acerte a senha, ou suas tentativas acabem, a senha é revelada e a  rodada\n");
    printf("    termina. O ");
    definirAtributoGrafico(ATR_NEGRITO);
    definirAtributoGrafico(ATR_AZUL);
    printf("criador");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" recebe como pontuação o número de tentativas feitas. Os  jogadores,  en-\n");
    printf("    tão, trocam de funções e a próxima rodada começa.\n");

    puts("");

    printf("    Se, no fim de uma rodada, um dos jogadores houver obtido a pontuação máxima definida no  i-\n");
    printf("    nício da partida, o jogo termina e esse jogador vence a partida.\n");

    puts("");

    printf("    Nas configurações do jogo, você pode trocar algumas variáveis do jogo. É possível mudar  o\n");
    printf("    tamanho das senhas e o número máximo de tentativas. Também é possível fazer com que  a  or-\n");
    printf("    dem das dicas corresponda à ordem das letras da tentativa, permitir letras repetidas na se-\n");
    printf("    nha e permitir o uso do alfabeto inteiro em vez de apenas de A a F.\n");

    puts("");
    
    printf("    Pressione ");
    definirAtributoGrafico(ATR_NEGRITO);
    printf("[ENTER]");
    definirAtributoGrafico(ATR_REINICIAR);
    printf(" para voltar. ");
}

void executarTelaInstrucoes(void)
{
    imprimirTelaInstrucoes();
    pularLinha();
}