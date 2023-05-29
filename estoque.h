#ifndef ESTOQUE_H
#define ESTOQUE_H

//----------------------------------------------------------
// Definição do arquivo de persistência dos dados.
#define ARQUIVO_ESTOQUE "./db/estoques.txt"

//----------------------------------------------------------
// Estrutura de dados estoque.
typedef struct
{
    char cnpj[14];
    int codigo_produto;
    int quantidade;
} Estoque;

//----------------------------------------------------------
// Estrutura de dados estoque.
Estoque cadastraEstoque();
void imprimeEstoque(Estoque estoques);
int carregarEstoquesTxt(Estoque *estoques);
void salvarEstoquesTXT(Estoque *estoques, int i_estoques);

#endif