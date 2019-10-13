#include <iostream>
#include <cmath>
using namespace std;
int n = 0;
int arr[11][11] = { 0 }; //���������� �����ϴ� ����
int people[11] = { 0 }; //�α����� �����ϴ� ����
int input[11] = { 0 };
int visited[11] = { 0 };
int result = 1000000000;
int sum2 = 0,sum3=0; //���� 2�� �α����� �ѷ�
int cnt = 0;
void dfs(int pos,int sum) { //����1�� sum���� ���� ���� 

	if (abs(sum2- sum) < result) result = abs(sum2- sum);

	for (int i = 1; i<=10; i++) { //���������� �����ϴ°��� 
		if (arr[pos][i] == 1&& visited[i]==0) { //����Ǿ��ְ� �湮 ��������

			visited[i] = 1;
			sum2 -= people[i];
			dfs(i, sum + people[i]);
			sum2 += people[i];
			visited[i] = 0;
		}
	}
}
void search(int num) {

	for (int i = 1; i <= 10; i++)
	{
		if (arr[num][i] == 1 && visited[i] == 0) {
			visited[i] = 1;
			if (cnt == 1) sum3 += people[i];
			else if (cnt == 2) sum2 += people[i];
			search(i);
		}
			
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> people[i];
		sum2 += people[i];
	}
	if (n == 2) {
		for (int i = 1; i <= n; i++) {
			cin >> input[i];
			for (int j = 0; j<input[i]; j++) {
				int input2 = 0;
				cin >> input2;
				arr[i][input2] = 1; // ���������̸� 1�� ǥ���ϴ°� 
			}
		}
		cout << abs(people[1] - people[2]) << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
		for(int j=0;j<input[i];j++ ){
			int input2 = 0;
			cin >> input2;
			arr[i][input2] = 1; // ���������̸� 1�� ǥ���ϴ°� 
		}
	}
	for (int i = 1; i <= n; i++) {
		if (input[i] > 0) {
			visited[i] = 1;
			sum2 -= people[i];
			dfs(i, people[i]);
			sum2 += people[i];
			visited[i] = 0;
		}
	}
	
	sum2 = 0; // ����� �ΰ��϶��� ���̰��� ����ϱ� ���ؼ� ��Ȱ���Ұž� 

	for (int i = 1; i <= 10; i++) { //���� ����� ����� �������ؼ� 
		if (input[i] > 0 && visited[i] == 0) {
			visited[i] = 1;
			cnt++;
			if (cnt == 1) sum3 += people[i];
			else if (cnt == 2) sum2 += people[i];
			search(i);
		}

	}

	if (result == 1000000000)
		cout << -1 << endl;
	else if (cnt == 1)
		cout << result << endl;
	else if (cnt == 2)
		cout << abs(sum2 - sum3) << endl;
	else
		cout << -1 << endl;
	return 0;
}