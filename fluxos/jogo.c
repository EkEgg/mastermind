#include "jogo.h"
#include "arquivos.h"
#include "../telas/tela-principal.h"
#include "../telas/tela-instrucoes.h"
#include "../telas/tela-creditos.h"
#include "../telas/tela-nomes.h"
#include "../telas/tela-pontuacao-maxima.h"
#include "../telas/tela-escolha-criador.h"
#include "../telas/tela-senha.h"
#include "../telas/tela-tentativas.h"
#include "../telas/tela-placar.h"
#include "../telas/tela-vencedor.h"
#include "../telas/tela-configuracao.h"
#include "../telas/tela-maximo-tentativas.h"
#include "../telas/tela-tamanho-senha.h"
#include "../utilidades/strings.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

void executarJogo(CONFIGURACAO *configuracao)
{
    ushort opcao;
    do
    {
        executarTelaPrincipal(&opcao);
        switch(opcao)
        {
            case 1: executarPartida(configuracao);      break;
            case 2: executarTelaInstrucoes();           break;
            case 3: executarConfiguracao(configuracao); break;
            case 4: executarTelaCreditos();             break;
        }
    }
    while(opcao != 5);
}

void executarPartida(CONFIGURACAO *configuracao)
{
    ESTADO_PARTIDA estado;
    ushort opcaoCriador;
    char *nomeDoVencedor;
    executarTelaNomes(estado.jogador1.nome, estado.jogador2.nome);
    executarTelaPontuacaoMaxima(&estado.pontuacaoMaxima);
    executarTelaEscolhaCriador(estado.jogador1.nome, estado.jogador2.nome, &opcaoCriador);
    if(opcaoCriador == 3)
    {
        srand(time(NULL));
        opcaoCriador = (rand() % 2) + 1;
    }
    if(opcaoCriador == 1)
    {
        estado.criador = &estado.jogador1;
        estado.quebrador = &estado.jogador2;
    }
    else if(opcaoCriador == 2)
    {
        estado.criador = &estado.jogador2;
        estado.quebrador = &estado.jogador1;
    }
    estado.jogador1.pontuacao = 0;
    estado.jogador2.pontuacao = 0;
    while(estado.jogador1.pontuacao < estado.pontuacaoMaxima && estado.jogador2.pontuacao < estado.pontuacaoMaxima)
    {
        executarRodada(configuracao, &estado);
        trocarPonteirosDeJogadores(&estado.quebrador, &estado.criador);
    }
    if(estado.jogador1.pontuacao == estado.pontuacaoMaxima) nomeDoVencedor = estado.jogador1.nome;
    else nomeDoVencedor = estado.jogador2.nome;
    executarTelaVencedor(nomeDoVencedor);
}

void executarRodada(CONFIGURACAO *configuracao, ESTADO_PARTIDA *estadoPartida)
{
    ESTADO_RODADA estadoRodada;
    TENTATIVA *tentativa;
    estadoRodada.senha = novaString(configuracao->tamanhoDaSenha);
    inicializarListaDeTentativas(&estadoRodada.tentativas);
    executarTelaSenha(configuracao, estadoPartida->criador->nome, estadoRodada.senha);
    do
    {
        tentativa = novaTentativa(configuracao->tamanhoDaSenha);
        executarTelaTentativas(configuracao, estadoPartida->quebrador->nome, estadoRodada.senha, &estadoRodada.tentativas, tentativa->tentativa);
        atribuirDicas(tentativa, estadoRodada.senha, configuracao->dicasEspecificamPosicao);
        adicionarTentativaNoFinal(&estadoRodada.tentativas, tentativa);
    }
    while(estadoRodada.tentativas.tamanho < configuracao->maximoDeTentativas && strcmp(estadoRodada.tentativas.ultima->tentativa, estadoRodada.senha) != 0);
    executarTelaTentativas(configuracao, estadoPartida->quebrador->nome, estadoRodada.senha, &estadoRodada.tentativas, tentativa->tentativa);
    estadoPartida->criador->pontuacao += estadoRodada.tentativas.tamanho;
    if(estadoPartida->criador->pontuacao > estadoPartida->pontuacaoMaxima)
    {
        estadoPartida->criador->pontuacao = estadoPartida->pontuacaoMaxima;
    }
    executarTelaPlacar(&estadoPartida->jogador1, &estadoPartida->jogador2, estadoPartida->pontuacaoMaxima);
    removerTodasAsTentativas(&estadoRodada.tentativas);
    free(estadoRodada.senha);
}

