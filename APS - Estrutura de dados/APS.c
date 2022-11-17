#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Função Bubble Sort
void bubbleSort(int vetor[], int tamanho){
	int aux, i, j;
	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
        }
      }
  }
}

//Função insertion sort
void insertionSort(int vetor[], int tamanho){
    int i, j, key;
    for (i = 1; i < tamanho; i++) {
        key = vetor[i];
        j = i - 1;
        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key;
    }
}

//Função Selection Sort
void selection_sort(int vetor[], int tamanho) { 
  int i, j, min, aux;
  for (i = 0; i < (tamanho-1); i++) 
  {
     min = i;
     for (j = (i+1); j < tamanho; j++) {
       if(vetor[j] < vetor[min]) 
         min = j;
     }
     if (i != min) {
       aux = vetor[i];
       vetor[i] = vetor[min];
       vetor[min] = aux;
     }
  }
}

//Função QuickSort
void quick_sort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}

//Principal
void main (){

  int numero,valor, tamanho = 100000, lista[100000]={};
  
  float tempo;
  time_t t_ini, t_fim;

  FILE* arqNome = fopen("dtaleat100kuni0.txt","r"); //Abre o arquivo para leituta

  //Verificação se o arquivo foi devidamente selecionado
  if(arqNome != NULL){
    
    for(int i = 0; fscanf(arqNome, "%d" ,&numero ) != EOF ; i++){
      //Colocando os dados dentro da array lista
      lista[i]=numero;


    }
  }
  
  printf("Selecione o algoritimo de organização: \n");
  printf("1. Bubble Sort;\n");
  printf("2. Insertion Sort; \n");
  printf("3. Selection sort;\n");
  printf("4. Quick Sort;\n");
  scanf("\n %d",&valor);

  switch (valor)
  {
  case 1:
    //Chamar bubble sort
    t_ini = time(NULL);
    bubbleSort(lista, tamanho);
    t_fim = time(NULL);
    tempo = difftime(t_fim,t_ini);

    for(int i = 0; i<=tamanho; i++){
      
      printf("\n %d",lista[i]);

    }
    
    printf("\nTempo (em segundos): %f",tempo);

  break;
 
  case 2:
    //Chamar insertion sort
    t_ini = time(NULL);
    insertionSort(lista, tamanho);
    t_fim = time(NULL);
    tempo = difftime(t_fim,t_ini);

    for(int i = 0; i<=tamanho; i++){
       
      printf("\n %d",lista[i]);

    } 

   printf("\nTempo (em segundos): %f",tempo);

  break;

  case 3:
    //Chamar Selection Sort
    t_ini = time(NULL);
    selection_sort(lista,tamanho);
    t_fim = time(NULL);
    tempo = difftime(t_fim,t_ini);
    
    for(int i = 0; i<=tamanho; i++){
       
      printf("\n %d",lista[i]);

    }

    printf("\nTempo (em segundos): %f",tempo); 

  break;

  case 4:
    //Chama o Quick sort
    t_ini = time(NULL);
    quick_sort(lista, 0, tamanho);
    t_fim = time(NULL);
    tempo = difftime(t_fim,t_ini);

    for(int i = 0; i<=tamanho; i++){
       
      printf("\n %d",lista[i]);

     }

   printf("\nTempo (em segundos): %f",tempo); 
   
   break;
  


    default:
    
    break;
  }
  
  fclose(arqNome);

  

  return 0;

}