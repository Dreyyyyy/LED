/*3.
Elaborar  um  programa  que  leia  dois  valores  inteiros  (A  e  B).  Em  seguida  faça uma função que retorne a soma do dobro dos dois números lidos. A função deverá armazenar o dobro de A na variável original A e o dobro de B na variável orginal B. */

#include <stdio.h>
#include <stdlib.h>

int *aloca_Ponteiro();
void dobra_Valores(int *A, int *B);
void desaloca_Ponteiro(int *p);

int main() {
	int *A = aloca_Ponteiro(), *B = aloca_Ponteiro();
	printf("Digite dois valores respectivamente: ");
	scanf("%d%d", A, B);
	dobra_Valores(A, B);
	printf("A dobrado: %d e B dobrado: %d\n", *A, *B);
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

void dobra_Valores(int *A, int *B) {
	*A = (*A) * 2;
	*B = (*B) * 2;
}

void desaloca_Ponteiro(int *p) {
    if(p == NULL) return;
    free(p);
}
