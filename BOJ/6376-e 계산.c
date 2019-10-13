#include <stdio.h>

double arr[10] = { 0 };
int main() {

	arr[0] = 1, arr[1] = 2,arr[2]=2.5;



	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	for (int i = 3; i <= 9; i++) {
		double a=1;
		for (int j = i; j > 1; j--)
			a *= j;

		arr[i] = (double)1 / a+ arr[i-1];
		printf("%d %.9lf\n",i,arr[i]);
	}
}