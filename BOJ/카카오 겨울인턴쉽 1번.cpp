#include <iostream>
#include <string>
#include <vector>
using namespace std;



int main() {
	vector<vector<int>> board = { {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} };

	vector<int> moves = { 1,5,3,5,1,2,1,4 };
	int n = board[0].size();
	int arr[30][30];
	vector<vector<int>> board2;
	vector<int> before;

	int answer = 0;
	int current = 0;
	
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			arr[j][i] = board[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = arr[i][n - j - 1];
			//cout << board[i][j] << ' ';
		}
		//cout << '\n';
	}

	for (int i = 0; i < moves.size(); i++)
	{
		int num = moves.at(i) - 1; //값을 입력받구 
		if (!board[num].empty()) {
			current = board[num].back(); //가져와서
			board[num].pop_back();
		}
		else continue;
		while (current == 0) {
			current = board[num].back(); //가져와서
			board[num].pop_back();
		}

		//if (current == 0)  continue;
		
		if (before.size() == 0) {
			before.push_back(current);
			continue;
		}
		//cout << current<< "  " << before.back() << endl;
		if (current == before.back()) {
			answer += 2;
			before.pop_back();
			//cout << current;
		}
		else
			before.push_back(current);

	}

	cout << answer << endl;

}