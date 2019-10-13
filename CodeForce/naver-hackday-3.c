#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// buttons_len, scores_len은 각각 배열 buttons, scores의 길이입니다.
// solution 함수의 파라미터로 주어지는 문자열은 const로 주어집니다.
// 변경이 필요한 경우에는 문자열을 복사해서 사용하세요.

int main() {
	char command[100];
	char buttons[100][100];

	int scores[10] = { 2,3 };
	int buttons_len = 2;
	int answer = 0;
	int cnt = 0;
	int dp[1001] = { 0 }; //디피문제네 
	int arr[101] = { 0 };

	scanf("%s", command);
	for (int i = 0; i < 2; i++)
		scanf("%s", buttons[i]);

	for (int i = 0; i<buttons_len; i++) {
		for (int j = 0; buttons[j]; j++)
			arr[i]++; // 버튼마다 길이를 측정 
	}
	dp[0] = 1;
	for (int i = 0; i<100; i++)
		if (arr[i] == 1)
			if (dp[i]<scores[i]) dp[i] = scores[i];

	for (int i = 1; i<command[i]; i++) { //모든 버튼에서 적용하자 
		cnt++;
		for (int j = 0; j< buttons_len; j++) {
			if ((arr[j] - 1) <= i) { //해당문자열이 작아야 넣어보지
				char jud = '1'; //같은지 확인하려고 써 
				for (int k = arr[j] - 1; k >= 0; k--) //같나 확인해보자
					if (buttons[j][k] != command[i + k - (arr[j] - 1)]) {
						jud = '0';
						break;
					}
				if (jud == '1') {//만약 문자열이 포함이 된다면
					if ((dp[i - arr[j]] + scores[j]) >(dp[i - 1] + 1))
						dp[i] = (dp[i - arr[j]] + scores[j]);
					else
						dp[i] = dp[i - 1] + 1;
				}

			}

		}
		answer = dp[i];
	}
	
	printf("%d\n", answer);
}