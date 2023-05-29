#ifndef PRODUTO_H
#define PRODUTO_H

//----------------------------------------------------------
// Definição do arquivo de persistência dos dados.
#define ARQUIVO_PRODUTOS "./db/produtos.txt"

//----------------------------------------------------------
// Estrutura de dados produto.
typedef struct
{
    int codigoProduto;
    char descricao[100];
    float valor;
} Produto;

//----------------------------------------------------------
// Estrutura de dados produto.
Produto cadastraProduto();
void imprimeProduto(Produto produto);
int carregarProdutosTxt(Produto *produtos);
void salvarProdutosTXT(Produto *produtos, int i_produtos);
void valoresOrdemCrescente(Produto p[], int n);

#endif