#include "bib.h"

/* -------------------------> Insercao inicio
* Insere novo nó no início de uma lista duplamente encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaEncadeada *insereInicioListaEncadeada(TipoListaEncadeada **prim,TipoChave chave, TipoValor valor) {
  TipoListaEncadeada *novoNo = (TipoListaEncadeada*)malloc(sizeof(TipoListaEncadeada));//Aloca um novo nó
  if (novoNo == NULL) return NULL;
  novoNo->chave = chave;
  novoNo->valorQualquer = valor;
  novoNo->prox = *prim;//Aponta o ponteiro "prox" do novo nó para o "*prim" atual
  novoNo->ant = NULL;//Aponta o anterior para nulo (Necessário para a primeira iteração com lista vazia)
  if (*prim != NULL) {//Verifica se a lista já existia antes da iteração
    (*prim)->ant = novoNo;//Caso já existir, o anterior do nó que já tinha sido alocado antes aponta para o novo nó
  }
  *prim = novoNo;//O primeiro nó da lista passar a ser o novo nó alocado
  return *prim;
}

void printa_lista(TipoListaEncadeada *lista) {//Função para printar os elementos da lista
  TipoListaEncadeada *listaAux = lista;
  if (listaAux == NULL) printf("Lista vazia!\n");
  do {
    printf("Chave: %d || Valor: %d\n", listaAux->chave, listaAux->valorQualquer);
    listaAux = listaAux->prox;
  }while (listaAux != NULL);
}

/* -------------------------> Insercao final
* Insere novo nó no final de uma lista duplamente encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.*/

TipoListaEncadeada *insereFimListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor) {
  TipoListaEncadeada *novoNo = (TipoListaEncadeada*)malloc(sizeof(TipoListaEncadeada));//Aloca um novo nó
  if (novoNo == NULL) return NULL;
  novoNo->chave = chave;
  novoNo->valorQualquer = valor;
  novoNo->prox = NULL;
  if (*prim == NULL) {//Verifica se a lista estava posteriormente vazia
    novoNo->ant = NULL;//Caso vazia, o nó anterior ao novo nó inserido será nulo, e o ponteiro que nomeia o primeiro nó apontará para o nó inserido
    *prim = novoNo;
    return *prim;
  }
  else {//Caso a lista não esteja vazia
    TipoListaEncadeada *listaAux = *prim;//Aloca um nó auxiliar para percorrer a lista
    while (listaAux->prox != NULL) {//Laço para achar o fim da lista
      listaAux = listaAux->prox;
    }
    listaAux->prox = novoNo;//Quando o final for encontrado, o próximo do último nó da lista (que no caso será NULL) recebe o novo nó
    novoNo->ant = listaAux;//Como aqui existia uma lista posteriormente, o ponteiro para o anterior do novo nó inserido aponta para a lista;
    return *prim;
  }
}

/*-------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.*/

void removeNo(TipoListaEncadeada **prim, TipoChave chave) {
  if(*prim == NULL) return;//Verifica se a lista está vazia
  TipoListaEncadeada *listaAux = *prim;//Aloca um nó para percorrer a lista
  while(listaAux != NULL && listaAux->chave != chave) {//Laço de busca: Buscará pela chave pedida para remoção até a lista ser nula, ou seja, até o fim da lista
    listaAux = listaAux->prox;
  }
  if(listaAux == NULL) return;//Caso a o laço tenha chegado ao fim da lista, então o elemento pedido não se encontra na mesma
  else listaAux->ant->prox = listaAux->prox;//Caso contrário, o nó anterior ao nó encontrado com a chave, apontará o seu ponteiro "prox" para o "prox" do nó encontrado com a chave
  if(listaAux->prox != NULL) listaAux->prox->ant = listaAux->ant;//Caso o próximo nó do nó encontrado com a chave não for nulo, este apontará o seu ponteiro "ant" para o nó anterior ao nó encontrado com a chave
  free(listaAux);//Após a parte anterior e posterior ao nó com a chave já estarem vinculadas, por fim o nó é liberado a memória.
  listaAux = NULL;//Evita vazamento de memória!!!!!
  return;
}

/*-------------------------> Cria cópia
* Cria uma nova lista cujos nós são múltiplos de 3.
* Devolve o ponteiro para
* o primeiro nó da nova lista.

TipoListaEncadeada *copiaLista3(TipoListaEncadeada *prim) {

}*/
