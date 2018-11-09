/*
* Faça uma biblioteca para as definições
* abaixo especificadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int TipoChave;
typedef int TipoValor;

struct TipoListaCircular {
  TipoChave chave;
  TipoValor valorQualquer;
  struct TipoListaCircular *prox;
};

typedef struct TipoListaCircular TipoListaCircular;

TipoListaCircular *novo_no(TipoChave chave, TipoValor valor);

int remove_prim(TipoListaCircular **no);

TipoListaCircular *insereInicioListaCircular(TipoListaCircular **prim, TipoChave chave, TipoValor valor);

void removeNo(TipoListaCircular **prim, TipoChave chave);

TipoListaCircular *copiaListaPar(TipoListaCircular *prim);
