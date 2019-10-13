#include <stdio.h>
int arr[100001] = { 0 };
int k = 0, pos = 0;



int main() {

	int k = 0;
	int sum = 0;
	int before = 0,num=0;
	scanf("%d", &k);


	for (int i = 0; i < k; i++) {
		scanf("%d", &num);
		if (num != 0)
			arr[pos++] = num;
		if (num == 0)
			arr[--pos]=0;
			
	
	}
	for (int i = 0; i <= pos; i++)
		sum += arr[i];
	printf("%d\n", sum);
}