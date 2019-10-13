#include <iostream>
#include <cmath>
using namespace std;
typedef struct p {
	int y;
	int x;
}point;

point house[2500];
point chik[2500];
bool visited[2500] = { 0 };
int house_cursor = 0, chik_cursor = 0;
int n = 0, m = 0, input = 0;
int result = 1000000000;

void dfs(int cnt,int current) {
	if (cnt == m) {
		int sum = 0; //해당 케이스의 값을 더한다음에 result랑 비교할거야 
		for (int i = 0; i < house_cursor; i++) {
			int mini = 1000;
			for (int j = 0; j < chik_cursor; j++) {
				if (visited[j] == 1) {
					int val = abs(house[i].y - chik[j].y) + abs(house[i].x - chik[j].x);
					if (mini > val) mini = val;
					
				}
		
			}
			sum += mini;
		}
		if (result > sum) result = sum;
		return;
	}

	for (int i = current; i < chik_cursor; i++) {
		if (visited[i] == 0)
		{
			visited[i] = 1;
			dfs(cnt + 1,i+1);
			visited[i] = 0;
			
			
		}
	}
	return;
}


int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> input;
			if (input == 1)
				house[house_cursor].x = j, house[house_cursor++].y = i;
			else if (input == 2)
				chik[chik_cursor].x = j, chik[chik_cursor++].y = i;
		}

	dfs(0,0);
	
	cout << result << '\n';
	
}