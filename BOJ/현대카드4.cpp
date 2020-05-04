#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int x_ar[4] = { -1,1,0,0 };
int y_ar[4] = { 0,0,1,-1 };
vector<int> arr[6]; // 배열이라네
void bfs() {

	queue <int> que[2];

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			int visited[6][6] = { 0 };
			bool jud = false;
			if (arr[i][j] != 0 && visited[i][j] == 0) {
				que[0].push(i);
				que[1].push(j);

				while (!que[0].empty()) {
					int yy = que[0].front();
					int xx = que[1].front();
					que[0].pop();
					que[1].pop();
					visited[yy][xx] = 1;

					for (int k = 0; k < 4; k++) {
						int y = yy + y_ar[k];
						int x = xx + x_ar[k];

						if (y >= 0 && y < 6 && x >= 0 && x < 6) 
							if (arr[y][x] == arr[yy][xx]) {//색깔이 같으면 
								visited[y][x] = visited[yy][xx] + 1;
								que[0].push(y);
								que[1].push(x);

							}
						
						if (visited[y][x] >= 3)
							jud = true;

					}

				}
			}
			if (jud == true) {
				for (int k = 0; k < 6; k++)
					for (int u = 0; u < 6; u++)
						if (visited[k][u] >= 1)
							arr[k][u] = -1;

				
			}
			for (int h = 0; h < 6; h++)
				for (int l = 0; l < 6; l++)
					if (arr[h][l] == -1)
						arr[h].erase(arr[h].begin() + l);

			for (int h = 0; h < 6; h++)
				for (int l = arr[h].size(); l < 6; l++)
					arr[h].push_back(0);

					

		}
	}
	


}
vector<string> solution(vector<vector<int>> macaron) {
	vector<string> answer;
	
	//cout << macaron.size() << endl;

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 6; j++)
			arr[i].push_back(0);
	for (int i = 0; i < macaron.size(); i++) { //위치랑 색깔 순서
		
		int pos = macaron[i][0] - 1;
		for (int j = 0; j < 6; j++) {
			if (arr[pos][j] == 0) {
				arr[pos][j] = (macaron[i][1]); //위치에 색깔투입
				break;
			}
		}
		
		bfs();
		
		
		
	}
	for (int i = 0; i < 6; i++) {
		string o;
		for (int j = 0; j < 6; j++) {
			o += (arr[i][j] + '0');

		}
		answer.push_back(o);
	}


	return answer;
}

int main() {

	vector<vector<int>> macaron = { {1,1},{2,1},{1,2},{3,3},{6,4},{3,1},{3,3},{3,3},{3,4},{2,1} };

	solution(macaron);
}