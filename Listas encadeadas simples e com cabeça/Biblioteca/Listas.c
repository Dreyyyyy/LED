#include <stdio.h>
#include "Prototipos.h"
#include <stdlib.h>

/*===================================>PROCEDIMENTOS BÁSICOS DE LISTAS
/* -------------------------> Insercao no início
* Insere novo nó no início de uma lista encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.*/

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
* o primeiro nó.*/

void atualizaValor(TipoListaSimples *prim, TipoValor novoValor) {
  if (prim != NULL) prim->valorQualquer = novoValor;
}

/*
-------------------------> Remoção no início
* Remove o primeiro nó de uma lista
* caso ele exista. O segundo, se existir, passará
* a ser o primeiro.*/

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
* ou NULL caso este não exista.*/

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
* insucesso.*/

TipoListaSimples * insereFimListaSimples(TipoListaSimples **prim, TipoChave chave) {
  if (*prim == NULL) {
    *prim = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
    if(*prim == NULL) return NULL;
    (*prim)->chave = chave;
    (*prim)->prox = NULL;
  }
  else insereFimListaSimples(&((*prim)->prox), chave);
}

/* -------------------------> Remoção último nó
* Remove o último nó de uma lista (caso ele exista) dada a
* referência do ponteiro do primeiro nó.*/
void removeUltimoNo(TipoListaSimples **prim) {
  if ((*prim)->prox == NULL) {
    TipoListaSimples *listaAux = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
    if (listaAux == NULL) return;
    listaAux = *prim;
    *prim = (*prim)->prox;
    free(listaAux);
  }
  else removeUltimoNo(&((*prim)->prox));
}

/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.*/
void removeNo(TipoListaSimples **prim, TipoChave chave) {
  TipoListaSimples *listaAux = NULL;
  if ((*prim)->prox == NULL) {
  	if ((*prim)->chave == chave) {
  		free(*prim);
  		*prim = NULL;
  	}
  	else return;		
  }
  for (listaAux = *prim; listaAux != NULL; listaAux = listaAux->prox) {
    if (listaAux->prox->chave == chave) {
      TipoListaSimples *noAux = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
      if (noAux == NULL) return;
      noAux = listaAux->prox->prox;
      free(listaAux->prox);
      listaAux->prox = noAux;
      return;
    }
  }
}

/* -------------------------> Remove todos nós
* Remove TODOS os nos da lista exceto e atualiza
* ponteiro para o primeiro para NULL.
* Dica: recursividade pode ajudar muito!*/
void liberaNos(TipoListaSimples **prim) {
  if(*prim == NULL) return;
  else {
    TipoListaSimples *listaAux = (TipoListaSimples*)malloc(sizeof(TipoListaSimples));
    listaAux = *prim;
    *prim = (*prim)->prox;
    free(listaAux);
    liberaNos(&(*prim));
  }
}

/* -------------------------> Cria cópia 
* Calcula a interseção entre as duas listas
* dadas e insere tais nós numa (nova) terceira
* lista. Devolve o ponteiro para o cabeça da nova lista.
* A interseção deve considerar o campo chave.
TipoListaSimples *intersecaoListas(TipoListaSimples *prim1, TipoListaSimples *prim2) {
	TipoListaSimples *listaAux1 = NULL, *listaAux2 = NULL, *lista3 = (TipoListaSimples*)malloc(sizeof(TipoListaSimples)), *lista3Aux = NULL;
	if (lista3 == NULL) return NULL;
	if (prim1 == NULL && prim2 == NULL) return NULL;
	for (listaAux1 = prim1; listaAux1 != NULL; listaAux1 = listaAux1->prox) {
		for (listaAux2 = prim2; listaAux2 != NULL; listaAux2 = listaAux2->prox) {
			if(listaAux1->chave == listaAux2->chave) {
				lista3Aux = listaAux1;
				lista3Aux->prox = lista3;
				lista3 = lista3Aux;			
			} 
		}
	} 
	return lista3;
}*/

/*================================>PROCEDIMENTOS ESPECÍFICOS DE LISTAS
-------------------------> Cria cópia
* Cria uma nova lista cujos nós têm os mesmos
* valores da lista dada. Devolve o ponteiro para
* o primeiro nó da nova lista.*/
TipoListaSimples *copiaListas(TipoListaSimples *prim) {
	if (prim == NULL) return prim;
	else {
		TipoListaSimples *novaLista = (TipoListaSimples*)malloc(sizeof(TipoListaSimples)), *listaAux = NULL;
		if (novaLista == NULL) return NULL;
		novaLista = prim;
		return novaLista;
	}
}

/* -------------------------> ContaNó.
* Conta o número de nós de uma lista encadeada.
* Retorno número de nós*/
int contaNo(TipoListaSimples **primLista1) {
	TipoListaSimples *listaAux = NULL;
	int nos = 0;
	for (listaAux = *primLista1; listaAux != NULL; listaAux = listaAux->prox) {
		nos++;
	}
	return nos;
}

/* -------------------------> Altura do Nó.
* Escreva uma função que calcule a altura de um dado nó(baseado na
* chave).
* A altura de um nó c em uma lista encadeada é a distância entre c e o
* fim da lista.
* Mais precisamente, a altura de c é o número de passos do caminho que
* leva de c até a último nó da lista.
* Retorno altura do nó */
int alturaNo(TipoListaSimples **primLista1, TipoChave chave) {
	int alt = 0, chaveAux = 0;
	TipoListaSimples *listaAux = NULL;
	for (listaAux = *primLista1; listaAux != NULL; listaAux = listaAux->prox) {
		if (listaAux->chave == chave) chaveAux = 1;
		if (chaveAux) alt++;
	}
	return alt;
}

/* -------------------------> Profundidade do Nó.
* Escreva uma função que calcule a profundidade de um dado nó (baseado na
*chave).
* A profundidade de um nó c em uma lista encadeada é o número de passos do
*único caminho que vai do primeiro nó da lista até c.*/
int profundidadeNo(TipoListaSimples **primLista1, TipoChave chave) {
	int prof = 0;
	TipoListaSimples *listaAux = *primLista1;
	while (listaAux != NULL) {
		if (listaAux->chave == chave) break;
		listaAux = listaAux->prox;
	}
	if (listaAux == NULL) return -1;
	listaAux = *primLista1;
	while (listaAux != NULL) {
		prof++;
		if (listaAux->chave == chave) break;
		listaAux = listaAux->prox;
	}
	return prof;
}