void atribuirDicas(TENTATIVA *tentativa, char *senha, byte dicasEspecificamPosicao)
{
    ushort i, j, tamanho = strlen(senha);
    ushort numeroDeAcertosExatos = 0;
    ushort numeroDeAcertosProximos = 0;
    ushort numeroDeErros = 0;
    char *copiaTentativa = novaString(tamanho);
    char *copiaSenha = novaString(tamanho);
    strcpy(copiaTentativa, tentativa->tentativa);
    strcpy(copiaSenha, senha);
    for(i = 0; copiaTentativa[i] != '\0'; i++)
    {
        if(copiaTentativa[i] == copiaSenha[i])
        {
            numeroDeAcertosExatos++;
            tentativa->dicas[i] = '*';
            copiaTentativa[i] = ' ';
            copiaSenha[i] = ' ';
        }
    }
    for(i = 0; copiaTentativa[i] != '\0'; i++)
    {
        if(copiaTentativa[i] == ' ') continue;
        for(j = 0; copiaSenha[j] != '\0'; j++)
        {
            if(copiaSenha[j] == ' ') continue;
            if(copiaTentativa[i] == copiaSenha[j])
            {
                numeroDeAcertosProximos++;
                tentativa->dicas[i] = '~';
                copiaTentativa[i] = ' ';
                copiaSenha[j] = ' ';
            }
        }
    }
    for(i = 0; copiaTentativa[i] != '\0'; i++)
    {
        if(copiaTentativa[i] == ' ') continue;
        numeroDeErros++;
        tentativa->dicas[i] = '.';
    }
    free(copiaTentativa);
    free(copiaSenha);
    if(!dicasEspecificamPosicao)
    {
        i = 0;
        while(numeroDeAcertosExatos--)
        {
            tentativa->dicas[i] = '*';
            i++;
        }
        while(numeroDeAcertosProximos--)
        {
            tentativa->dicas[i] = '~';
            i++;
        }
        while(numeroDeErros--)
        {
            tentativa->dicas[i] = '.';
            i++;
        }
    }
    tentativa->dicas[tamanho] = '\0';
}

void executarConfiguracao(CONFIGURACAO *configuracao)
{
    ushort opcao;
    ushort novoValor;
    char *erro = NULL;
    do
    {
        executarTelaConfiguracao(configuracao, erro, &opcao);
        erro = NULL;
        switch(opcao)
        {
            case 1:
                executarTelaTamanhoSenha(&novoValor);
                if(!configuracao->permitirLetrasRepetidas && novoValor > 6)
                {
                    erro = "O tamanho da senha deve ser 6 ou menor caso não sejam permitidas letras repetidas.";
                }
                else
                {
                    configuracao->tamanhoDaSenha = novoValor;
                }
                break;
            
            case 2:
                executarTelaMaximoTentativas(&configuracao->maximoDeTentativas);
                break;

            case 3:
                configuracao->dicasEspecificamPosicao = !configuracao->dicasEspecificamPosicao;
                break;
            
            case 4:
                if(configuracao->permitirLetrasRepetidas)
                {
                    if(configuracao->tamanhoDaSenha > 6)
                    {
                        erro = "O tamanho da senha deve ser 6 ou menor para desabilitar as letras repetidas.";
                    }
                    else
                    {
                        configuracao->permitirLetrasRepetidas = 0;
                        configuracao->permitirAlfabetoInteiro = 0;
                    }
                }
                else configuracao->permitirLetrasRepetidas = 1;
                break;
            
            case 5:
                if(!configuracao->permitirLetrasRepetidas)
                {
                    erro = "O alfabeto inteiro só pode ser permitido com letras repetidas.";
                }
                else
                {
                    configuracao->permitirAlfabetoInteiro = !configuracao->permitirAlfabetoInteiro;
                }
                break;
            
            case 6:
                definirConfiguracaoPadrao(configuracao);
                break;
        }
        if(opcao != 7) salvarConfiguracao(configuracao);
    }
    while(opcao != 7);
}