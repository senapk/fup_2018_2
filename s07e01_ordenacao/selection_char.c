#include <stdio.h>

#define SWAP(a, b, tipo) do{tipo SWAP = a; a = b; b = SWAP;}while(0)

//retorna a posicao do menor elemento entre inicio e fim
int find_menor(char vet[], int size, int inicio){
	int i_menor = inicio;
	for(int j = inicio + 1; j < size; j++)
		if(vet[j] < vet[i_menor])
			i_menor = j;
	return i_menor;
}

void selection(char vet[], int size){
	for (int i = 0; i < size; i++){
		int i_menor = find_menor(vet, size, i);
		SWAP(vet[i_menor], vet[i], char);
	}
}

void print_vet(char vet[], int size){
	printf("[");
	if(size > 0)
		printf("%c", vet[0]);
	for(int i = 1; i < size; i++)
		printf("%c", vet[i]);
	printf("]\n");
}

int main(){

	//hardcoded
	//int vet[] = {1, 3, 4, 1, 4, 5, 9, 19, 100, 150, 7, 8};
	//char vet[] = {'d', 'a', 'v', 'i', 'd', ' ', 's', 'e'};
	char vet[] = "davidsenaoliveira";
	int size = sizeof(vet) / sizeof(char);
	selection(vet, size - 1);
	//print_vet(vet, size);
	printf("%s", vet);
	return 0;
}

	
	
	
	
	
	
	
	
