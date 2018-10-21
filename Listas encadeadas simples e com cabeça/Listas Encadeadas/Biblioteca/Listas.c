#include <stdio.h>
#include "Prototipos.h"
#include <stdlib.h>

/*===================================>PROCEDIMENTOS BÁSICOS DE LISTAS
/* -------------------------> Insercao no início
* Insere novo nó no início de uma lista encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/

TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor) {
  TipoListaSimples *noAux = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
  if (noAux == NULL) return NULL;
  noAux->chave = chave;
  noAux->valorQualquer = valor;
  noAux->prox = *prim;
  *prim = noAux;
  return noAux;
}

/* -------------------------> Atualiza primeiro no
* Caso o primeiro nó exista, atualiza o campo
* valorQualquer com novoValor. É dado o ponteiro para
* o primeiro nó.
*/

void atualizaValor(TipoListaSimples *prim, TipoValor novoValor) {
  if (prim != NULL) prim->valorQualquer = novoValor;
}

/*
-------------------------
> Remoção no início
* Remove o primeiro nó de uma lista
* caso ele exista. O segundo, se existir, passará
* a ser o primeiro.
*/

void removePrimeiroNo(TipoListaSimples **prim) {
  TipoListaSimples *noAux = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
  if (noAux != NULL) {
    noAux = *prim;
    *prim = (*prim)->prox;
    free(noAux);
  }
}

/* -----------------> Busca pelo endereço de um nó dado um valor de chave
* Devolve ponteiro para o nó cujo valor chave é 'chave'
* ou NULL caso este não exista.
*/

TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave) {
  if (prim == NULL) return NULL;
  while (prim != NULL && prim->chave != chave) {
    prim = prim->prox;
  }
  return prim;
}

/* -------------------------> Inserção no fim de uma lista
* Insere nó no fim de uma lista dada a referência do ponteiro
* do primeiro nó.
* Devolve endereço do novo nó ou NULL em caso de
* insucesso.
*/

TipoListaSimples * insereFimListaSimples(TipoListaSimples **prim, TipoChave chave) {
  TipoListaSimples *listaAux = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
  if (listaAux == NULL) return NULL;
  TipoListaSimples *novo_No = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
  if (novo_No == NULL) return NULL;
  novo_No->chave = chave;
  novo_No->prox = NULL;
  listaAux = *prim;
  if (listaAux == NULL) {
    listaAux = novo_No;
  }
  while (listaAux != NULL) {
    listaAux = listaAux->prox;
  }
  listaAux = novo_No;
  return listaAux;
}
