#include <stdio.h>
int n = 0,  m = 0;
char arr2[105][105];
char arr[105][105];
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}
	for(int i=0;i<n;i++){
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '|')
				arr2[m-j-1][i] = '-';
			else if (arr[i][j] == '/')
				arr2[m-j-1][i] = 92;
			else if (arr[i][j] == '-')
				arr2[m - j - 1][i] = '|';
			else if (arr[i][j] == 92)
				arr2[m - j - 1][i] = '/';
			else if (arr[i][j] == '^')
				arr2[m - j - 1][i] = '<';
			else if (arr[i][j] == '<')
				arr2[m - j - 1][i] = 'v';
			else if (arr[i][j] == 'v')
				arr2[m - j - 1][i] = '>';
			else if (arr[i][j] == '>')
				arr2[m - j - 1][i] = '^';
			else
				arr2[m - j - 1][i] = arr[i][j];
		}

	

	}


	for (int i = 0; i < m; i++)
		printf("%s\n", arr2[i]);



}