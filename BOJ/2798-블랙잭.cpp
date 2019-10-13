
#include <stdio.h>
#include <math.h>
#include<malloc.h>
int factorial(int n) {
	int result = 1;
	for (int i = 1; i < n + 1; i++) {
		result = result * i;
	}
	return result;
}

int main() {

	int n, m; // n : ī���� ����,  m : ���ذ�
	scanf("%d %d", &n, &m);
	int t = factorial(n) / (factorial(n - 3) * factorial(3)); // nC3 = n!/(n-3)!3!
	int answer = 10000;
	int cnt = 0;

	int *arr = (int*)malloc(sizeof(int) * n); // n�� �� 3�� ����
	int *ans = (int*)malloc(sizeof(int) * t); // ���� �� �ִ� ����� �� ��ŭ �迭 ����


	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 2; i++) { // i�� 2����
		for (int j = i + 1; j < n - 1; j++) { // j�� 3���� 
			for (int k = j + 1; k < n; k++) { // k�� 4����
				ans[cnt] = arr[i] + arr[j] + arr[k];
				if (abs(m - ans[cnt]) < abs(m - answer))
					answer = ans[cnt];
				cnt++;
			}
		}
	}

	printf("%d", answer);
	return 0;
}