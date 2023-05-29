/**********************************************************
 *  SENAI - SERVIÇO NACIONAL DE APRENDIZAGEM INDUSTRIAL
 *  Unidade Curricular: Lógica de programação
 *  Situação de aprendizagem
 *  Professor: Lucas Antunes
 *  Alunos: Kaio Henrique Manfroi
 *  Luzerna, 26/05/2022
 **********************************************************/

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "produto.h"
#include "cliente.h"
#include "loja.h"
#include "estoque.h"

#define MAX_CLIENTES 100
#define MAX_PRODUTOS 100
#define MAX_LOJAS 100
#define MAX_ESTOQUES 100

Cliente clientes[MAX_CLIENTES];
Produto produtos[MAX_PRODUTOS];
Loja lojas[MAX_LOJAS];
Estoque estoques[MAX_ESTOQUES];

int i_clientes = 0; // Variável de índice do vetor.
int i_produtos = 0; // Variável de índice do vetor.
int i_lojas = 0;    // Variável de índice do vetor.
int i_estoques = 0; // Variável de índice do vetor.

//-----------------------------------------------------------------------------
// Função para adicionar/ler clientes.
void op1()
{
    system("cls");
    printf("***************************************************");
    printf("\n***\tEscolha uma das opções abaixo:\t\t***\n"
           "***************************************************\n\n"
           "\n[1] - Adicionar Cliente\n\n"
           "[2] - Listar Cliente\n\n"
           "[3] - Buscar Cliente pelo CPF\n\n");
    switch (getch())
    {
    case '1':
        clientes[i_clientes++] = cadastraCliente();
        break;

    case '2':
        system("cls");
        for (int n = 0; n < i_clientes; n++)
        {
            imprimeCliente(clientes[n]);
        }
        break;

    case '3':
        system("cls");
        procurarCliente(clientes, i_clientes);
        break;
    }
}

//-----------------------------------------------------------------------------
// Função para adicionar/ler produtos.
void op2()
{
    system("cls");
    printf("***************************************************");
    printf("\n***\tEscolha uma das opções abaixo:\t\t***\n"
           "***************************************************\n\n"
           "\n[1] - Adicionar Produto\n\n"
           "[2] - Listar Produto\n\n"
           "[3] - Ordenar Produtos por Preço (Ordem Crescente).\n\n");
    switch (getch())
    {
    case '1':
        produtos[i_produtos++] = cadastraProduto();
        break;

    case '2':
        system("cls");
        for (int n = 0; n < i_produtos; n++)
        {
            imprimeProduto(produtos[n]);
        }
        break;
        
    case '3':
        system("cls");
        valoresOrdemCrescente(produtos, i_produtos);
        printf("\nValores ordenados com sucesso.\n\n");
    }
}

//-----------------------------------------------------------------------------
// Função para adicionar/ler lojas.
void op3()
{
    system("cls");
    printf("***************************************************");
    printf("\n***\tEscolha uma das opções abaixo:\t\t***\n"
           "***************************************************\n\n"
           "\n[1] - Adicionar Loja\n\n"
           "[2] - Listar Loja\n\n");
    switch (getch())
    {
    case '1':
        lojas[i_lojas++] = cadastraLoja();
        break;

    case '2':
        system("cls");
        for (int n = 0; n < i_lojas; n++)
        {
            imprimeLoja(lojas[n]);
        }
        break;
    }
}

//-----------------------------------------------------------------------------
// Função para adicionar/ler estoques.
void op4()
{
    system("cls");
    printf("***************************************************");
    printf("\n***\tEscolha uma das opções abaixo:\t\t***\n"
           "***************************************************\n\n"
           "\n[1] - Adicionar Estoque\n\n"
           "[2] - Listar Estoque\n\n");
    switch (getch())
    {
    case '1':
        estoques[i_estoques++] = cadastraEstoque();
        break;

    case '2':
        system("cls");
        for (int n = 0; n < i_estoques; n++)
        {
            imprimeEstoque(estoques[n]);
        }
        break;
    }
}

//----------------------------------------------------------
// Função Principal.
int main()
{
    SetConsoleOutputCP((UINT)65001);
    system("color 02");

    i_clientes = carregarClientesTxt(clientes);
    i_produtos = carregarProdutosTxt(produtos);
    i_lojas = carregarLojasTxt(lojas);
    i_estoques = carregarEstoquesTxt(estoques);

    while (1)
    {
        printf("*******************************************************************\n");
        printf("***\tEscolha uma das estruturas abaixo para executar:\t***\n"
                "*******************************************************************\n\n"
               "\n1 - Clientes\n"
               "\n2 - Produtos\n"
               "\n3 - Lojas\n"
               "\n4 - Estoques\n"
               "\n[ESC] - Sair do programa\n\n\n");

        switch (getch())
        {

        case '1':
            op1();
            break;

        case '2':
            op2();
            break;

        case '3':
            op3();
            break;

        case '4':
            op4();
            break;

        case 27:
            salvarClientesTXT(clientes, i_clientes);
            salvarProdutosTXT(produtos, i_produtos);
            salvarLojasTXT(lojas, i_lojas);
            salvarEstoquesTXT(estoques, i_estoques);
            return (0);

        default:
            printf("Comando não implementado\n");
        }

        printf("\n\n\n");
        system("pause");
        system("cls");
    }

    return (0);
}