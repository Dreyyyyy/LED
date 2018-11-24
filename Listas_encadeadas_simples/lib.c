#include "lib.h"

//O código está completamente comentado, pois é o único jeito que eu consigo entender o que aprendo/aplico

TipoListaSimples *aloca_no(int chave, int valor) {
  TipoListaSimples *novoNo = (TipoListaSimples*)malloc(sizeof(TipoListaSimples*));//Aloca uma região da memória para o novo nó
  if (novoNo == NULL) return NULL;//Retorna nulo caso não tenha obtido sucesso
  else {//Caso contrário, isere o novo nó
    novoNo->chave = chave;
    novoNo->valorQualquer = valor;
    novoNo->prox = NULL;
    return novoNo;//Retorna o endereço do novo nó inserido
  }
}

/*===================================>PROCEDIMENTOS BÁSICOS DE LISTAS
/* -------------------------> Insercao no início
* Insere novo nó no início de uma lista encadeada.
* A referência de ponteiro para o primeiro nó e os
* valores dos campos do nó são dados.
* Devolve endereço do nó recém inserido
* ou NULL em caso de insucesso.
*/
TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor) {
  if (*prim == NULL) {//Verifica se a lista está vazia
    *prim = aloca_no(chave, valor);//Se estiver vazia, aloca o primeiro nó
  }
  else {//Caso contrário, alocará o próximo nó
    TipoListaSimples *novoNo = NULL;//Ponteiro criado não apontando para alguma região de memória
    novoNo = aloca_no(chave, valor);//Aloca o novo nó
    novoNo->prox = *prim;//Novo nó aponta seu ponteiro "->prox" para onde o primeiro nó antecessor apontadava
    *prim = novoNo;//Novo nó passa a ser o primeiro nó
  }
  return *prim;//Retorna o endereço do nó inserido
}

/* -------------------------> Atualiza primeiro no
* Caso o primeiro nó exista, atualiza o campo
* valorQualquer com novoValor. É dado o ponteiro para
* o primeiro nó.
*/
void atualizaValor(TipoListaSimples *prim, TipoValor novoValor) {
  if (prim == NULL) return;//Caso não exista nós, a função é terminada antes de ser realizado qualquer operação
  else {//Caso contrário, atualiza o campo com o novo valor
    prim->valorQualquer = novoValor;
  }
}

/* -------------------------> Remoção no início
* Remove o primeiro nó de uma lista
* caso ele exista. O segundo, se existir, passará
* a ser o primeiro.
*/
void removePrimeiroNo(TipoListaSimples **prim) {
  if (*prim == NULL) return;//Caso não exista nós, a função é terminada antes de ser realizado qualquer operação
  else {//Caso contrário, inicia-se a remoção
    TipoListaSimples *noAux = *prim;//auxiliar recebe o endereço do primeiro nó
    *prim = (*prim)->prox;//primeiro nó passa a ser o próximo nó
    free(noAux);//Libera a região para onde o auxiliar aponta
    noAux = NULL;//Evita leitura e escrita ilegal
  }
}

/* -----------------> Busca pelo endereço de um nó dado um valor de chave
* Devolve ponteiro para o nó cujo valor chave é 'chave'
* ou NULL caso este não exista.
*/
TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave) {
  TipoListaSimples *listaAux = NULL;//Cria um ponteiro auxiliar para não alterar os endereços do ponteiro original
  for (listaAux = prim; listaAux != NULL; listaAux = listaAux->prox) {//Condição do laço: Enquanto auxiliar não chegar ao fim da lista
    if (listaAux->chave == chave) return listaAux;//Caso a chave seja encontrada, retorna-se o seu endereço
  }
  return NULL;//Caso contrário retorna-se "NULL"
}

/* -------------------------> Inserção no fim de uma lista
* Insere nó no fim de uma lista dada a referência do ponteiro
* do primeiro nó.
* Devolve endereço do novo nó ou NULL em caso de
* insucesso.
*/
TipoListaSimples * insereFimListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor) {
  if (*prim == NULL) {//Caso base: irá inserir nó apenas na última posição da lista, onde esta é nula
      *prim = aloca_no(chave, valor);//Se estiver vazia, aloca o primeiro nó
      return *prim;//Retorna a lista
  }
  else {
    insereFimListaSimples(&(*prim)->prox, chave, valor);//Caso recursivo: Função que insere no fim da lista recebe o próximo nó como o "prim", até chegar ao caso base (Tipo uma pilha)
  }
}

