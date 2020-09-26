#define TAM 15
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//SEQUENCIA CIURA
int ciura[14] = {1, 4, 10, 23, 57, 132, 301, 701, 1577, 3548, 7983, 17961, 40412, 90927};

//ARRAYS DE TESTE DIVERSOS
int ar1[TAM] = {5,56,8,321,8,2,5,1,0,3,5,1,8,3,6};
int ar2[TAM] = {8,6,0,21,3,8,21,348,32,1,8,31,5,5,9};
int ar3[TAM] = {6,8,2,8,1,23,8,2321,832,18,321,8,7,215,555};
int ar4[TAM] = {85, 84, 83,82,81,80,79,78,77,76,75,74,73,72,71};

//LISTAS DO EXERCICIO 1
int arrayTeste[9] = {54, 26, 93, 17, 77, 31, 44, 55, 20};
int arrayA1[14] = {733, 77, 611, 51, 496, 990, 61, 175, 127, 794, 76, 197, 141, 863};
int arrayB1[20] = {872, 424, 729, 573, 877, 696, 321, 758, 949, 217, 767, 238, 562, 175, 999, 12, 380, 406, 225, 995};

//LISTAS DO EXERCICIO 2 (vazio para geracao aleatoria)
  int vazio100[100];
  int vazio1000[1000];
  int vazio10000[10000];
  int vazio100000[100000];


void printArr(int arr[], int tam) {
  int i = 0;
  for(i = 0; i < tam; i++){
    if( i < tam-1){
      printf("%d, ", arr[i]);
    } else {
      printf("%d", arr[i]);
    }
  }
}

void arrAleatorio(int arr[], int tam) {
  int i;
  srand(time(0));
  for(i = 0; i < tam; i++){
    arr[i] = rand();
  }
}

// Função para checar se o array está ordenado retirada do arquivo de funcoes auxiliares
// dado pelo profesor
//--------------------------------------------------------------
void check_correctness (int C[], int tam) {
//--------------------------------------------------------------
  for (int i=0; i<tam-1; i++) {
      if (C[i]>C[i+1]) {
          printf ("\n***** INCORRECT ORDERING *****");
          return;
      }
  }
  printf("\n***** CORRECT ORDERING *****");
}
// Função para cópia de arrays retirada do arquivo de funcoes auxiliares
// dado pelo profesor

void copy_array (int* array_origem, int* array_destino, int size) {
	for (int i=0; i< size; i++) array_destino [i] = array_origem [i];
}

//gera um indice aleatorio com o tamanho recebido e o indice de inicio do subarray
int random_index(int size, int start){
  srand(time(0));
  return ((int)(rand() % size) + start);
}