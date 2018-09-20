/*
A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J,   Q, K
1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13

int carta;

Digite a 1a carta: 10
Digite a 2a carta: 13
a 2a carta eh maior
*/
#include <stdio.h>

int main(){

	//hardcoded
	int vet[] = {1, 3, 4, 1, 4, 5, 9, 19, 100, 150, 7, 8};
	int n = sizeof(vet) / sizeof(int);

	for (int i = 0; i < n; i++){
		int i_menor = i;
		for(int j = i + 1; j < n; j++)
			if(vet[j] < vet[i_menor])
				i_menor = j;
		int c = vet[i_menor];
		vet[i_menor] = vet[i];
		vet[i] = c;
	}
	//[1, 2,..., 5]
	printf("[");
	if(n > 0)
		printf("%d", vet[0]);
	for(int i = 1; i < n; i++)
		printf(", %d", vet[i]);
	printf("]\n");
	return 0;
}

	
	
	
	
	
	
	
	
