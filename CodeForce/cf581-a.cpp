#include <stdio.h>
char arr[101];
int cnt = 0;
int result = 0;
int jud = 0;
int main() {
	scanf("%s", arr);
	for(cnt=0;arr[cnt];cnt++){}

	for (int i = cnt - 1, j = 1; i > 0; i--, j++)
	{
		if (j % 2 == 1)
			result++;
		if (arr[i] == '1')
			jud = 1;
	}
	if (jud == 1&&cnt%2==1)
		result++;

	printf("%d\n", result);
	return 0;
}