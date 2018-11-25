#include "lib.h"

TipoListaCircular *novo_no(TipoChave chave, TipoValor valor) {//Alocação comum de um nó circular
  TipoListaCircular *novoNo = (TipoListaCircular*)malloc(sizeof(TipoListaCircular));//Alocando espaço de memória
  if (novoNo == NULL) return NULL;//Caso insucesso, a função retorna "NULL"
  else {//Caso contrário, insere os dados no novo nó
    novoNo->chave = chave;
    novoNo->valorQualquer = valor;
    novoNo->prox = novoNo;
    return novoNo;
  }
}

int remove_prim(TipoListaCircular **lista) {
  if (*lista == NULL) return 0;//Verifica se a lista está vazia
  if ((*lista)->prox == *lista) {//Verifica se existe apenas um elemento na lista, em caso positivo este é removido
    free(*lista);
    *lista = NULL;
    return 1;
  }
  TipoListaCircular *listaAux = *lista, *noAux = *lista;//Ponteiros auxiliares são declarados
  while (listaAux->prox != *lista) {//Condição do laço: Enquanto a lista não chegar ao seu "fim"
    listaAux = listaAux->prox;
  }
  listaAux->prox = (*lista)->prox;//"Fim" da lista aponta para o sucessor do primeiro nó da lista
  *lista = (*lista)->prox;//Início da lista passa a ser o seu sucessor
  free(noAux);//O primeiro nó anterior é removido
  noAux = NULL;//Evita leitura e escrita ilegal
  return 1;
}

/*===========================>PROCEDIMENTOS BÁSICOS DE LISTAS CIRCULAR
/* -------------------------> Insercao
* Insere novo nó no início de uma lista encadeada circular.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaCircular *insereInicioListaCircular(TipoListaCircular **prim, TipoChave chave, TipoValor valor) {
  if (*prim == NULL) {//Verifica se a lista está vazia
    *prim = novo_no(chave, valor);//Aloca um novo nó
    if (*prim == NULL) return NULL;//Verifica se ocorreu tudo bem na alocação
    else return *prim;//Retorna a lista com o único nó inserido
  }
  else {
    TipoListaCircular *novoNo = novo_no(chave, valor), *noAux = *prim;
    while (noAux->prox != *prim) {//Busca o "último" nó da fila, o que aponta para o começo
      noAux = noAux->prox;
    }
    noAux->prox = novoNo;//O "->prox" que apontava para o primeiro anterior agora aponta para o novo nó inserido
    novoNo->prox = *prim;//O "->prox" do novo nó inserido aponta para o primeiro anterior, assim ligando o novo nó com a lista
    *prim = novoNo;//Novo nó passa a ser o primeiro
  }
  return *prim;//Retorna a lista com o novo nó alocado
}

/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
void removeNo(TipoListaCircular **prim, TipoChave chave) {
  if (*prim == NULL) return;//Verifica se a lista está vazia
  TipoListaCircular *noSuc = *prim;
  if (noSuc->chave == chave) remove_prim(&noSuc);//Verifica se o primeiro nó da lista é o procurado, caso for já é removido
  else {
    TipoListaCircular *noAnt = *prim;//Ponteiros auxiliares declarados
    noSuc = noSuc->prox;//Avança o nó sucessor para frente
    while (noSuc->prox != *prim && noSuc->chave != chave) {//Condição do laço: Enquanto não for encontrado a chave ou o "fim" da lista, o laço continua em execução
      noSuc = noSuc->prox;
      noAnt = noAnt->prox;
    }
    if (noSuc == *prim) return;//Ao término do laço, é verificad se este chegou até o "fim" da lista, caso positivo, a chave não foi encontrada
    else {
      noAnt->prox = noSuc->prox;//Caso contrário o nó anterior ao que será removido aponta o "->prox" para onde o nó que será removido apontava
      free(noSuc);//Então o nó pode ser finalmente removido
      noSuc = NULL;//Evita leitura e escrita ilegal
    }
  }
}


/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós tem valor chave par
* Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
TipoListaCircular *copiaListaPar(TipoListaCircular *prim) {
  TipoListaCircular *novaLista = NULL, *listaAux = NULL;//Ponteiros auxiliares declarados
  for (listaAux = prim; listaAux->prox != prim; listaAux = listaAux->prox) {//Condição do laço: Enquanto a lista não chegar ao fim
    if (listaAux->chave % 2 == 0) insereInicioListaCircular(&novaLista, listaAux->chave, listaAux->valorQualquer);//Se os nós que passarem por aqui tiverem seu campo chave par, serão inseridos na nova lista
  }
  return novaLista;//Retorna a nova lista
}
