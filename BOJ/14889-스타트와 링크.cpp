#include<iostream>
using namespace std;
int arr[21][21] = { 0 };
int visited[21] = { 0 };
int mini = 1000000000;
int n = 0;
int countstatus(int a) {
	int sum = 0;
	for (int i = 0; i < n; i++)
		if (visited[i] == a) {
			for (int j = i + 1; j < n; j++)
				if (visited[j] == a) {
					sum += arr[i][j];
					sum += arr[j][i];
				}
		}

	return sum;

}
void search(int cnt,int current) {
	if (cnt == n / 2) {
		int a= countstatus(1);
		int b= countstatus(0);
		if (a == b) mini = 0;
		else if (a > b) {
			if (mini > (a - b))
				mini = a - b;
		}
		else
			if (mini > (b - a))
				mini = b - a;
		return;

	}
	for (int i = current; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			search(cnt + 1,current+1);
			visited[i] = 0;
			search(cnt, current + 1);
			return;
		}
		
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	search(0,0);

	cout << mini << '\n';


 }