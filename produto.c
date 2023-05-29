#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

//----------------------------------------------------------
// Função para organizar os preços por ordem crescente.
void valoresOrdemCrescente(Produto p[], int n)
{
    int x, z;
    Produto t;

    for (x = 0; x < n - 1; x++)
    {
        for (z = x + 1; z < n; z++)
        {
            if (p[x].valor > p[z].valor)
            {
                t = p[x];
                p[x] = p[z];
                p[z] = t;
            }
        }
    }
}

//----------------------------------------------------------
// Função para imprimir produtos.
void imprimeProduto(Produto produto)
{
    printf("\n-----------------------------\n"
           "Informações do produto: \n"
           "\nCódigo: %d\n"
           "\nDescrição: %s\n"
           "\nValor: %.2f\n",
           produto.codigoProduto,
           produto.descricao,
           produto.valor);
}

//----------------------------------------------------------
// Função para cadastrar produtos.
Produto cadastraProduto()
{
    Produto cadastro;

    system("cls");
    printf("\n-----------------------------\n"
           "Cadastro do produto\n");

    printf("\nInforme o código do produto: ");
    scanf("%d", &cadastro.codigoProduto);
    fflush(stdin);

    printf("\nInforme a descrição do produto: ");
    gets(cadastro.descricao);

    printf("\nInforme o valor do produto (R$): ");
    scanf("%f", &cadastro.valor);
    fflush(stdin);

    return cadastro;
}

//------------------------------------------------------------------------------------------------
// Função para salvar informações da estrutura em arquivo txt.
void salvarProdutosTXT(Produto *produtos, int i_produtos)
{

    FILE *fp;

    if ((fp = fopen(ARQUIVO_PRODUTOS, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo produtos.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_produtos; n++)
    {
        fprintf(fp, "%d|%s|%f\n",
                produtos[n].codigoProduto,
                produtos[n].descricao,
                produtos[n].valor);
    }

    fclose(fp);
}

//------------------------------------------------------------------------------------------------
// Função para carregar dados do arquivo txt para estrutura.
int carregarProdutosTxt(Produto *produtos)
{
    FILE *fp;
    char buffer[1024];
    int i_produtos = 0;

    if ((fp = fopen(ARQUIVO_PRODUTOS, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo produtos.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove CR e LF.
        buffer[strlen(buffer) - 1] = '\0';

        // Adiciona os campos separados por PIPE para os campos da estrutura.
        (*(produtos + i_produtos)).codigoProduto = atoi(strtok(buffer, "|"));
        strcpy((*(produtos + i_produtos)).descricao, strtok(NULL, "|"));
        (*(produtos + i_produtos)).valor = atof(strtok(NULL, "|"));

        i_produtos++;
    }

    fclose(fp);

    return (i_produtos);
}