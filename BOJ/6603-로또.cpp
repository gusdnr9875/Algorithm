#include <stdio.h>
#include <string.h>

int k = 0;
int lotto[13] = { 0 };
int combi[13] = { 0 };


void backtracking(int start, int dep) {
	if (dep == 6) {
		for (int i = 0; i <5; i++)
			printf("%d ", combi[i]);
		printf("%d\n", combi[5]);
		return;
	}

	for (int i = start; i < k; i++) {
		combi[dep] = lotto[i]; 
		backtracking(i + 1, dep + 1);
	}
}


int main() {
	while (1) {
		scanf("%d", &k);
		if (k == 0)
			break;

		for (int i = 0; i < k; i++) {
			scanf("%d", &lotto[i]);
		}
		backtracking(0, 0);
		printf("\n");
	}
	return 0;
}