#include "lib.h"

void printa_lista(TipoListaCircular *prim);

int main(int argc, char const *argv[]) {
  TipoListaCircular *prim = NULL;
  int i, tam = 0, chave = -1, valor = 0, no = 0;
  printf("Digite o tamanho da lista circular desejada: ");
  scanf("%d", &tam);
  for (i = 0; i < tam; i++) {
    valor = rand () % 100;
    printf("Valor gerado para ser inserido: %d\n", valor);
    insereInicioListaCircular(&prim, chave, valor);
  }
  printa_lista(prim);
  printf("Digite uma chave para remover um nó: ");
  scanf("%d", &no);
  removeNo(&prim, no);
  printa_lista(prim);
  return 0;
}

void printa_lista(TipoListaCircular *prim) {
  TipoListaCircular *listaAux = prim, *primeiro = prim;
  if(prim == NULL) return;
  do {
      printf("Chave: %d || Valor: %d\n", listaAux->chave, listaAux->valorQualquer);
      listaAux = listaAux->prox;
  }while(listaAux != primeiro);
  printf("\n");
}
