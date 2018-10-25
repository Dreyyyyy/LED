/*Fazer as rotinas de:

- Inserção 

- Remoção

- Busca

Obedecendo as restrições no uso de Filas.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int elemento;
	struct No *prox;	
}No;

typedef struct inicio_fim {
	No *inicio;
	No *fim;
}InicioFim;

// - Cria a cabeça da lista(protótipo)
int cria_cabeca(InicioFim *fila);

// - Verifica se a fila está vazia(protótipo)
//int verifica_lista(InicioFim *fila);

// - Printa lista(protótipo)
void printa_fila(InicioFim *fila);

// - Inserção(protótipo)
int insere_fila(InicioFim *fila, int elemento);

// - Remoção(protótipo)
int remove_fila(InicioFim *fila);

// - Busca(protótipo)
int busca_sequencial(InicioFim *fila, int ele);

// - Main
int main () {
	InicioFim *fila;
	int ins = 0, i, num, op, esc, ele, res;
	cria_cabeca(fila);
	do {
		printf ("Escolha uma das opções abaixo: ");
		printf ("\n1 - inserir elementos;\n2 - remover elementos;\n3 - buscar elementos.\n");
		printf ("Digite uma das opções disponíveis: ");
		scanf ("%d", &op);
		switch (op) {
			case 1:
				printf ("Digite o número desejado de inserções em sua fila: ");
				scanf ("%d", &ins);
				for (i = 0; i < ins; i++) {
					printf ("Digite o %dº número a ser inserido na fila: ", i+1);
					scanf ("%d", &num);
					insere_fila (fila, num);
					printa_fila (fila);
				}break;	
			case 2:
				printf ("Removendo nó da fila\n");
				remove_fila (fila);
				printa_fila (fila);break;
			case 3:
				printf ("Digite o elemento que deseja buscar na lista: ");
				scanf("%d", &ele);	
				res = busca_sequencial(fila, ele);
				if (res != 0) printf("Elemento %d encontrado!\n", res);
				else printf("Elemento %d não encontrado.\n", ele);				
		}
		printf ("Deseja continuar? Digite 1 para sim: ");
		scanf ("%d", &esc);	
	}while (esc != 0);	
	return 0;
}

// - Cria a cabeça da lista(função)
int cria_cabeca(InicioFim *fila) {
	No *filaAux = (No*)malloc(sizeof(No));
	if (filaAux == NULL) return 0;
	else {
		filaAux->prox = NULL;
		fila->inicio = fila->fim = filaAux;
		return 1;
	}
}

// - Verifica se a fila está vazia(função)
int verifica_lista (InicioFim *fila) {
	if (fila->inicio->prox == NULL) return 1;
	else return 0;
}

// - Printa fila(função)
void printa_fila (InicioFim *fila) {
	No *filaAux = fila->inicio->prox;
	if (filaAux == NULL) printf("Lista vazia!\n");
	while (filaAux != NULL) {
		printf ("Elemento: %d\n", filaAux->elemento);
		filaAux = filaAux->prox;
	}
}

// - Inserção(função)
int insere_fila(InicioFim *fila, int elemento) {
	No *noAux = (No*)malloc(sizeof(No*));
	if (noAux == NULL) return 0;
	else {
		noAux->elemento = elemento;
		noAux->prox = NULL;
		fila->fim->prox = noAux;
		fila->fim = noAux;
		return 1;
	}	
}

// - Remoção(função)
int remove_fila(InicioFim *fila) {
	if (verifica_lista (fila) == 1) return 0;
	else {
		No *filaAux = fila->inicio;
		fila->inicio = fila->inicio->prox;
		free (filaAux);
		return 1;
	}
}

// - Busca(função)
int busca_sequencial(InicioFim *fila, int ele) {
	No *filaAux = NULL;
	for (filaAux = fila->inicio->prox; filaAux !=NULL; filaAux = filaAux->prox) {
		if (filaAux->elemento == ele) return filaAux->elemento;
	}
	return 0;
}
