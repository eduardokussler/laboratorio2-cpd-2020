#include <stdlib.h>
#include <stdio.h>
#include "arrays.h"


int particione_hoare_mediana(int arr[], int inicio, int fim);
int particione_hoare_aleatorio(int arr[], int inicio, int fim);
int particione_lomuto_mediana(int arr[], int inicio, int fim);
int particione_lomuto_aleatorio(int arr[], int inicio, int fim);

void quicksort_mediana_hoare(int arr[], int inicio, int fim);
void quicksort_aleatorio_hoare(int arr[], int inicio, int fim);
void quicksort_aleatorio_lomuto(int arr[], int inicio, int fim);
void quicksort_mediana_lomuto(int arr[], int inicio, int fim);

//Conta o total de swaps para cada algoritmo
int swaps;
//Conta o total de chamadas recursivas de cada algoritmo
int recurisiveCalls;

void quicksort_aleatorio_hoare(int arr[], int inicio, int fim){
  int tam = fim - inicio;
  int key;
  if(fim > inicio){
    key = particione_hoare_aleatorio(arr, inicio, fim);
    quicksort_aleatorio_hoare(arr, inicio, key-1);
    recurisiveCalls++;
    quicksort_aleatorio_hoare(arr, key+1, fim);
    recurisiveCalls++;
  }
}

void quicksort_mediana_hoare(int arr[], int inicio, int fim){
  int tam = fim - inicio;
  int key;
  if(fim > inicio){
    key = particione_hoare_mediana(arr, inicio, fim);
    quicksort_mediana_hoare(arr, inicio, key-1);
    recurisiveCalls++;
    quicksort_mediana_hoare(arr, key+1, fim);
    recurisiveCalls++;
  }
}

void quicksort_aleatorio_lomuto(int arr[], int inicio, int fim){
  int tam = fim - inicio;
  int key;
  if(fim > inicio){
    key = particione_lomuto_aleatorio(arr, inicio, fim);
    quicksort_aleatorio_lomuto(arr, inicio, key-1);
    recurisiveCalls++;
    quicksort_aleatorio_lomuto(arr, key+1, fim);
    recurisiveCalls++;
  }
}

void quicksort_mediana_lomuto(int arr[], int inicio, int fim){
  int key;
  if(fim > inicio){
    key = particione_lomuto_mediana(arr, inicio, fim);
    quicksort_mediana_lomuto(arr, inicio, key-1);
    recurisiveCalls++;
    quicksort_mediana_lomuto(arr, key+1, fim);
    recurisiveCalls++;
  }
}

int particione_hoare_mediana(int arr[], int inicio, int fim){
  int tam = fim - inicio;
  int key_index = (int)(tam/2);
  //pegando a mediana entre os extremos do array e a posição central
  if(arr[key_index] < arr[fim] && arr[key_index] < arr[fim]){
    key_index = arr[fim]>arr[inicio]?inicio:fim;
  }else if(arr[key_index] > arr[fim] && arr[key_index] > arr[inicio]){
    key_index = arr[fim]>arr[inicio]?fim:inicio;
  }
  //Trocando a primeira posição com o elemento pivô
  int temp = arr[inicio];
  swaps++;
  int key = arr[key_index];
  arr[inicio] = key;
  arr[key_index] = temp;

  int esq = 1;
  while(inicio < fim){
    if(esq){
      if(key >= arr[fim]){
        swaps++;
        temp = arr[inicio];
        arr[inicio] = arr[fim];
        arr[fim] = temp;
        inicio++;
        esq = 0;
      }else {
        fim--;
      }
    }else if(key < arr[inicio]) {
      temp = arr[fim];
      arr[fim] = arr[inicio];
      arr[inicio] = temp;
      swaps++;
      fim--;
      esq = 1;
    }else {
      inicio++;
    }
    
  }
    arr[inicio] = key;
    key_index = inicio;
    return key_index;
}

int particione_hoare_aleatorio(int arr[], int inicio, int fim){
  int tam = fim - inicio;
  // gerando um index aleatorio
  int key_index = random_index(tam, inicio);
  //trocando a primeira posição com o valor aleatório
  int temp = arr[key_index];
  swaps++;
  arr[key_index] = arr[inicio];
  arr[inicio] = temp;
  int key = arr[inicio];


  //particionamento de hoare
  int esq = 1;
  while(inicio < fim){
    if(esq){
      if(key >= arr[fim]){
        swaps++;
        temp = arr[inicio];
        arr[inicio] = arr[fim];
        arr[fim] = temp;
        inicio++;
        esq = 0;
      }else {
        fim--;
      }
    }else if(key < arr[inicio]) {
      temp = arr[fim];
      swaps++;
      arr[fim] = arr[inicio];
      arr[inicio] = temp;
      fim--;
      esq = 1;
    }else {
      inicio++;
    }
    
  }
    arr[inicio] = key;
    key_index = inicio;
    return key_index;
}

int particione_lomuto_mediana(int arr[], int inicio, int fim){
  int tam = fim - inicio;
  int key_index = (int)(tam/2);
  //pegando a mediana entre os extremos do array e a posição central
  if(arr[key_index] < arr[fim] && arr[key_index] < arr[fim]){
    key_index = arr[fim]>arr[inicio]?inicio:fim;
  }else if(arr[key_index] > arr[fim] && arr[key_index] > arr[inicio]){
    key_index = arr[fim]>arr[inicio]?fim:inicio;
  }
  //Trocando a ultima posição com o elemento pivô
  swaps++;
  int temp = arr[fim];
  int key = arr[key_index];
  arr[fim] = key;
  arr[key_index] = temp;

  // Particionamento
  int i = inicio - 1;
  int j;
  for(j = inicio; j < fim; j++){
    if(arr[j] <= key){
      i++;
      swaps++;
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  temp = arr[i+1];
  swaps++;
  //fim é onde a chave está armazenada
  arr[i+1] = arr[fim];
  arr[fim] = temp;
  return i+1;
}

int particione_lomuto_aleatorio(int arr[], int inicio, int fim){
  int tam = fim - inicio;
  // gerando um index aleatorio
  int key_index = random_index(tam, inicio);
  //trocando a primeira posição com o valor aleatório
  int temp = arr[key_index];
  arr[key_index] = arr[fim];
  arr[fim] = temp;
  int key = arr[fim];
  swaps++;

  // Particionamento
  int i = inicio - 1;
  int j;
  for(j = inicio; j < fim; j++){
    if(arr[j] <= key){
      i++;
      temp = arr[i];
      swaps++;
      arr[i] = arr[j];
      arr[j] = temp;
    }
  }
  swaps++;
  temp = arr[i+1];
  //fim é onde a chave está armazenada
  arr[i+1] = arr[fim];
  arr[fim] = temp;
  return i+1;
}

