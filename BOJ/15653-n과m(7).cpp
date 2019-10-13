#include <stdio.h>


int n = 0, m = 0, temp = 0;
int arr[10] = { 0 };
int result[10] = { 0 };
void dfs(int x) {
	if (x == m) {
		for (int i = 0; i < x; i++)
			printf("%d ", result[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		result[x] = arr[i];
		dfs(x + 1);
	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i] < arr[j]) temp = arr[j], arr[j] = arr[i], arr[i] = temp;
	
		
	dfs(0);
}