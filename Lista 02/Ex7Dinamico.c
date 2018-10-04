/*7.
Crie  um  programa  que  contenha  um  array  de  inteiros  contendo  5  elementos.  Utilizando apenas aritmética de ponteiros, leia esse array do teclado e imprima o dobro de cada valor lido. */

#include <stdio.h>
#include <stdlib.h>

int *aloca_Memoria();
void imprime_Dobro(int *array);
void desaloca_Ponteiro(int *p);

int main() {
	int i, *array = aloca_Memoria();
	for(i = 0; i < 5; i++) {
		printf("Digite o %dº elemento: ", i+1);
		scanf("%d", array+i);
	}
	imprime_Dobro(array);
	return 0;
}

int *aloca_Memoria() {
	int *p_Local = NULL;
	p_Local = (int*)malloc(5 * sizeof(int));
	if(p_Local == NULL) printf("O SO não liberou memória!\n");
	return p_Local;
}

void imprime_Dobro(int *array) {
	int i;
	for(i = 0; i < 5; i++) {
		printf("O dobro do %dº elemento será: %d\n", i+1, (*array+i) * 2);
	}
	free(array);
}

void desaloca_Ponteiro(int *p) {
    if(p == NULL) return;
    free(p);
}
