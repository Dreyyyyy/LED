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
      return novoNo;
    }
  }
}

/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
void removeNo(TipoListaCircular **prim, TipoChave chave) {
  if (*prim == NULL) return;//Se a lista for nula, a função é encerrada;
  if (*prim == (*prim)->prox) {
    if ((*prim)->chave == chave) {
      free(*prim);
      *prim = NULL;
      return;//Se a lista contém apenas um elemento, este é removido e a função é encerrada;
    }
    else {
      printf("Chave inexistente na lista!\n");//Caso a chave não exista no único nó da lista;
      return;
    }
  }
  TipoListaCircular *listaAux = NULL, *listaAux2 = NULL;
  for (listaAux = *prim; listaAux != NULL; listaAux = listaAux->prox) {
    if (listaAux->chave == chave) {
      free(listaAux);
      *prim = listaAux->prox;break;
    }
  }
}

/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós tem valor chave par
* Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
//TipoListaCircular *copiaListaPar(TipoListaCircular *prim);
