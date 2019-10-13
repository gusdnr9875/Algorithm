#include <stdio.h>
double arr[4] = { 0 };
int mindex = 0;
double sum = 0, temp = 0,maxx=0;
int main() {
	for(int i =0;i<4;i++)
		scanf("%lf", &arr[i]);
	for (int i = 0; i < 4; i++) {
		sum = arr[0] / arr[2] + arr[1] / arr[3];
		if (sum > maxx) maxx = sum, mindex = i ;
		temp = arr[2], arr[2] = arr[3], arr[3] = arr[1],arr[1]=arr[0],arr[0]=temp;
	}
	printf("%d\n", mindex);
}