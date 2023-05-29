#ifndef LOJA_H
#define LOJA_H

//----------------------------------------------------------
// Definição do arquivo de persistência dos dados.
#define ARQUIVO_LOJAS "./db/lojas.txt"

//----------------------------------------------------------
// Estrutura de dados loja.
typedef struct 
{
    char cnpj[14];
    char nome[50];
    char segmento[200];
} Loja;

//----------------------------------------------------------
// Estrutura de dados loja.
Loja cadastraLoja();
void imprimeLoja(Loja lojas);
int carregarLojasTxt(Loja *lojas);
void salvarLojasTXT(Loja *lojas, int i_lojas);

#endif