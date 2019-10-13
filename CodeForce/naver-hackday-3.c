#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// buttons_len, scores_len�� ���� �迭 buttons, scores�� �����Դϴ�.
// solution �Լ��� �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�.
// ������ �ʿ��� ��쿡�� ���ڿ��� �����ؼ� ����ϼ���.

int main() {
	char command[100];
	char buttons[100][100];

	int scores[10] = { 2,3 };
	int buttons_len = 2;
	int answer = 0;
	int cnt = 0;
	int dp[1001] = { 0 }; //���ǹ����� 
	int arr[101] = { 0 };

	scanf("%s", command);
	for (int i = 0; i < 2; i++)
		scanf("%s", buttons[i]);

	for (int i = 0; i<buttons_len; i++) {
		for (int j = 0; buttons[j]; j++)
			arr[i]++; // ��ư���� ���̸� ���� 
	}
	dp[0] = 1;
	for (int i = 0; i<100; i++)
		if (arr[i] == 1)
			if (dp[i]<scores[i]) dp[i] = scores[i];

	for (int i = 1; i<command[i]; i++) { //��� ��ư���� �������� 
		cnt++;
		for (int j = 0; j< buttons_len; j++) {
			if ((arr[j] - 1) <= i) { //�ش繮�ڿ��� �۾ƾ� �־��
				char jud = '1'; //������ Ȯ���Ϸ��� �� 
				for (int k = arr[j] - 1; k >= 0; k--) //���� Ȯ���غ���
					if (buttons[j][k] != command[i + k - (arr[j] - 1)]) {
						jud = '0';
						break;
					}
				if (jud == '1') {//���� ���ڿ��� ������ �ȴٸ�
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