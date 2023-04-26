#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Introduzindo os algoritimos de organização

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

void main(){
    // variaveis para guiar o código com base nas escolhas do usuário e controle de operações
    int algoritimo, qtd_arq, numero, i;

    //Recebe o diretório do arquivo e o nome do arquivo
    char diretorio[150], nome_arquivo[20], caminho_completo[200];

    // Monta um vetor inicial para futuramente remodularmos o tamanho do memso 
    int *vetor = calloc (1,sizeof(int));
    
    //Cria um ponteiro para os arquivos, onde será modulado no decorrer do codigo
    FILE *arquivo;
    
    //Montando um menu simples para a navegação do codigo
    printf("\n-------- Analise de Algoritimo--------\n");

    //Seleção de algoritimo
    printf("Selecione o algoritimo de organizacao: \n");
    printf("1. Bubble Sort. \n");
    printf("2. Insertion Sort. \n");
    printf("3. Selection sort. \n");
    printf("4. Quick Sort. \n");
    scanf("\n %d", & algoritimo);

    //quantidade de caracteres que o usuário deseja ultilizar
    printf("\nEscreva a quantidade de caracteresde (no intervalo de 10 a 100.000) que deseja trabalhar \n");
    printf("OBSERVACAO: A quantidade de caracteres e o arquivo selecionado devem ser equivalentes.\n");
    scanf("\n %d", & qtd_arq);

    //altera o tamanho do vetor dinamicamnente
    vetor = realloc(vetor, qtd_arq * sizeof(int));

    //Diretorio dos arquivos
    printf("\nCopie e cole o caminho (diretorio) do arquivo por completo (com o nome + exten txt) \n");
    scanf("%s", diretorio);
   


    //Abre arquivo
    fgets(diretorio, qtd_arq, stdin);
    diretorio[strcspn(diretorio, "\n")] = '\0'; // Remove o caractere de nova linha do final da string

    // Solicita ao usuário o nome do arquivo
    printf("Digite o nome do arquivo: ");
    scanf("%s", nome_arquivo);

    // Concatena o caminho completo com o nome do arquivo
    sprintf(caminho_completo, "\"%s/%s\"", diretorio, nome_arquivo);

    // Abre o arquivo
    arquivo = fopen(caminho_completo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    // Lê o conteúdo do arquivo e armazena em um vetor
    int i = 0;
    while (fscanf(arquivo, "%d", &vetor[i]) != EOF) {
        i++;
    }

    // Imprime o vetor TESTE
    printf("Valores lidos do arquivo:\n");
    for (int j = 0; j < i; j++) {
        printf("%d ", vetor[j]);
    }
    printf("\n");

    // Fecha o arquivo
    fclose(arquivo);

    //CRIAR UM SWITCH PARA REDIRECIONAR AS INFORMAÇÕES PARA OS ALGORRITIMOS
    
    //Recriar a chamda da função de organização a partir deste ponto

}
