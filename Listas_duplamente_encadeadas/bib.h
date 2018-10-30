#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
* Faça uma biblioteca para as definições
* abaixo especificadas.
*/
typedef int TipoChave;
typedef int TipoValor;
struct TipoListaEncadeada {
 TipoChave chave;
 TipoValor valorQualquer;
 struct TipoListaEncadeada *prox;
 struct TipoListaEncadeada *ant;
};typedef struct TipoListaEncadeada TipoListaEncadeada;

TipoListaEncadeada *insereInicioListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor);

void printa_lista(TipoListaEncadeada *lista);

TipoListaEncadeada *insereFimListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor);

void removeNo(TipoListaEncadeada **prim, TipoChave chave);

TipoListaEncadeada *copiaLista3(TipoListaEncadeada *prim);
