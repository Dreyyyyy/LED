#include "lib.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void imprimeLista(TipoListaSimples *prim) {
    TipoListaSimples *aux = prim;

	if(aux == NULL) {
		printf("Lista Vazia!\n");
        return;
	}

    do {
        printf("Valor => %d | Chave => %d\n", aux->valorQualquer, aux->chave);
        aux = aux->prox;
    } while(aux != NULL);
}

int main(void) {
    TipoListaSimples *lista = NULL, *no = NULL, *lista2 = NULL;
    int chave, i;

    puts("insereInicioListaSimples()");
    for(i = 0; i < 5; i++) {
        chave = rand() % 50;
        printf("Mandei inserir => %d\n", chave);
        insereInicioListaSimples(&lista, chave, -1);
    }
    printf("\n");
    imprimeLista(lista);

    puts("\natualizaValor()");
    atualizaValor(lista, -2);
    imprimeLista(lista);

    puts("\nremovePrimeiroNo()");
    removePrimeiroNo(&lista);
    imprimeLista(lista);

    no = pesquisaNo(lista, 36);
    printf("\npesquisaNO => %p\n", no);

    insereFimListaSimples(&lista, 344, -2);
    puts("\ninsereFimListaSimples() // 344");
    imprimeLista(lista);

    puts("\nremoveUltimoNo()");
    removeUltimoNo(&lista);
    imprimeLista(lista);

    puts("\nremoveNo() //27");
    removeNo(&lista, 27);
    imprimeLista(lista);

    puts("\ncopiaListas()");
    lista2 = copiaListas(lista);
    imprimeLista(lista2);

    puts("\nintersecaoListas()");
    lista2 = intersecaoListas(lista, lista2);
    imprimeLista(lista2);

    puts("\ninsereRemove()");
    insereRemove(&lista, &lista2);
    imprimeLista(lista);
    puts("\n");
    imprimeLista(lista2);

    /*puts("transplantaNo");
    transplantaNo(&lista, &lista2);
    imprimeLista(lista);
    puts("\n");
    imprimeLista(lista2);
    puts("\n");*/

    puts("\ncontaNo(Lista 1)");
    printf("n = %d\n", contaNo(&lista));

    puts("\nalturaNo(Lista 1) //33");
    printf("h = %d\n\n", alturaNo(&lista, 33));
    imprimeLista(lista);

    puts("\nprofundidadeNo(Lista 1) //33");
    printf("p = %d\n\n", profundidadeNo(&lista, 33));
    imprimeLista(lista);

    puts("\nliberaNos()");
    liberaNos(&lista);
    imprimeLista(lista);

    return 0;
}
