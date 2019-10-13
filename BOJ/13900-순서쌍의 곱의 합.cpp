#include <stdio.h>
int n = 0, input = 0;
int arr[10001] = { 0 };
long long sum = 0;
long long a, b, c, d;
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &input);
		arr[input]++;
	}

	for (int i = 0; i <= 10000; i++) {
		if (arr[i] == 0) continue;
		for (int j = 0; j < i; j++) {
			if (arr[j] == 0) continue;
			a = i, b = j, c = arr[j], d = arr[i];
			sum += a*b*c*d;
			
		}
		if (arr[i] > 1) {
			for (int j = 1; j < arr[i]; j++) {
				a = i, b = j;
				sum += a*a*b;
			}
		}
	}

	
	printf("%lld\n", sum);
}