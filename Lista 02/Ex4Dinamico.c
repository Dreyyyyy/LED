/*4.
Crie um programa que contenha um procedimento que permita passar por parâmetro dois números reais A e B. A função deverá calcular a soma  entre estes dois números e armazenar o resultado na variável A. Este procedimento deverá modificar o valor do primeiro parâmetro. Imprima os valores de A e B na função principal. */

#include <stdio.h>
#include <stdlib.h>

float *aloca_Ponteiro();
void soma(float *A, float *B);
void desaloca_Ponteiro(int *p);

int main() {
	float *A = aloca_Ponteiro(), *B = aloca_Ponteiro();
	printf("Digite dois valores reais respectivamente: ");
	scanf("%f%f", A, B);
	printf("A = %.2f B = %.2f\n", *A, *B);
	soma(A, B);
	printf("Soma armazenada na variável A: %.2f\n", *A);
	desaloca_Ponteiro(A);
	desaloca_Ponteiro(B);
	return 0;
}

float *aloca_Ponteiro() {
	float *p_Local = NULL;
	p_Local = (float*)malloc(sizeof(float));
	if(p_Local == NULL) printf("O SO não alocou memória!\n");
	return p_Local;
}

void soma(float *A, float *B) {
	*A = (*A) + (*B);
}

void desaloca_Ponteiro(int *p) {
    if(p == NULL) return;
    free(p);
}
