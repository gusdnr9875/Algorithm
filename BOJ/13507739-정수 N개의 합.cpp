#include <stdio.h>

int a[1000000] = { 0 };

long long sum(int *a, int n);

int main() {
	a[0] = 1, a[1] = 100;
	printf("%d" ,sum(a, 2));

}

long long sum(int *a, int n) {
	long long total = 0;

	for (int i = 0; i < n; i++)
		total += a[i];

	return total;
}