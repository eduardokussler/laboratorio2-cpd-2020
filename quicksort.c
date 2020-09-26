#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include <string.h>


void chamaAlgoritmos(char* nome, char* algo);
double hoarealeatorio(FILE** arq, FILE** saida, int tam);
double hoaremediana(FILE** arq, FILE** saida, int tam);
double lomutoaleatorio(FILE** arq, FILE** saida, int tam);
double lomutomediana(FILE** arq, FILE** saida, int tam);

// como argumento arquivo de entrada
int main(int argc, char *argv[]){
  chamaAlgoritmos(argv[1], "ha");
  chamaAlgoritmos(argv[1], "hm");
  chamaAlgoritmos(argv[1], "la");
  chamaAlgoritmos(argv[1], "lm");
  return 0;
}

//nome:nome do arquivo a ser lido
//algo:algoritmo a ser usado 
// ha- particionamento de hoare aleatorio
// hm- particionamento de hoare mediana
// la - particionamento de lomuto aleatorio
// lm - particionamento de lomuto mediana
void chamaAlgoritmos(char* nome, char* algo){
  FILE* arq = fopen(nome, "r");
  FILE* saida;
  FILE* stats;
  // tempo de execução em milisegundos
  double tempo;
  swaps = 0;
  recurisiveCalls = 0;
  if(!arq){
    printf("\nERRO NA ABERTURA\n");
    return ;
  }
  // numero de arrays do arquivo
  int n;
  fscanf(arq, "%d", &n);
  if(strcmp(algo, "ha") == 0){
    saida = fopen("saida-aleatorio-hoare.txt", "w+");
    fprintf(saida, "%d\n", n);
    stats = fopen("stats-aleatorio-hoare.txt", "w+");
  } else if(strcmp(algo, "hm") == 0){
    saida = fopen("saida-mediana-hoare.txt", "w+");
    fprintf(saida, "%d\n", n);
    stats = fopen("stats-mediana-hoare.txt", "w+");
  } else if(strcmp(algo, "la") == 0){
    saida = fopen("saida-aleatorio-lomuto.txt", "w+");
    stats = fopen("stats-aleatorio-lomuto.txt", "w+");
    fprintf(saida, "%d\n", n);
  } else if(strcmp(algo, "lm") == 0){
    saida = fopen("saida-mediana-lomuto.txt", "w+");
    stats = fopen("stats-mediana-lomuto.txt", "w+");
    fprintf(saida, "%d\n", n);
  }
  

  int i;
  //tamanho de cada array
  int tam;
  for(i = 0; i < n; i++){
    fscanf(arq, "%d", &tam);

    //hoare aleatório
    if(strcmp(algo, "ha") == 0){
      swaps = 0;
      recurisiveCalls = 0;
      fflush(saida);
      fprintf(saida, "%d", tam);
      fflush(saida);
      tempo = hoarealeatorio(&arq, &saida, tam);
      fprintf(stats,"%d - swaps: %d - tempo: %10.4f ms - chamadas recursivas: %d\n", tam, swaps, tempo, recurisiveCalls);

    //hoare mediana
    } else if(strcmp(algo, "hm") == 0){
      swaps = 0;
      recurisiveCalls = 0;
      fflush(saida);
      fprintf(saida, "%d", tam);
      fflush(saida);
      tempo = hoaremediana(&arq, &saida, tam);
      fprintf(stats,"%d - swaps: %d - tempo: %10.4f ms - chamadas recursivas: %d\n", tam, swaps,tempo, recurisiveCalls);


    //lomuto aleatorio
    } else if(strcmp(algo, "la") == 0){
      swaps = 0;
      recurisiveCalls = 0;
      fflush(saida);
      fprintf(saida, "%d", tam);
      fflush(saida);
      tempo = lomutoaleatorio(&arq, &saida, tam);
      fprintf(stats,"%d - swaps: %d - tempo: %10.4f ms - chamadas recursivas: %d\n", tam, swaps,tempo, recurisiveCalls);

    //lomuto mediana
    } else if(strcmp(algo, "lm") == 0){
      swaps = 0;
      recurisiveCalls = 0;
      fflush(saida);
      fprintf(saida, "%d", tam);
      fflush(saida);
      tempo = lomutomediana(&arq, &saida, tam);
      fprintf(stats,"%d - swaps: %d - tempo: %10.4f ms - chamadas recursivas: %d\n", tam, swaps,tempo, recurisiveCalls);

    }
  } 

  // fprintf(stats, "Número de swaps: %d\n", swaps);
  // fprintf(stats, "Número de chamadas recursivas: %d\n", recurisiveCalls);
  // fprintf(stats, "Tempo de execução: %10.4Lf ms", tempo);
  fclose(arq);
  fclose(saida);
}