/* -------------------------> Remoção último nó
* Remove o último nó de uma lista (caso ele exista) dada a
* referência do ponteiro do primeiro nó.
*/
void removeUltimoNo(TipoListaSimples **prim) {
  if (*prim == NULL) return;//Caso não tenha nós na lista, a função é anulada
  if ((*prim)->prox == NULL) {//Caso base: irá buscar o último elemento da lista, para a remoção do mesmo
    TipoListaSimples *noAux = *prim;
    *prim = (*prim)->prox;
    free(noAux);
    noAux = NULL;
    return;
  }
  else {
    removeUltimoNo(&(*prim)->prox);//Caso recursivo: Função que remove o último nó sempre retornará o seu "->prox" até que o caso base seja feito
  }
}

/* -------------------------> Remove nó por valor de chave
* Remove nó cujo valor chave seja igual a 'chave'
* Mantêm lista inalterada caso este não exista.
*/
void removeNo(TipoListaSimples **prim, TipoChave chave) {
  if (*prim == NULL) return;//Caso não tenha nós na lista ou o elemento não tenha sido encontrado, a função é anulada
  if ((*prim)->chave == chave) {//Caso base: Quando a recursividade entrar nessa condição, será removido o nó cujo o valor chave é igual ao buscado
    TipoListaSimples *noAux = *prim;
    *prim = (*prim)->prox;
    free(noAux);
    noAux = NULL;
  }
  else {//Caso recursivo: Função que remove o nó buscado sempre buscará pelo seu "->prox" até que o caso base, ou o caso de lista vazia seja ou lista sem o elemento buscado seja executado
    removeNo(&(*prim)->prox, chave);
  }
}

/* -------------------------> Remove todos nós
* Remove TODOS os nos da lista exceto e atualiza
* ponteiro para o primeiro para NULL.
* Dica: recursividade pode ajudar muito!
*/
void liberaNos(TipoListaSimples **prim) {
  if (*prim == NULL) return;//Caso base:Caso a lista esteja vazia, a função é encerrada
  else {//Caso contrário, remove o primeiro nó (Poderia ter removido o último, ou feito algo diferente, mas aproveitei que já tinha implementado essa então...)
    removePrimeiroNo(&(*prim));
  }
  liberaNos(&(*prim));//Caso recursivo: Função libera nós recebe a lista, até que o caso base seja concluído
}

/*================================>PROCEDIMENTOS ESPECÍFICOS DE LISTAS
/* -------------------------> Cria cópia
* Cria uma nova lista cujos nós têm os mesmos
* valores da lista dada. Devolve o ponteiro para
* o primeiro nó da nova lista.
*/
TipoListaSimples *copiaListas(TipoListaSimples *prim) {
  TipoListaSimples *novaLista = NULL, *listaAux = NULL;//Cria uma nova lista e um ponteiro auxiliar
  for (listaAux = prim; listaAux != NULL; listaAux = listaAux->prox) {//Condição do laço: Enquanto a lista não chegar ao seu fim
    insereInicioListaSimples (&novaLista, listaAux->chave, listaAux->valorQualquer);//Insere os valores da lista 1 no início de uma nova lista
  }
  return novaLista;//Retorna a nova lista
}

/* -------------------------> Cria cópia
* Calcula a interseção entre as duas listas
* dadas e insere tais nós numa (nova) terceira
* lista. Devolve o ponteiro para o cabeça da nova lista.
* A interseção deve considerar o campo chave.
*/
TipoListaSimples *intersecaoListas(TipoListaSimples *prim1, TipoListaSimples *prim2) {
  TipoListaSimples *novaLista = NULL, *listaAux1 = NULL, *listaAux2 = NULL;//Declaração de ponteiros
  for (listaAux1 = prim1; listaAux1 != NULL; listaAux1 = listaAux1->prox) {//Condição do laço: Enquanto a lista 1 não chegar ao seu fim
    for (listaAux2 = prim2; listaAux2 != NULL; listaAux2 = listaAux2->prox) {//Condição de laço: Enquanto a lista 2 não chegar ao seu fim
      if (listaAux1->chave == listaAux2->chave) {//Compara os campos chave da lista 1 e lista 2, caso encontrar igualdades, tal nó será inserido na nova lista
        insereInicioListaSimples (&novaLista, listaAux1->chave, listaAux2->valorQualquer);//Insere o nó no ínicio da nova lista (Mais uma vez aproveitei da função pronta, e coloquei o chave da lista 1 e o valor da lista 2 só pra ter certeza de que estava funcionando)
      }
    }
  }
  return novaLista;//Retorna a nova lista
}

