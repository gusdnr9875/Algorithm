#include <iostream>
using namespace std;

int n = 0, l = 0;
int arr[101][101] = { 0 };
int visited[101][101] = { 0 };
int cnt = 0;
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++) {
		bool jud = true; // 해당줄이 지나갈 수 있는지 판단합니다.
		int current = arr[i][0]; // 현재 높이 


		for (int j = 0; j < n; j++) { //1번 경사로가 급 낮아지거나 높아질때 
			if ((current - arr[i][j]) == 0) continue;
			else if ((current - arr[i][j]) == 1) {
				for (int k = j ; k < j + l; k++) {
					if (current != (arr[i][k] + 1)) {
						jud = false;
						break;
					}
					else
						visited[i][k] = 1;

				}
				if (jud == false)
					break;
				j = j + l-1;
				current --;
			}
			else if ((current - arr[i][j]) == -1) {
				if (j < l) {
					jud = false;
					break;
				}
				for (int k = j - l; k < j; k++) {
					if (visited[i][k] != 0 || arr[i][k] != (current)) {
						jud = false;
						break;
					}
				}
				if (jud == false)
					break;
				else
					current++;

			}
			else
				jud = false;
			if (jud == false)
				break;

		
				
		}

		if (jud == true) 
			cnt++;
		
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = 0;



	for (int i = 0; i < n; i++) {
		bool jud = true; // 해당줄이 지나갈 수 있는지 판단합니다.
		int current = arr[0][i]; // 현재 높이 


		for (int j = 0; j < n; j++) { //1번 경사로가 급 낮아지거나 높아질때 
			if ((current - arr[j][i]) == 0) continue;
			else if ((current - arr[j][i]) == 1) {
				for (int k = j; k < j + l; k++) {
					if (current != (arr[k][i] + 1)) {
						jud = false;
						break;
					}
					else
						visited[k][i] = 1;

				}
				if (jud == false)
					break;
				j = j + l - 1;
				current--;
			}
			else if ((current - arr[j][i]) == -1) {
				if (j < l) {
					jud = false;
					break;
				}
				for (int k = j - l; k < j; k++) {
					if (visited[k][i] != 0 || arr[k][i] != (current)) {
						jud = false;
						break;
					}
				}
				if (jud == false)
					break;
				else
					current++;

			}
			else
				jud = false;
			if (jud == false)
				break;



		}

		if (jud == true)
			cnt++;

	}




	cout << cnt << '\n';
}