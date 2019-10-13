#include <stdio.h>
int n = 0, l = 0, r = 0;
long long mini = 0 , maxed = 0;
int temp2 = 0;
int main() {
	scanf("%d %d %d", &n, &l, &r);
	
	mini = (n - l) * 1;
	for (int i = 1; i <= l; i++) {
		int temp = 1;
		for (int j = 1,k=1; k <= i;k++, j *= 2)
			temp += j/2;
		mini += temp;
	}


	for (int i = 1; i <= r; i++) {
		temp2 = 1;
		for (int j = 1,k = 1; k <= i; k++,j *= 2)
			temp2 += j/2;
		maxed+= temp2;

	}
	maxed += temp2*(n - r);

	printf("%lld %lld\n", mini,maxed);
}