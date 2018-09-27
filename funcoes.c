#include "trabpaa.h"

//========================================================================================================================
/*Funções auxiliares*/

void menu(void) {
	int op, n;
	do {
		printf("Entre com o método de ordenação desejado: \n"
			"\t1 - Bubble Sort (versão original sem melhorias)\n"
			"\t2 - Bubble Sort melhorado (verifica se o vetor já está ordenado)\n"
			"\t3 - Quick Sort (com pivô sendo o primeiro elemento da lista – partição)\n"
			"\t4 - Quick Sort (com pivô sendo o elemento central da lista – partição)\n"
			"\t5 - Insertion Sort (inserção simples ou inserção direta)\n"
			"\t6 - Shell Sort\n"
			"\t7 - Selection Sort (Seleção Direta)\n"
			"\t8 - Heap Sort\n"
			"\t9 - Merge Sort\n"
			">> ");
		scanf("%d", &op);
	} while(op < 1 || op > 9);
	
	printf("Entre com o tamanho do vetor: ");
	scanf("%d", &n);
	int vetor[n];
	criar_vetor(vetor, n);
	imprimir_vetor(vetor, n);
	
	switch(op) {
		case 1: 
			bubble_sort1(vetor, n);
			break;
		case 2:
			bubble_sort2(vetor, n);
			break;
		case 3:
			quick_sort1(vetor, 0, n);
			break;
//		case 4:
//			quick_sort2();
//			break;
//		case 5:
//			insertion_sort();
//			break;
//		case 6: 
//			shell_sort();
//			break;
//		case 7: 
//			selection_sort();
//			break;
//		case 8:
//			heap_sort();
//			break;
//		case 9:
//			merge_sort();
//			break;
		default:
			printf("ERRO");
			break;
	}
	printf("\nO vetor ordenado é: \n");
	imprimir_vetor(vetor, n);
}


void criar_vetor(int vetor[], int n) {
	int i;
	
	srand(time(NULL));
	for(i=0; i<n; i++) {
		vetor[i] = rand() % 1000 + 1;
	}
}


void imprimir_vetor(int vetor[], int n) {
	int i;
	
	for(i=0; i<n; i++) {
		printf("[%d], ", vetor[i]);
	}
	PULA;
}


//========================================================================================================================
/*Algoritmos de Ordenação*/

//1 - Bubble Sort (1) original
void bubble_sort1(int vetor[], int n) {
	int k, j, aux;
	
    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;	
            }
        }
    }
}

//2 - Bubble Sort (2) melhorado
void bubble_sort2(int vetor[], int n) {
	int k, j, aux;

    for (k = n - 1; k > 0; k--) {

        for (j = 0; j < k; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

//3 - Quick Sort (1) com pivô sendo o primeiro elemento da lista
void quick_sort1(int vetor[], int inicio, int fim) {
	int pivo, aux, i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = (int) ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (vetor[i] < pivo) i = i + 1;
      while (vetor[j] > pivo) j = j - 1;
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   if(inicio < j) quick_sort1(vetor, inicio, j);
   if(i < fim) quick_sort1(vetor, i, fim);   

}

//Quick Sort (2) com pivô sendo o elemento central da lista
void quick_sort2() {
	
}
