#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

//----------------------------------------------------------
// Função para achar clientes pelo seu CPF.
void procurarCliente(Cliente *clientes, int i_clientes)
{
    int i;
    char cpfSearsh[12];
    int posicao;

    system("cls");
    printf("Digite o CPF do cliente que deseja encontrar: ");
    scanf("%s", cpfSearsh);

    for (i = 0; i<i_clientes; i++)
    {
        if(strcmp(cpfSearsh, clientes[i].cpf) == 0)
        {
            printf("\n\nRegistro Encontrado.\n\n");
            posicao = i;
            printf("Nome: %s\n", clientes[posicao].nome);
            printf("CPF: %s\n", clientes[posicao].cpf);
            printf("Saldo: %.2f\n", clientes[posicao].saldo);
        }
    }
}

//----------------------------------------------------------
// Função para imprimir os dados de um cliente.
void imprimeCliente(Cliente cliente)
{
    printf("\n-----------------------------\n"
           "Informações do Cliente: \n"
           "\nCPF: %s\n"
           "\nNome: %s\n"
           "\nSaldo: %.2f\n",
           cliente.cpf,
           cliente.nome,
           cliente.saldo);
}

//----------------------------------------------------------
// Função para cadastrar os dados de um cliente.
Cliente cadastraCliente()
{
    Cliente cadastro;

    system("cls");
    printf("\n-----------------------------\n"
           "Cadastro de cliente\n");

    printf("\nInforme o CPF do cliente: ");
    gets(cadastro.cpf);

    printf("\nInforme o nome do cliente: ");
    gets(cadastro.nome);

    printf("\nInforme o saldo do cliente (R$): ");
    scanf("%f", &cadastro.saldo);
    fflush(stdin);

    return cadastro;
}

//------------------------------------------------------------------------------------------------
// Função para salvar informações da estrutura em arquivo txt.
void salvarClientesTXT(Cliente *clientes, int i_clientes)
{

    FILE *fp;

    if ((fp = fopen(ARQUIVO_CLIENTES, "w")) == NULL)
    {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        exit(-1);
    }

    for (int n = 0; n < i_clientes; n++)
    {
        fprintf(fp, "%s|%s|%f\n",
                clientes[n].cpf,
                clientes[n].nome,
                clientes[n].saldo);
    }

    fclose(fp);
}

//------------------------------------------------------------------------------------------------
// Função para carregar dados do arquivo txt para estrutura.
int carregarClientesTxt(Cliente *clientes)
{
    FILE *fp;
    char buffer[1024];
    int i_clientes = 0;

    if ((fp = fopen(ARQUIVO_CLIENTES, "r")) == NULL)
    {
        printf("Erro ao abrir o arquivo clientes.txt\n");
        exit(-2);
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        // Remove CR e LF.
        buffer[strlen(buffer) - 1] = '\0';

        // Adiciona os campos separados por PIPE para os campos da estrutura.
        strcpy((*(clientes + i_clientes)).cpf, strtok(buffer, "|"));
        strcpy((*(clientes + i_clientes)).nome, strtok(NULL, "|"));
        (*(clientes + i_clientes)).saldo = atof(strtok(NULL, "|"));

        i_clientes++;
    }

    fclose(fp);

    return (i_clientes);
}