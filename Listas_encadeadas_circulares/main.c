#include "lib.h"

void printa_lista(TipoListaCircular *prim);

int main(int argc, char const *argv[]) {
  TipoListaCircular *prim = NULL, *lista2;
  int i, tam = 0, chave = 0, valor = 0, no = 0, op1 = 0;
  printf("Digite o tamanho da lista circular desejada: ");
  scanf("%d", &tam);
  for (i = 0; i < tam; i++) {
    valor = rand () % 50;
    chave = rand () % 50;
    printf("Valor gerado para ser inserido: %d\n", valor);
    insereInicioListaCircular(&prim, chave, valor);
  }
  printa_lista(prim);
  do {
		printf("Digite uma chave para remover um nó: ");
		scanf("%d", &no);
		removeNo(&prim, no);
		printa_lista(prim);
		printf("Digite 1 para remover novamente ou qualquer outro número para prosseguir com o código: ");
		scanf("%d", &op1);
	}while(op1 == 1);
	printf("Nova lista com chaves pares da lista anterior:\n");
	lista2 = copiaListaPar(prim);
	printa_lista(lista2);
  return 0;
}

void printa_lista(TipoListaCircular *prim) {
  TipoListaCircular *listaAux = prim;
  if(prim == NULL) {
    printf("Lista vazia.\n");
    return;
  }
  do {
  	printf("Chave: %d || Valor: %d\n", listaAux->chave, listaAux->valorQualquer);
    listaAux = listaAux->prox;
  }while(listaAux != prim);
  printf("\n");
}
