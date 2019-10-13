#include <stdio.h>
int t = 0;

int main() {
	int n = 0,sum;
	scanf("%d", &t);

	while (t--) {
		sum = 0;
		scanf("%d", &n);

		for (int i = 1; i <= n; i += 2)
			sum += i;

		printf("%d\n", sum);
	}

}