#include <iostream>
using namespace std;

int arr[16][16] = { 0 };
int mini = 987654321;
int dat[16] = { 0 };
int n = 0;

void dfs(int start, int current, int sum, int count) {
	if (start == current&&count == n) { //만약 시작점이랑 현재지점이랑 같고 카운트값이 (순회) 주어진 n가 같으면 
		if (mini > sum) {  //min값보다 sum이 작으면 
			mini = sum;
		}
		return;
	}

	for (int i = 1; i <= n; i++) { //자 이제 순회를 시작합니다. 
		if (arr[current][i] == 0) continue; //만약 간선이 없다면 갈수 없어요.

		if (dat[current] != 1) {

			dat[current] = 1; //현재 지점을 지나왔다고 표시해주기 
			sum += arr[current][i]; //갈 지점에 가중치값을 더해주고!

			if (sum <= mini)
				dfs(start, i, sum, count + 1);  //다음 순회할곳으로 ㄱㄱ 

												//방문한 기록과 합 초기화
			dat[current] = 0;
			sum -= arr[current][i];
		}

	}

}


int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	/*
	for (int i = 1; i <= n; i++)
	dfs(i, i, 0, 0);
	*/
	dfs(1, 1, 0, 0);

	cout << mini << endl;
}