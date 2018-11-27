#include "lib.h"

int main(int argc, char const *argv[]) {
  int tam = 0, i, chave = 0, valor = 0, chaveRemove = 0, op = 0;
  TipoListaEncadeada *prim = NULL, *prim2 = NULL;
  printf("Digite o tamanho de sua lista: ");
  scanf("%d", &tam);
  printf("INSERÇÃO NO INÍCIO DA LISTA\n");
  for (i = 0; i < tam; i++) {
    chave = rand () % 50;
    valor = rand () % 50;
    printf("Chave e valor gerados, respectivamente: %d || %d\n", chave, valor);
    insereInicioListaEncadeada(&prim, chave, valor);
  }
  printa_lista(prim);
  printf("INSERÇÃO NO FIM DA LISTA\n");
  for (i = 0; i < tam; i++) {
    chave = rand () % 50;
    valor = rand () % 50;
    printf("Chave e valor gerados, respectivamente: %d || %d\n", chave, valor);
    insereFimListaEncadeada(&prim, chave, valor);
  }
  printa_lista(prim);
  printf("REMOÇÃO DE UM NÓ POR CHAVE\n");
  do {
    printf("Digite uma chave ao qual deseja remover o nó que contenha a mesma da lista: ");
    scanf("%d", &chaveRemove);
    removeNo(&prim, chaveRemove);
    printa_lista(prim);
    printf("Deseja remover outro nó? tecle 1 para sim: ");
    scanf("%d", &op);
  }while(op == 1);
	printf("CÓPIA DA LISTA 1 (APENAS NÓS COM CHAVE MULTIPLA DE 3)\n");
	prim2 = copiaLista3(prim);
	printa_lista(prim2);
  return 0;
}

