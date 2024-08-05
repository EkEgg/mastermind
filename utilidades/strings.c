#include "strings.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void emCaixaAlta(char *destino, char *origem)
{
    char c = origem[0];
    size_t i;
    
    for(i = 0; c != '\0'; i++)
    {
        destino[i] = toupper(c);
        c = origem[i+1];
    }
}

void apararPontas(char *destino, char *origem)
{
    size_t i, j, primeiroNaoEspaco, ultimoNaoEspaco;
    primeiroNaoEspaco = 0;
    while(origem[primeiroNaoEspaco] != '\0' && isspace(origem[primeiroNaoEspaco]))
    {
        primeiroNaoEspaco++;
    }
    ultimoNaoEspaco = primeiroNaoEspaco;
    for(i = primeiroNaoEspaco; origem[i] != '\0'; i++)
    {
        if(!isspace(origem[i])) ultimoNaoEspaco = i;
    }
    j = 0;
    for(i = primeiroNaoEspaco; i <= ultimoNaoEspaco; i++)
    {
        destino[j] = origem[i];
        j++;
    }
    destino[j] = '\0';
}

int ehVazia(char *string)
{
    return string[0] == '\0';
}


void simplificarEspacos(char *destino, char *origem)
{
    size_t i, k = 0;
    int espaco = 1;

    for(i = 0; i < strlen(origem); i++)
    {
        if(espaco)
        {
            destino[k] = origem[i];
            k++;
        }
        if(origem[i+1] == ' ' && origem[i] == ' ') espaco = 0;
        else espaco = 1;
    }
    destino[k] = '\0';    
}


int ehNumero(char *string)
{
    size_t i;
    if(ehVazia(string)) return 0;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(!isdigit(string[i])) return 0;
    }
    return 1;
}

int contemRepeticao(char *string)
{
    size_t i, j;
    for(i = 0; string[i] != '\0'; i++)
    {
        for(j = 0; string[j] != '\0'; j++)
        {
            if(i != j && string[i] == string[j]) return 1;
        }
    }
    return 0;
}

int estahEmIntervalo(char *string, char minimo, char maximo)
{
    size_t i;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(string[i] < minimo || string[i] > maximo) return 0;
    }
    return 1;
}

char *novaString(size_t numeroDeCaracteres)
{
    char *string = (char*) malloc(sizeof(char) * (numeroDeCaracteres+1));
    string[0] = '\0';
    return string;
}

int ehIdentificadorValido(char *string)
{
    size_t i;
    for(i = 0; string[i] != '\0'; i++)
    {
        if(!(isalnum(string[i]) || string[i] == ' ')) return 0;
    }
    return 1;
}