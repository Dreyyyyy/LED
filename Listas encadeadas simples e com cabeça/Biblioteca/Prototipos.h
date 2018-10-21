/*
* Faça uma biblioteca para as definições
* abaixo especificadas.
*/
typedef int TipoChave;
typedef int TipoValor;
struct TipoListaSimples {
TipoChave chave;
TipoValor valorQualquer;
struct TipoListaSimples *prox;
};typedef struct TipoListaSimples TipoListaSimples;

TipoListaSimples *insereInicioListaSimples(TipoListaSimples **prim, TipoChave chave, TipoValor valor);

void atualizaValor(TipoListaSimples *prim, TipoValor novoValor);

void removePrimeiroNo(TipoListaSimples **prim);

TipoListaSimples *pesquisaNo(TipoListaSimples *prim, TipoChave chave);

TipoListaSimples * insereFimListaSimples(TipoListaSimples **prim, TipoChave chave);

void removeUltimoNo(TipoListaSimples **prim);

void removeNo(TipoListaSimples **prim, TipoChave chave);

void liberaNos(TipoListaSimples **prim);
