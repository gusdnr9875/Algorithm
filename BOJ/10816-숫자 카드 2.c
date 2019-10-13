#include <stdio.h>
#include <stdlib.h>
#include<malloc.h>

int n = 0, m = 0,k=0;


int main() {

	int *pArr = (int*)calloc(10000001, sizeof(int)); 
	int *pArr2 = (int*)calloc(10000001, sizeof(int));

	int *pMarr = (int*)calloc(10000001, sizeof(int));

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &k);
		if (k >= 0)
			pArr[k]++;
		else
			pArr2[-k]++;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) 
		scanf("%d", &pMarr[i]);
	
	
	for (int i = 0; i < m; i++) {
		if (pMarr[i] >= 0)
			printf("%d", pArr[pMarr[i]]);
		else
			printf("%d", pArr2[-pMarr[i]]);
		
		if(i!=m-1)
			printf(" ");
		
	}
	printf("\n");
	return 0;

}