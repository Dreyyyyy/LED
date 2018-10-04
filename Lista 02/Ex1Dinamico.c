/*1.
Faça um programa que leia 2 valores inteiros e chame uma função que receba estas 2 variáveis e troque o seu conteúdo, ou seja,
esta função é chamada passando duas variáveis A e B por exemplo e, após a  execução da função, A conteráo valor de B e B terá o valor de A.*/

#include <stdio.h>
#include <stdlib.h>

int *aloca_Ponteiro();
void troca_Valores(int *A, int *B);
void desaloca_Ponteiro(int *p);

int main() {
    int *A = aloca_Ponteiro(), *B = aloca_Ponteiro();
    printf("Digite respectivamente os valores A e B, separando-os com espaço: ");
    scanf("%d%d", A, B);
    troca_Valores(A, B);
    printf("Valor A: %d e valor B: %d\n", *A, *B);
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

void troca_Valores(int *A,int *B) {
    int varAux = 0;
    varAux = *A;
    *A = *B;
    *B = varAux;
}

void desaloca_Ponteiro(int *p) {
    if(p == NULL) return;
    free(p);
}
