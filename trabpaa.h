#ifndef  TRABPAA_H
#define  TRABPAA_H

    #include <stdio.h>
    #include <stdlib.h>
	#include <locale.h>
	#include <time.h>
	
	#define PULA printf("\n\n")
	
    void menu(void);
    void bubble_sort1(int vetor[], int n);
	void bubble_sort2(int vetor[], int n);
	void quick_sort1(int vetor[], int inicio, int fim);
	void quick_sort2();
	void insertion_sort();
	void shell_sort();
	void selection_sort();
	void heap_sort();
	void merge_sort();
	void criar_vetor(int vetor[], int n);
	void imprimir_vetor(int vetor[], int n);

#endif  /*TRABPAA_H*/
