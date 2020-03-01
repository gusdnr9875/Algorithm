#include <stdio.h>
char arr[5001] = { 0 };
char arr2[5001] = { 0 };
int start = 0, ended = 0;
int cnt = 0;
int m = 0, n1 = 0, n2 = 0, n3 = 0;
int main() {

	scanf("%d %d %d", &n1, &n2, &n3);

	
	for (int i = 0; i < n1; i++) {
		scanf("%d", &m);
		arr[m]++;
	}
	for (int i = 0; i < n2; i++) {
		scanf("%d", &m);
		arr[m]++;
	}
	for (int i = 0; i < n3; i++) {
		scanf("%d", &m);
		arr[m]++;
	}
	for (int i = 1; i <= 5000; i++) {
		if (arr[i] < 2) continue;
		if (arr[i] >= 2) {
			cnt++;
			arr2[ended++] = i;
		}
	}
	printf("%d\n", cnt);


	for (int i = 0; i < ended; i++)
		printf("%d\n", arr2[i]);
}