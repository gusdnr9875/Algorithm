#include <stdio.h>
int n = 0, m = 0,cnt=0;
char arr[55][55];
char arr2[55][55];

int veri() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (arr[i][j] != arr2[i][j])
				return 0;
	}
	return 1;
}

int main() {
	scanf("%d %d", &n,&m);

	for (int i = 0; i < n; i++)
		scanf("%s", &arr[i]);

	for (int i = 0; i < n; i++)
		scanf("%s", &arr2[i]);
	if (n<3 || 3>m) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (arr[i][j] != arr2[i][j])
				{
					printf("-1\n");
					return 0;
				}
		printf("0\n");
		return 0;

	}
	for (int i = 0; i <= n-3; i++) {
		for (int j = 0; j <= m-3; j++) {
			if (arr[i][j] != arr2[i][j]) { //만약 그수의 값이 다르다면 
				for (int k = 0; k < 3; k++)
					for (int r = 0; r < 3; r++) {
						if (arr[i + k][j + r] == '0')arr[i + k][j + r] = '1';
						else arr[i + k][j + r] = '0';
					}
				cnt++;
			}
			//검사단계
			if (veri() == 1)
			{
				printf("%d\n", cnt);
				return 0;
			}
		}
	}

	printf("-1\n");
	return 0;
}