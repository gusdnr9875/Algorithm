	#include <iostream>
	using namespace std;
	int n = 0, plus_size = 0;
	int arr[12] = { 0 };
	int pluss[12] = { 0 };
	int a[4] = { 0 };
	int visited[12] = { 0 };
	int result[13] = { 0 };
	int minied = 1000000000;
	int maxed =-1000000000;
	void dfs(int current, int cnt) {
		if (cnt == (n - 1)) {
			int num = arr[0];
			for (int i = 1; i <= n - 1; i++)
				if (result[i - 1] == 1)
					num += arr[i];
				else if (result[i - 1] == 2)
					num -= arr[i];
				else if (result[i - 1] == 3)
					num *= arr[i];
				else if (result[i - 1] == 4)
					num /= arr[i];
			if (num > maxed) maxed = num;
			if (num < minied) minied = num;
			return;
		}

		for (int i = 0; i < plus_size; i++) {
			if (visited[i] == 0) {
				visited[i] = 1;
				result[cnt] = pluss[i]; //+인지를 넣어놓고 
				dfs(i, cnt + 1);
				result[cnt] =0;
				visited[i] = 0;
			
			}

		}

	}
	int main() {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 1; i <= 4; i++) {
			cin >> a[i];
			while (a[i]--) {
				pluss[plus_size++] = i;
			}
		}

		for (int i = 0; i < plus_size; i++) {
			visited[i] = 1;
			result[0] = pluss[i]; //+인지를 넣어놓고 
			dfs(i, 1);
			result[0] = 0; //+인지를 넣어놓고 
			visited[i] = 0;
		}
		cout << maxed << endl;
		cout << minied << endl;
	
	}