/*5.
Crie um programa que contenha um array de float contendo 10 elementos. Imprima o endereço de cada posição desse array.*/

#include <stdio.h>
#include <stdlib.h>

float *aloca_Ponteiro();
void imprime_Endereco(float *array);
void desaloca_Ponteiro(int *p);

int main() {
	int i;
	float *array = aloca_Ponteiro();
	for(i = 0; i < 10; i++) {
		printf("Digite o %dº valor: ", i+1);
		scanf("%f", array+i);
	}
	imprime_Endereco(array);
	return 0;
}

float *aloca_Ponteiro() {
	float *p_Local = NULL;
	p_Local = (float*)malloc(10 * sizeof(float));
	if(p_Local == NULL) printf("O SO não liberou memória!\n");
	return p_Local;
}

void imprime_Endereco(float *array) {
	int i;
	for(i = 0; i < 10; i++) {
		printf("Endereço do %dº valor: %x\n", i+1, &array[i]);
	}
	free(array);
}

void desaloca_Ponteiro(int *p) {
    if(p == NULL) return;
    free(p);
}
