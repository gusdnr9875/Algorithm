#include <iostream>
using namespace std;
int n = 0, m = 0,mcur=0;
int arr[51][51] = { 0 };
int birus[11][3] = { 0 };
int que[2501][2] = { 0 };
int copyarr[51][51] = { 0 };
int mini = 1000000000;

int countsecond() {
	int start = 0, end = 0;
	int cnt = 0,currentcount=0,nextcount=0;
	

	for (int i = 0; i < mcur; i++) {
		if (birus[i][2] == 1) {
			arr[birus[i][0]][birus[i][1]] = 3;	

			que[end][0] = birus[i][0];
			que[end++][1] = birus[i][1];
			copyarr[que[end - 1][0]][que[end - 1][1]] = 1;
			currentcount++;

		}
		
	
	}
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 2) copyarr[i][j] = 0;
			else copyarr[i][j] = arr[i][j];
		}

	
	while (start != end) {
		nextcount = 0;
		//cout << currentcount << endl;
		for (int i = 0; i < currentcount; i++) {
					
				int y = que[start][0];
				int x = que[start++][1];

				if ((y - 1) >= 0 && copyarr[y - 1][x] == 0) {
					que[end][0] = y - 1, que[end++][1] = x;
					copyarr[y - 1][x] = 1;
					nextcount++;
				}
				if ((y + 1) < n && copyarr[y + 1][x] == 0) {
					que[end][0] = y + 1, que[end++][1] = x;
					copyarr[y + 1][x] = 1;
					nextcount++;
				}
				if ((x + 1) < n && copyarr[y][x + 1] == 0) {
					que[end][0] = y, que[end++][1] = x + 1;
					copyarr[y][x + 1] = 1;
					nextcount++;
				}
				if ((x - 1) >= 0 && copyarr[y][x - 1] == 0) {
					que[end][0] = y, que[end++][1] = x - 1;
					copyarr[y][x - 1] = 1;
					nextcount++;
				}

			
		}
		currentcount = nextcount;
		cnt++;
	}

	for (int i = 0; i < mcur; i++)
		if (birus[i][2] == 1) {
			arr[birus[i][0]][birus[i][1]] = 2;
			//cout << birus[i][0] << birus[i][1] << endl;
		}

	
	return cnt;

}

void searchspot(int cnt, int current) {
	if (cnt == m) {
		int cnt= countsecond();
		bool jud = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (copyarr[i][j] == 0) jud = false;
		if (mini > cnt && jud==true) mini = cnt;
		return;
	}
	
	for (int i = current; i < mcur; i++)
	{
		birus[i][2] = 1;
		searchspot(cnt + 1, current + 1);
		birus[i][2] = 0;
		searchspot(cnt, current + 1);
		return;
	}
}

int main() {
	cin >> n>>m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2)
				birus[mcur][0] = i, birus[mcur++][1] = j;
		}

	searchspot(0, 0);
	if (mini > 2500) cout << -1 << endl;
	else cout << mini -1  << '\n';
}