double hoarealeatorio(FILE** arq, FILE** saida, int tam) {
  clock_t start, end;
  double time_elapsed_ms; 
  start = clock();
  int* arr = (int*) malloc(sizeof(int)*tam);
  int i;
  for(i = 0; i < tam; i++){
    fscanf(*arq, "%d", &(arr[i]));
  }
  quicksort_aleatorio_hoare(arr, 0, tam-1);
  for(i = 0; i < tam-1; i++){
    fprintf(*saida, " %d", arr[i]);
    fflush(*saida);
  }
  fprintf(*saida, " %d\n", arr[tam-1]);
  fflush(*saida);
  end = clock();
  return time_elapsed_ms = 1000.0 * (end-start) / (double) CLOCKS_PER_SEC;
}


double hoaremediana(FILE** arq, FILE** saida, int tam) {
  clock_t start, end;
  double time_elapsed_ms; 
  start = clock();
  int* arr = (int*) malloc(sizeof(int)*tam);
  int i;
  for(i = 0; i < tam; i++){
    fscanf(*arq, "%d", &(arr[i]));
  }
  quicksort_mediana_hoare(arr, 0, tam-1);
  for(i = 0; i < tam-1; i++){
    fprintf(*saida, " %d", arr[i]);
    fflush(*saida);
  }
  fprintf(*saida, " %d\n", arr[tam-1]);
  fflush(*saida);
  end = clock();
  return time_elapsed_ms = 1000.0 * (end-start) / (double) CLOCKS_PER_SEC;
}

double lomutoaleatorio(FILE** arq, FILE** saida, int tam) {
  clock_t start, end;
  double time_elapsed_ms; 
  start = clock();
  int* arr = (int*) malloc(sizeof(int)*tam);
  int i;
  for(i = 0; i < tam; i++){
    fscanf(*arq, "%d", &(arr[i]));
  }
  quicksort_aleatorio_lomuto(arr, 0, tam-1);
  for(i = 0; i < tam-1; i++){
    fprintf(*saida, " %d", arr[i]);
    fflush(*saida);
  }
  fprintf(*saida, " %d\n", arr[tam-1]);
  fflush(*saida);
  end = clock();
  return time_elapsed_ms = 1000.0 * (end-start) / (double)CLOCKS_PER_SEC;
}

double lomutomediana(FILE** arq, FILE** saida, int tam) {
  clock_t start, end;
  double time_elapsed_ms; 
  start = clock();
  int* arr = (int*) malloc(sizeof(int)*tam);
  int i;
  for(i = 0; i < tam; i++){
    fscanf(*arq, "%d", &(arr[i]));
  }
  quicksort_mediana_lomuto(arr, 0, tam-1);
  for(i = 0; i < tam-1; i++){
    fprintf(*saida, " %d", arr[i]);
    fflush(*saida);
  }
  fprintf(*saida, " %d\n", arr[tam-1]);
  fflush(*saida);
  end = clock();
  return time_elapsed_ms = 1000.0 * (end-start) / (double)CLOCKS_PER_SEC;
}