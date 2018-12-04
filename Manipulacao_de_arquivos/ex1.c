#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1: Implemente uma função “iguais” que compara duas pessoas e retorna se são iguais - ou
seja, seus campos possuem o mesmo valor. Retorne verdadeiro (ou 1) se iguais, e falso (ou 0)
se diferentes. (Lembre-se da função strcmp da string.h que recebe duas strings e retorna um
número menor que 0 se string1 menor que string2; igual a 0 se string1 igual a string2; e maior
que 0 se string1 maior que string2)*/

typedef struct pessoa {
  char nome[64];
  int idade;
}Pessoa;

int iguais(Pessoa *v1, Pessoa *v2);

int main(int argc, char const *argv[]) {
  FILE *pessoas1, *pessoas2, *output;
  Pessoa *v1 = NULL, *v2 = NULL;
  pessoas1 = fopen("pessoas1.dat", "r");
  pessoas2 = fopen("pessoas2.dat", "r");
  if (pessoas1 == NULL || pessoas2 == NULL) {
    printf("\nFalha ao abrir os arquivos!\n");
  }
  else {
    int tam1 = -1, tam2 = -1, i = 0, j = 0, idade = 0, res = 0;
    char nome[64];
    while (!feof(pessoas1)) {
      fscanf(pessoas1, "%s %d", nome, &idade);
      tam1++;
    }
    while (!feof(pessoas2)) {
      fscanf(pessoas2, "%s %d", nome, &idade);
      tam2++;
    }
    fclose(pessoas1);
    fclose(pessoas2);
    pessoas1 = fopen("pessoas1.dat", "r");
    pessoas2 = fopen("pessoas2.dat", "r");
    if (pessoas1 == NULL || pessoas2 == NULL) {
      printf("\nFalha ao abrir os arquivos!\n");
    }
    v1 = (Pessoa*)malloc(sizeof(Pessoa) * tam1);
    v2 = (Pessoa*)malloc(sizeof(Pessoa) * tam2);
    for (i = 0;  i < tam1; i++) {
      fscanf(pessoas1, "%s %d", nome, &idade);
      strcpy(v1[i].nome, nome);
      v1[i].idade = idade;
    }
    for (j = 0;  j < tam2; j++) {
      fscanf(pessoas2, "%s %d", nome, &idade);
      strcpy(v2[j].nome, nome);
      v2[j].idade = idade;
      j++;
    }
    output = fopen("output.dat", "w");
    for (i = 0; i < tam1; i++) {
      for (j = 0; j < tam2; j++) {
        res =iguais(&v1[i], &v2[j]);
        if (res == 1) {
          printf("\nAs pessoas cujos nomes são %s e %s possuem os mesmos dados.\n\n", v1[i].nome, v2[j].nome);
          fprintf(output, "\nAs pessoas cujos nomes são %s e %s possuem os mesmos dados.\n\n", v1[i].nome, v2[j].nome);
        }
        else {
          printf("\nAs pessoas cujos nomes são %s e %s não possuem os mesmos dados.\n\n", v1[i].nome, v2[j].nome);
          fprintf(output, "\nAs pessoas cujos nomes são %s e %s não possuem os mesmos dados.\n\n", v1[i].nome, v2[j].nome);
        }
      }
    }
    fclose(pessoas1);
    fclose(pessoas2);
    fclose(output);
    free(v1);
    v1 = NULL;
    free(v2);
    v2 = NULL;
  }
  return 0;
}

int iguais(Pessoa *v1, Pessoa *v2) {
  if (v1->idade == v2->idade && strcmp(v1->nome, v2->nome) == 0) return 1;
  else return 0;
}
