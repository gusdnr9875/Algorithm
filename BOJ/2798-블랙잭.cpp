
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

	int n, m; // n : 카드의 개수,  m : 기준값
	scanf("%d %d", &n, &m);
	int t = factorial(n) / (factorial(n - 3) * factorial(3)); // nC3 = n!/(n-3)!3!
	int answer = 10000;
	int cnt = 0;

	int *arr = (int*)malloc(sizeof(int) * n); // n개 중 3개 선택
	int *ans = (int*)malloc(sizeof(int) * t); // 나올 수 있는 경우의 수 만큼 배열 생성


	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n - 2; i++) { // i는 2까지
		for (int j = i + 1; j < n - 1; j++) { // j는 3까지 
			for (int k = j + 1; k < n; k++) { // k는 4까지
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