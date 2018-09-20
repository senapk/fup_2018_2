#include <stdio.h>

/*
//retorne a posicao que encontrar ou -1
int find(int vet[], int size, int value, int inicio){

}

int contar(int vet[], int size, int value){

}
*/

#define SWAP(a, b) do{int SWAP = a; a = b; b = SWAP;}while(0)

//retorna a posicao do menor elemento entre inicio e fim
int find_menor(int vet[], int size, int inicio){
	int i_menor = inicio;
	for(int j = inicio + 1; j < size; j++)
		if(vet[j] < vet[i_menor])
			i_menor = j;
	return i_menor;
}

void swap(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

void selection(int vet[], int size){
	for (int i = 0; i < size; i++){
		int i_menor = find_menor(vet, size, i);
		SWAP(vet[i_menor], vet[i]);
	}
}

void print_vet(int vet[], int size){
	printf("[");
	if(size > 0)
		printf("%d", vet[0]);
	for(int i = 1; i < size; i++)
		printf(", %d", vet[i]);
	printf("]\n");
}

int main(){

	//hardcoded
	int vet[] = {1, 3, 4, 1, 4, 5, 9, 19, 100, 150, 7, 8};
	int size = sizeof(vet) / sizeof(int);
	selection(vet, size);
	print_vet(vet, size);
	return 0;
}

	
	
	
	
	
	
	
	
