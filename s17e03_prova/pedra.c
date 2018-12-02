#include <stdio.h>

int main () {
	
	int n;
	int ganhador = -1;
	int melhordist = 0;
	int dist;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
        int A, B;
		scanf("%d%d", &A, &B);
		if ( A >= 10 && B >= 10) { 
    		dist = A - B;
    		dist = dist < 0 ? -dist : dist;
    		if((ganhador == -1) || (dist < melhordist)){
		        ganhador = i;
		        melhordist = dist;
    		}
		}
	}	
		
	if( ganhador != -1)
		printf("%d", ganhador);
	else
		printf("sem ganhador");
	
	return 0;
}
