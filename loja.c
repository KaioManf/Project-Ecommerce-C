#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"

//----------------------------------------------------------
// Função para imprimir os dados de uma loja.
void imprimeLoja(Loja lojas)
{
    printf("\n-----------------------------\n"
           "Informações da Loja: \n"
           "\nCNPJ: %s\n"
           "\nNome: %s\n"
           "\nSaldo: %s\n",
           lojas.cnpj,
           lojas.nome,
           lojas.segmento);
}

//----------------------------------------------------------
// Função para cadastrar os dados de uma loja.
Loja cadastraLoja()
{
    Loja cadastro;

    system("cls");
    printf("\n-----------------------------\n"
           "Cadastro de Loja\n");

    printf("\nInforme o CNPJ da loja: ");
    gets(cadastro.cnpj);

    printf("\nInforme o nome da loja: ");
    gets(cadastro.nome);

    printf("\nInforme o segmento da loja: ");
    gets(cadastro.segmento);

    return cadastro;
}

//------------------------------------------------------------------------------------------------
// Função para salvar informações da estrutura em arquivo.txt
void salvarLojasTXT(Loja *lojas, int i_lojas)
{

    FILE *fp;

    if ((fp = fopen(ARQUIVO_LOJAS, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo lojas.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_lojas; n++)
    {
        fprintf(fp, "%s|%s|%s\n",
                lojas[n].cnpj,
                lojas[n].nome,
                lojas[n].segmento);
    }

    fclose(fp);
}

//------------------------------------------------------------------------------------------------
// Função para carregar dados do arquivo txt para estrutura.
int carregarLojasTxt(Loja *lojas)
{
    FILE *fp;
    char buffer[1024];
    int i_lojas = 0;

    if ((fp = fopen(ARQUIVO_LOJAS, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo lojas.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove CR e LF.
        buffer[strlen(buffer) - 1] = '\0';

        // Adiciona os campos separados por PIPE para os campos da estrutura.
        strcpy((*(lojas + i_lojas)).cnpj, strtok(buffer, "|"));
        strcpy((*(lojas + i_lojas)).nome, strtok(NULL, "|"));
        strcpy((*(lojas + i_lojas)).segmento, strtok(NULL, "|"));

        i_lojas++;
    }

    fclose(fp);

    return (i_lojas);
}