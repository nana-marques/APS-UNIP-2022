#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// variavel global de registro dos movimentos.
int movimento = 0;

//Função Bubble Sort
void bubbleSort(int vetor[], int tamanho){
	int aux, i, j;
	for(j=tamanho-1; j>=1; j--){
		for(i=0; i<j; i++){
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
                    vetor[i]=vetor[i+1];
                    vetor[i+1]=aux;
                    movimento++;
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
            movimento++;
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
       movimento++;
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
            movimento++;
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

  int numero, valor, tamanho = 100, lista[100]={};
  
  // variáveis para armazenar tempo
  float beginBubble, endBubble, tempoBubble;
  float beginSelection, endSelection, tempoSelection;
  float beginInsertion, endInsertion, tempoInsertion;
  float beginQuick, endQuick, tempoQuick;

  FILE* arqNome = fopen("dados.txt","r"); //Abre o arquivo para leituta

  //Verificação se o arquivo foi devidamente selecionado
  if(arqNome != NULL){
    
    for(int i = 0; fscanf(arqNome, "%d" ,&numero ) != EOF ; i++){
      //Colocando os dados dentro da array lista
      lista[i]=numero;


    }
  }
  
  LOOP:{
  printf("Selecione o algoritimo de organização: \n");
  printf("1. Bubble Sort;\n");
  printf("2. Insertion Sort; \n");
  printf("3. Selection sort;\n");
  printf("4. Quick Sort;\n");
  printf("Número do algoritmo: ");
  scanf("\n %d",&valor);
  }

  switch (valor)
  {
  case 1:
    //Chamar bubble sort e iniciar timer
    clock_t beginBubble = clock();
    bubbleSort(lista, tamanho);
    
    printf("[");
    for(int i = 0; i<=tamanho; i++){
      
      printf("%d, ", lista[i]);
    }
    printf("]\n");
    
    clock_t endBubble = clock();
    double tempoBubble = (double)(endBubble - beginBubble) * 1000.0 / CLOCKS_PER_SEC;
    
    printf("\nNúmero de movimentações: %i", movimento);
    printf("\nTempo de execução (em segundos): %f", tempoBubble);

  break;
 
  case 2:
    //Chamar insertion sort
    clock_t beginInsertion = clock();
    insertionSort(lista, tamanho);

    printf("[");
    for(int i = 0; i<=tamanho; i++){
       
      printf("%d, ",lista[i]);

    } 
    printf("]\n");

    clock_t endInsertion = clock();
    double tempoInsertion = (double)(endInsertion - beginInsertion) * 1000.0 / CLOCKS_PER_SEC;

    printf("\nNúmero de movimentações: %i", movimento);
    printf("\nTempo (em segundos): %f", tempoInsertion);

  break;

  case 3:
    //Chamar Selection Sort
    clock_t beginSelection = clock();
    selection_sort(lista, tamanho);
    
    printf("[");
    for(int i = 0; i<=tamanho; i++){
       
      printf("%d, ",lista[i]);

    }
    printf("]\n");

    clock_t endSelection = clock();
    double tempoSelection = (double)(endSelection - beginSelection) * 1000.0 / CLOCKS_PER_SEC;

    printf("\nNúmero de movimentações: %i", movimento);
    printf("\nTempo (em segundos): %f", tempoSelection); 

  break;

  case 4:
    //Chama o Quick sort
    clock_t beginQuick = clock();
    quick_sort(lista, 0, tamanho);

    printf("[");
    for(int i = 0; i<=tamanho; i++){

      printf("%d, ",lista[i]);

    }
    printf("]\n");

    clock_t endQuick = clock();
    double tempoQuick = (double)(endQuick - beginQuick) * 1000.0 / CLOCKS_PER_SEC;

    printf("\nNúmero de movimentações: %i", movimento);
    printf("\nTempo (em segundos): %f", tempoQuick);
   
   break;
  
    default:
        printf ("\nOpção inválida! Escolha as opções listadas (apenas o número).\n\n");
        goto LOOP;
    break;
  }
  
  fclose(arqNome);
}