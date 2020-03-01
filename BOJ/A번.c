#include <stdio.h>

int main() {
	int n = 0; 
	scanf("%d", &n);

	n = n % 8;
	if (n == 1)
		n = 1;
	else if (n == 2)
		n = 2;
	else if (n == 3)
		n = 3;
	else if (n == 4)
		n = 4;
	else if (n == 5)
		n = 5;
	else if (n == 6)
		n = 4;
	else if (n == 7)
		n = 3;
	else if (n == 0)
		n = 2;
	printf("%d\n", n);


}