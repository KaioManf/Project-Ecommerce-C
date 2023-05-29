#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

//----------------------------------------------------------
//
void imprimeEstoque(Estoque estoques)
{

    printf("\n-----------------------------\n"
           "Informações do Estoque: \n"
           "\nCNPJ: %s\n"
           "\nCódigo do Produto: %d\n"
           "\nQuantidade: %d\n",
           estoques.cnpj,
           estoques.codigo_produto,
           estoques.quantidade);
}

//----------------------------------------------------------
// Função para cadastrar os dados de um estoque.
Estoque cadastraEstoque()
{
    Estoque cadastro;

    system("cls");
    printf("\n-----------------------------\n"
           "Cadastro do Estoque\n");

    printf("\nInforme o CNPJ do Estoque: ");
    gets(cadastro.cnpj);

    printf("\nInforme o código do produto: ");
    scanf("%d", &cadastro.codigo_produto);

    printf("\nInforme a quantidade do produto: ");
    scanf("%d", &cadastro.quantidade);
    fflush(stdin);

    return cadastro;
}

//------------------------------------------------------------------------------------------------
// Função para salvar informações da estrutura em arquivo.txt
void salvarEstoquesTXT(Estoque *estoques, int i_estoques)
{
    FILE *fp;

    if ((fp = fopen(ARQUIVO_ESTOQUE, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo estoques.txt");
        exit(-1);
    }

    for (int n = 0; n < i_estoques; n++)
    {
        fprintf(fp, "%s|%d|%d\n",
                estoques[n].cnpj,
                estoques[n].codigo_produto,
                estoques[n].quantidade);
    }

    fclose(fp);
}

//------------------------------------------------------------------------------------------------
// Função para carregar dados do arquivo txt para estrutura.
int carregarEstoquesTxt(Estoque *estoques)
{
    FILE *fp;
    char buffer[1024];
    int i_estoques = 0;

    if ((fp = fopen(ARQUIVO_ESTOQUE, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo estoques.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove CR e LF.
        buffer[strlen(buffer) -1] = '\0';

        // Adiciona os campos separados por PIPE para os campos da estrutura.
        strcpy((*(estoques + i_estoques)).cnpj, strtok(buffer, "|"));
        (*(estoques + i_estoques)).codigo_produto = atoi(strtok(NULL, "|"));
        (*(estoques + i_estoques)).quantidade = atoi (strtok(NULL, "|"));

        i_estoques++;

    }

    fclose(fp);

    return(i_estoques);
}