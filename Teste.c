#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *arq;
	char nome[10];
	int idade = 0, op = 0;
	arq = fopen("/home/aluno/Área de Trabalho/101/teste.txt", "a");
	if(arq == NULL) printf("Diretório inexistente.\n");
	else {
		do {
			printf("Digite um nome e uma idade, separando por espaço: ");
			scanf("%s %d", nome, &idade);
			fprintf(arq, "%s %d\n", nome, idade);
			printf("Deseja adicionar mais dados? Tecle 1 para continuar: ");
			scanf("%d", &op);
		}while(op == 1);
	}
	fclose(arq);
	fopen("/home/aluno/Área de Trabalho/101/teste.txt", "r");	
	while(!feof(arq)) {
		fscanf(arq, "%s %d", nome, &idade);
		printf("%s %d\n", nome, idade);
	}
	return 0;
}
