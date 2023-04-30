#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int movimento = 0; // Variavel global de registro dos movimentos.
int trocas = 0, comparacoes = 0; // Variáveis de registro das trocas e comparações

//Função Bubble Sort
void bubbleSort(int vetor[], int tamanho){
	int aux, i, j;
	for(j=tamanho-1; j>=1; j--){

		for(i=0; i<j; i++){
        comparacoes++;

			if(vetor[i]>vetor[i+1]){
				trocas++;
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
        comparacoes++;

        while (j >= 0 && vetor[j] > key) {
            trocas++;
            vetor[j + 1] = vetor[j];
            j = j - 1;
            movimento++;
        }
        trocas++;
        vetor[j + 1] = key;
    }
}

//Função Selection Sort
void selection_sort(int vetor[], int tamanho) { 
  int i, j, min, aux;
  for (i = 0; i < (tamanho-1); i++) {
    min = i;
     
    for (j = (i+1); j < tamanho; j++) {
      comparacoes++;
      
      if(vetor[j] < vetor[min]){
        min = j;
      }
     }
     
     trocas+=3;
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
    trocas+=3;
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
            comparacoes++;
            trocas++;
        }

        while(a[j] > x && j > left) {
            j--;
            comparacoes++;
            trocas++;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            movimento+=3;
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

  int numero, valor, tamanho = 50, lista[50]={}; //Declaração dos valores a serem usados (tamanhos)
  
  // Variáveis para armazenar tempo
  float beginBubble, endBubble, tempoBubble;
  float beginSelection, endSelection, tempoSelection;
  float beginInsertion, endInsertion, tempoInsertion;
  float beginQuick, endQuick, tempoQuick;

  FILE* arqNome = fopen("dtconcv50dup9.txt","r"); //Abre o arquivo para leituta

  //Verificação se o arquivo foi devidamente selecionado
  if(arqNome != NULL){
    
    for(int i = 0; fscanf(arqNome, "%d" ,&numero ) != EOF ; i++){
      //Colocando os dados dentro da array lista
      lista[i]=numero;


    }
  }
  
  LOOP:{ // Usado para reiniciar o menu
  printf("Selecione o algoritimo de organização: \n");
  printf("1. Bubble Sort;\n");
  printf("2. Insertion Sort; \n");
  printf("3. Selection sort;\n");
  printf("4. Quick Sort;\n");
  printf("Número do algoritmo: ");
  scanf("\n %d",&valor); //leitura do input
  }

  switch (valor) // Switch que trata qual função será chamada
  {
  case 1:
    //Chama Bubble Sort e inicia timer
    clock_t beginBubble = clock();
    bubbleSort(lista, tamanho);
    
    printf("["); //Print do array resolvido
    for(int i = 0; i<tamanho; i++){
      
      printf("%d, ", lista[i]);
    }
    printf("]\n");
    
    clock_t endBubble = clock();
    double tempoBubble = (double)(endBubble - beginBubble) * 1000.0 / CLOCKS_PER_SEC; // Contagem do tempo
    

    printf("\nNúmero de comparacoes: %i", comparacoes);
    printf("\nNúmero de trocas de posição: %i", trocas);
    printf("\nTempo de execução (em segundos): %f", tempoBubble);

  break;
 
  case 2:
    //Chama Insertion Sort e inicia timer
    clock_t beginInsertion = clock();
    insertionSort(lista, tamanho);

    printf("["); //Print do array resolvido
    for(int i = 0; i<tamanho; i++){
       
      printf("%d, ",lista[i]);

    } 
    printf("]\n");

    clock_t endInsertion = clock();
    double tempoInsertion = (double)(endInsertion - beginInsertion) * 1000.0 / CLOCKS_PER_SEC; // Contagem do tempo

    printf("\nNúmero de comparacoes: %i", comparacoes);
    printf("\nNúmero de trocas de posição: %i", trocas);
    printf("\nTempo (em segundos): %f", tempoInsertion);

  break;

  case 3:
    //Chama Selection Sort e inicia o timer
    clock_t beginSelection = clock();
    selection_sort(lista, tamanho);
    
    printf("["); //Print do array resolvido
    for(int i = 0; i<tamanho; i++){
       
      printf("%d, ",lista[i]);

    }
    printf("]\n");

    clock_t endSelection = clock();
    double tempoSelection = (double)(endSelection - beginSelection) * 1000.0 / CLOCKS_PER_SEC; // Contagem do tempo
   
    printf("\nNúmero de comparacoes: %i", comparacoes);
    printf("\nNúmero de trocas de posição: %i", trocas);
    printf("\nTempo (em segundos): %f", tempoSelection); 

  break;

  case 4:
    //Chama o Quick Sort e inicia o timer
    clock_t beginQuick = clock();
    quick_sort(lista, 0, tamanho);

    printf("["); //Print do array resolvido
    for(int i = 0; i<tamanho; i++){

      printf("%d, ",lista[i]);

    }
    printf("]\n");

    clock_t endQuick = clock();
    double tempoQuick = (double)(endQuick - beginQuick) * 1000.0 / CLOCKS_PER_SEC; // Contagem do tempo
 
    printf("\nNúmero de comparacoes: %i", comparacoes);
    printf("\nNúmero de trocas de posição: %i", trocas);
    printf("\nTempo (em segundos): %f", tempoQuick);
   
   break;
  
    default: // Caso usuário escolha um número diferente de 1, 2, 3 ou 4
        printf ("\nOpção inválida! Escolha as opções listadas (apenas o número).\n\n");
        goto LOOP;
    break;
  }
  
  //Fecha o arquivo utilizado
  fclose(arqNome);
}
