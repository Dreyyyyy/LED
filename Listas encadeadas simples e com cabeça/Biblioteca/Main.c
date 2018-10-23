#include "Prototipos.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void imprimeLista(TipoListaSimples *prim) {
    TipoListaSimples *aux = prim;

	if(aux == NULL) {
		printf("\nLista Vazia!\n");
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

    imprimeLista(lista);
    puts("\n");

    puts("atualizaValor()");
    atualizaValor(lista, -2);
    imprimeLista(lista);

    puts("\n");

    puts("removePrimeiroNo()");
    removePrimeiroNo(&lista);
    imprimeLista(lista);

    puts("\n");

    no = pesquisaNo(lista, 3);

    printf("pesquisaNO => %p\n", no);
    insereFimListaSimples(&lista, 344);

   	puts("\n");

    puts("insereFimListaSimples() // 344");
    imprimeLista(lista);

    puts("\n");
    puts("removeUltimoNo()");
    removeUltimoNo(&lista);
    imprimeLista(lista);

    puts("\n");
    puts("removeNo() //33");
    removeNo(&lista, 33);
    imprimeLista(lista);

	puts("\n");
    puts("copiaListas()");
    lista2 = copiaListas(lista);
    imprimeLista(lista2);
    
    /*puts("\n");
    puts("intersecaoListas()");
    lista2 = intersecaoListas(lista, lista2);
    imprimeLista(lista2);
    puts("\n");
    puts("insereRemove()");
    insereRemove(&lista, &lista2);
    imprimeLista(lista);
    imprimeLista(lista2);
    puts("\n");
    puts("transplantaNo");
    transplantaNo(&lista, &lista2);
    imprimeLista(lista);
    puts("\n");
    imprimeLista(lista2);
    */

    puts("\n");
    puts("contaNo()");
    printf("n = %d\n", contaNo(&lista));

    puts("\n");
    puts("alturaNo(27)");
    printf("h = %d\n", alturaNo(&lista, 27));


    puts("profundidadeNo() //36");
    printf("p = %d\n", profundidadeNo(&lista, 36));
    imprimeLista(lista);

    puts("\n");
    puts("liberaNos()");
    liberaNos(&lista);
    imprimeLista(lista);

    return 0;
}
