#include <stdio.h>
int n = 0, s = 0;
int arr[100000] = { 0 };
int start = 0, end = 0;
int sum = 0, ans = 1000000000;
int main() {

	scanf("%d %d", &n, &s);

	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);

	sum = arr[0];

	while (start <= end&&end < n) {
		
		if (sum < s) {
			sum+=arr[++end];
		}
		else if(sum>=s) {
			int len = end - start + 1;
			if (ans > len) ans = len;
			if (start < end) {
				sum -= arr[start++];
			}

		}
		
	}
	if(ans==1000000000) printf("0", ans);
	else printf("%d\n", ans);

}