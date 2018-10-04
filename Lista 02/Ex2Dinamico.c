/*2.
Faça um programa que leia dois valores inteiros e chame uma função que receba estes 2 valores de entrada e retorne o maior valor entre eles.
No programa principal apresente o maior e também o conteúdo das 2 variáveis na tela.*/

#include <stdio.h>
#include <stdlib.h>

int *aloca_Ponteiro();
int maior_Valor(int *A,int *B);
void desaloca_Ponteiro(int *p);

int main() {
	int *A = aloca_Ponteiro(), *B = aloca_Ponteiro(), *maior = aloca_Ponteiro();
	printf("Digite dois valores inteiros, respectivamente: ");
	scanf("%d%d", A, B);
	*maior = maior_Valor(A, B);
	printf("A = %d, B = %d. O maior valor entre ambos é: %d\n", *A, *B, *maior);
	desaloca_Ponteiro(A);
	desaloca_Ponteiro(B);	
	return 0;
}

int *aloca_Ponteiro() {
	int *p_Local = NULL;
	p_Local = (int*)malloc(sizeof(int));
	if(p_Local == NULL) printf("O SO não alocou memória!\n");
	return p_Local;
}

int maior_Valor(int *A,int *B) {
	if(*A > *B) return *A;
	if(*B > *A) return *B;
}

void desaloca_Ponteiro(int *p) {
    if(p == NULL) return;
    free(p);
}
