#include "lib.h"

/*===========================>PROCEDIMENTOS BÁSICOS DE LISTAS CIRCULAR
/* -------------------------> Insercao
* Insere novo nó no início de uma lista encadeada circular.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaCircular *insereInicioListaCircular(TipoListaCircular **prim, TipoChave chave, TipoValor valor) {
  if (*prim == NULL) {
    *prim = (TipoListaCircular*)malloc(sizeof(TipoListaCircular));
    if (*prim == NULL) return NULL;
    else {
      (*prim)->chave = chave;
      (*prim)->valorQualquer = valor;
      (*prim)->prox = (*prim);
      return *prim;
    }
  }
  else {
    TipoListaCircular *novoNo = (TipoListaCircular*)malloc(sizeof(TipoListaCircular));
    if (novoNo == NULL) return NULL;
    else {
      novoNo->chave = chave;
      novoNo->valorQualquer = valor;
      novoNo->prox = (*prim)->prox;
      (*prim)->prox = novoNo;
      return *prim;
    }
  }
}

/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
void removeNo(TipoListaCircular **prim, TipoChave chave) {
  if (*prim == NULL) return;
  if ((*prim)->prox == *prim && (*prim)->chave == chave) {
    free(*prim);
    *prim = NULL;
    return;
  }
  else {
    TipoListaCircular **listaAux = &(*prim), **primeiroNo = &(*prim);
    do {
      if ((*listaAux)->chave == chave) {
        free(*listaAux);
        *listaAux = (*listaAux)->prox;
        return;
      }
      *listaAux = (*listaAux)->prox;
    }while (*listaAux != *primeiroNo);
  }
}


/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós tem valor chave par
* Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
//TipoListaCircular *copiaListaPar(TipoListaCircular *prim);
