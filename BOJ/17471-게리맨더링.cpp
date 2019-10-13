#include <iostream>
#include <cmath>
using namespace std;
int n = 0;
int arr[11][11] = { 0 }; //인접구역을 저장하는 공간
int people[11] = { 0 }; //인구수를 저장하는 공간
int input[11] = { 0 };
int visited[11] = { 0 };
int result = 1000000000;
int sum2 = 0,sum3=0; //구역 2의 인구수의 총량
int cnt = 0;
void dfs(int pos,int sum) { //구역1의 sum값을 넣을 예정 

	if (abs(sum2- sum) < result) result = abs(sum2- sum);

	for (int i = 1; i<=10; i++) { //인접구역을 접근하는거지 
		if (arr[pos][i] == 1&& visited[i]==0) { //연결되어있고 방문 안했으면

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
				arr[i][input2] = 1; // 인접구역이면 1로 표시하는겨 
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
			arr[i][input2] = 1; // 인접구역이면 1로 표시하는겨 
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
	
	sum2 = 0; // 덩어리가 두개일때의 차이값을 계산하기 위해서 재활용할거야 

	for (int i = 1; i <= 10; i++) { //현재 덩어리가 몇개인지 보기위해서 
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