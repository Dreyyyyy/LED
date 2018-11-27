#include "lib.h"

//Todo o código está comentado para fixação.

/* -------------------------> Insercao inicio
* Insere novo nó no início de uma lista duplamente encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaEncadeada *insereInicioListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor) {
	if (*prim == NULL) {//Insere o primeiro nó caso a lista esteja vazia
		*prim = (TipoListaEncadeada*)malloc(sizeof(TipoListaEncadeada));//Alocação de memória dinâmica
		if (*prim == NULL) return NULL;//Verifica se a linha acima foi bem sucedida
		else {//Aloca os dados em tal nó
			(*prim)->chave = chave;
			(*prim)->valorQualquer = valor;
			(*prim)->ant = NULL;//Como é o primeiro nó, não há nó anterior
			(*prim)->prox = NULL;//Como é o primeiro nó, não há nó sucessor
		}
	}
	else {//Insere um novo nó na lista já existente
		TipoListaEncadeada *novoNo = (TipoListaEncadeada*)malloc(sizeof(TipoListaEncadeada));//Alocação de memória
		if (novoNo == NULL) return NULL;//Verifica se a linha acima foi bem sucedida
		else {//Aloca os dados em tal nó
			novoNo->chave = chave;
			novoNo->valorQualquer = valor;
			novoNo->ant = NULL;//Não existe nó anterior
			novoNo->prox = *prim;//"->prox" aponta para o primeiro nó atual
			(*prim)->ant = novoNo;//"->ant" aponta para o novo nó alocado
			*prim = novoNo;//Primeiro nó passa a ser o novo nó
		}
	}
	return *prim;
}

void printa_lista(TipoListaEncadeada *lista) {//Função para printar os elementos da lista
	TipoListaEncadeada *listaAux = lista;//Lista auxiliar para não mudar o endereço da lista original
	if (listaAux == NULL) {//Verifica se a lista está vazia
		printf("Lista vazia!\n");
		return;
	}	
	do {//Condição do laço: Enquanto a lista não chegar ao seu fim, printa o valor e a chave de cada nó
		printf("Chave:%d || Valor:%d\n", listaAux->chave, listaAux->valorQualquer);
		listaAux = listaAux->prox;
	}while(listaAux != NULL);
}

/* -------------------------> Insercao final
* Insere novo nó no final de uma lista duplamente encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.*/

TipoListaEncadeada *insereFimListaEncadeada(TipoListaEncadeada **prim, TipoChave chave, TipoValor valor) {
	if (*prim == NULL) {//Insere o primeiro nó caso a lista esteja vazia
		*prim = (TipoListaEncadeada*)malloc(sizeof(TipoListaEncadeada));//Alocação de memória
		if (*prim == NULL) return NULL;//Verifica se a linha acima foi bem sucedida
		else {//Aloca os dados em tal nó
			(*prim)->chave = chave;
			(*prim)->valorQualquer = valor;
			(*prim)->ant = NULL;//Como é o primeiro nó, não há nó anterior
			(*prim)->prox = NULL;//Como é o primeiro nó, não há nó sucessor
		}
	}
	else {//Insere um novo nó na lista já existente 
		TipoListaEncadeada *listaAux = *prim, *novoNo = (TipoListaEncadeada*)malloc(sizeof(TipoListaEncadeada));//Alocação de memória dinâmica
		if (novoNo == NULL) return NULL;//Verifica se a linha acima foi bem sucedida
		else {
			while (listaAux->prox != NULL) {//Condição do laço: Enquanto a lista auxiliar não chegar ao seu fim
				listaAux = listaAux->prox;//Avança entre a lista
			}
			novoNo->chave = chave;//Aloca os dados na lista
			novoNo->valorQualquer = valor;
			novoNo->prox = NULL;//Próximo elemento não existe
			novoNo->ant = listaAux;//Nó anterior apontará para o fim atual da lista
			listaAux->prox = novoNo;//Fim da lista passa a ser o novo nó
		}
	}
	return *prim;
}

/*-------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.*/

void removeNo(TipoListaEncadeada **prim, TipoChave chave) {
	if (*prim == NULL) return;//Verifica se a lista está vazia
	TipoListaEncadeada *listaAux = *prim;
	while (listaAux != NULL && listaAux->chave != chave) {//Condição do laço: Enquanto a lista não chegar ao fim ou a chave ser encontrada
		listaAux = listaAux->prox;
	}
	if (listaAux == NULL) return;//Caso a lista tenha chegao ao fim, a chave buscada não se encontra na lista
	else {
		if (listaAux->ant == NULL) {//Caso exista mais de um elemento na lista e a chave está no primeiro, remove este
			if (listaAux->prox == NULL) {//Caso exista apenas um elemento na lista, remove este
				free (listaAux);
				listaAux = NULL;
				*prim = NULL;
			}
			else {
				*prim = (*prim)->prox;//Primeiro nó passa a ser o seu sucessor
				(*prim)->ant = NULL;//Nó anterior não existe
				free (listaAux);//Libera o nó desejado
				listaAux = NULL;//Evita leitura e escrita ilegal
			}	
		}
		else {//Caso esteja no meio da lista, remove este
			listaAux->ant->prox = listaAux->prox;//Caso contrário, o nó anterior ao nó encontrado com a chave, apontará o seu ponteiro "prox" para o "prox" do nó encontrado com a chave
			if (listaAux->prox != NULL) listaAux->prox->ant = listaAux->ant;//Caso o próximo nó do nó encontrado com a chave não for nulo, este apontará o seu ponteiro "ant" para o nó anterior ao nó encontrado com a chave
			free (listaAux);//Após a parte anterior e posterior ao nó com a chave já estarem vinculadas, por fim o nó é liberado a memória
			listaAux = NULL;//Evita leitura e escrita ilegal
		}	
	}		
}

/*-------------------------> Cria cópia
* Cria uma nova lista cujos nós são múltiplos de 3.
* Devolve o ponteiro para
* o primeiro nó da nova lista.*/
TipoListaEncadeada *copiaLista3(TipoListaEncadeada *prim) {
	int chave = 0, valor = 0;//Variáveis locais declaradas
	TipoListaEncadeada *listaAux = NULL, *novaLista = NULL;//Ponteiros declarados
	for (listaAux = prim; listaAux != NULL; listaAux = listaAux->prox) {//Condição do laço: Enquanto a lista não chegar ao fim
		if (listaAux->chave % 3 == 0) {//Caso a chave seja divisível por 3 (múltipla), o nó onde essa chave reside será copiado para a nova lista
			chave = listaAux->chave;
			valor = listaAux->valorQualquer;
			insereInicioListaEncadeada(&novaLista, chave, valor);//A inserção de tais nós será feita no ínicio
		}
	}
	return novaLista;
}

