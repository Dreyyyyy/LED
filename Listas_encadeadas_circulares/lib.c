#include "lib.h"

TipoListaCircular *novo_no(TipoChave chave, TipoValor valor) {//Alocação comum de um nó circular, outra hora detalho isso direito (Se eu não esquecer);
  TipoListaCircular *novoNo = (TipoListaCircular*)malloc(sizeof(TipoListaCircular));
  if (novoNo == NULL) return NULL;
  novoNo->chave = chave;
  novoNo->valorQualquer = valor;
  novoNo->prox = novoNo;
  return novoNo;
}

int remove_prim(TipoListaCircular **lista) {
  if (*lista == NULL) return 0;//Verifica se a lista está vazia;
  if (*lista == (*lista)->prox) {//Verifica se existe apenas um nó na lista, em caso positivo remove este;
    free(*lista);
    *lista = NULL;
  }
  else {
    TipoListaCircular *noAtual = *lista;//Auxiliar para busca na lista;
    while (noAtual->prox != *lista) {//Condição do laço: Enquanto o nó não for igual ao primeiro, no caso enquanto ele não for o último ???K(De novo eu não faço ideia de como deu certo, mas deu)
      noAtual = noAtual->prox;
    }
    TipoListaCircular *no = *lista;//Primeiro nó é apontado por um ponteiro;
    noAtual->prox = no->prox;//O nó encontrado(no caso o último, já entendi o que acontecia nos "for" acima mas não to afim de arrumar os comentários agora :")) aponta para o próximo nó da lista, no caso o segundo;
    *lista = no->prox;//A lista passa apontar para o novo primeiro nó;
    free(no);//Enfim é liberado o nó;
    return 1;
  }
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
  if (*prim == NULL) {//Verifica se a lista está vazia;
    *prim = novo_no(chave, valor);//Caso esteja vazia, aloca o primeiro elemento;
  }
  else {
    TipoListaCircular *novoNo = novo_no(chave, valor), *noAux = *prim;
    while (noAux->prox != *prim) {//Busca o último, e consequentemente o primeiro ???(Sei lá como isso deu certo mas tá funcionando aparentemente :"));
      noAux = noAux->prox;
    }
    noAux->prox = novoNo;//O próximo nó do último, que consequentemente é o primeiro ???(Sei lá novamente) aponta para o novo nó alocado;
    novoNo->prox = *prim;//O próximo nó aponta seu próximo para o nó que anteriormente era o primeiro;
    *prim = novoNo;//Novo nó passa a ser o primeiro;
  }
  return *prim;//Retorna a lista com o novo nó alocado;
}

/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
void removeNo(TipoListaCircular **prim, TipoChave chave) {
  if (*prim == NULL) return;//Verifica se a lista está vazia;
  TipoListaCircular *listaAux = *prim;//Auxiliar para percorrer a lista sem alterar o endereço;
  if (listaAux->chave == chave) {//Verifica se o primeiro nó da lista é o que procuramos;
    remove_prim(&listaAux);//Caso for, remove o primeiro;
  }
  else {
    TipoListaCircular *noAnt = listaAux;//Armazena o nó anterior em um ponteiro;
    listaAux = listaAux->prox;//Avança a posição da lista;
    while (listaAux != *prim && listaAux->chave != chave) {//Condição do laço: Enquanto o auxiliar for diferente do início da lista e diferente da chave procurada;
      noAnt = noAnt->prox;
      listaAux = listaAux->prox;
    }
    if (listaAux == *prim) return;//Após o fim da busca, caso a lista tenha sido percorrida por completo, a chave não foi encontrada;
    noAnt->prox = listaAux->prox;//Caso contrário, o nó anterior apontará para onde o nó encontrado apontava;
    free(listaAux);//Agora é removido tal nó, visto que a lista já está conectada;
    listaAux = NULL;//Evita vazamento de memória!!!!!
  }
}


/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós tem valor chave par
* Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
TipoListaCircular *copiaListaPar(TipoListaCircular *prim) {
  TipoListaCircular *novaLista = (TipoListaCircular*)malloc(sizeof(TipoListaCircular)), *listaAux;
  if (novaLista == NULL) return NULL;
  else {
    for (listaAux = prim; listaAux != prim; listaAux = listaAux->prox) {
      if (listaAux->chave % 2 == 0) {
        insereInicioListaCircular(&novaLista, listaAux->chave, listaAux->valorQualquer);
      }
    }
  }
  return novaLista;
}