/* -------------------------> Remove/Insere
* Remove último nó da segunda lista (caso ele exista).
* Insere um novo nó na última posição da primeira lista.
* O novo nó deve ter os mesmos valores do nó removido.
* A referencia do ponteiro para o primeiro nó das listas de entrada
* são primLista1 e primLista2, respectivamente.
*/
void insereRemove(TipoListaSimples **primLista1, TipoListaSimples **primLista2) {
  TipoListaSimples *listaAux = NULL;//Ponteiro auxiliar para não alterar os endereços originais da lista
  int valor = 0, chave = 0;//Variáveis declaradas
  for (listaAux = *primLista2; listaAux != NULL; listaAux = listaAux->prox) {//Condição do laço: Enquanto a lista não chegar ao fim
    if (listaAux->prox == NULL) {//Caso o último elemento for encontrado, seus campos chave e valor são armazenados
      valor = listaAux->valorQualquer;
      chave = listaAux->chave;
      break;//Se entrou no if, não é mais necessário o loop continuar a execução
    }
  }
  removeUltimoNo(&(*primLista2));//Remove o último nó
  insereFimListaSimples(&(*primLista1), chave, valor);//Insere um novo nó na ultima posição da lista 1, com os campos valor e chave do último nó da lista 2
}

/* -------------------------> Transplanta Nó.
* Desconecta o último nó da segunda lista (caso ele exista).
* Conecta tal nó na última posição da primeira lista.
* NOTE QUE A REGIÃO DE MEMÓRIA DO NÓ NÃO MUDA!
* A referencia do ponteiro para o primeiro nó das listas de entrada
* são primLista1 e primLista2, respectivamente.
*/
/*void transplantaNo(TipoListaSimples **primLista1, TipoListaSimples **primLista2) {

}*/

/* -------------------------> Conta Nó.
* Conta o número de nós de uma lista encadeada.
* Retorno número de nós
*/
int contaNo(TipoListaSimples **primLista1) {
  int contador = 0;//Variável inicializada
  TipoListaSimples *listaAux = NULL;//Ponteiro auxiliar para não alterar o endereço original da lista
  for (listaAux = *primLista1; listaAux != NULL; listaAux = listaAux->prox) {//Condição do laço:Enquanto não chegar ao fim da lista
    contador++;//Incrementa o contador
  }
  return contador;//Retorna o contador
}

/* -------------------------> Altura do Nó.
* Escreva uma função que calcule a altura de um dado nó (baseado na
*chave).
* A altura de um nó c em uma lista encadeada é a distância entre c e o
*fim da lista.
* Mais precisamente, a altura de c é o número de passos do caminho que
*leva de c até a último nó da lista.
* Retorno altura do nó
*/
int alturaNo(TipoListaSimples **primLista1, TipoChave chave) {
  int contador = 0;//Variável inicializada
  TipoListaSimples *listaAux = NULL;//Ponteiro auxiliar para não alterar o endereço original da lista
  for (listaAux = *primLista1; listaAux != NULL; listaAux = listaAux->prox) {//Condição do laço:Enquanto não chegar ao fim da lista
    if (listaAux->chave == chave) {//Caso a chave seja encontrada, entra no laço abaixo
      while (listaAux != NULL) {//Condição do laço:Enquanto for diferente do fim
        contador++;//Neste caso só incrementará no contador quando a chave for encontrada, assim contando apenas da chave até o fim (altura)
        listaAux = listaAux->prox;
      }
      break;//Quando terminar o laço while, o for não será mais útil
    }
  }
  return contador;//Retorna a altura
}


/* -------------------------> Profundidade do Nó.
* Escreva uma função que calcule a profundidade de um dado nó (baseado na
*chave).
* A profundidade de um nó c em uma lista encadeada é o número de passos do
*único caminho que vai do primeiro nó da lista até c.
*/
int profundidadeNo(TipoListaSimples **primLista1, TipoChave chave) {
  int contador = 0;//Variável inicializada
  TipoListaSimples *listaAux = NULL;//Ponteiro auxiliar para não alterar o endereço original da lista
  for (listaAux = *primLista1; listaAux != NULL; listaAux = listaAux->prox) {//Condição do laço:Enquanto não chegar ao fim da lista
    if (listaAux->chave == chave) {//Caso a chave seja encontrada, incrementa mais uma vez e encerra o laço for, pois assim terá sido contado apenas do ínicio até o nó com a chave(profundidade)
      contador++;
      break;
    }
    contador++;
  }
  return contador;//Retorna a profundidade
}
