#include <iostream>
using namespace std;

int n = 0,cnt = 0;
int x, y, d, g;
bool visited[401][401] = { 0 };
int dhistory[20][11] = { 0 };
int dcur[20] = { 0 };

int main() {
	cin >> n;
	
	for(int u=0;u<n;u++) {
		cin >> x >> y >> d >> g; // ��ǥ���� �Է¹޽��ϴ�. 
		x += 200, y += 200;

		visited[y][x] = 1;
	
		if (d == 0) // 0���뿡 ���� �׾��ִ� �ൿ 
			visited[y][x + 1] = 1, x++;
		else if (d == 1)
			visited[y - 1][x] = 1, y--;
		else if (d == 2)
			visited[y][x - 1] = 1, x--;
		else
			visited[y + 1][x] = 1, y++;
		
		dhistory[u][dcur[u]++] = d; // ó���� �� ����������� ���������� �����մϴ�. 

		for (int i = 1; i <= g; i++) { // 1����� �ѹ� 2����� 2�� ~
			int k = dcur[u];
			for (int j =  k-1; j >= 0; j--) { //1����� �ѹ� 2����� �ι�  �� ������� ������ �׷��ִ°Ŵ� �Ȱ��� 
				//��뿡�� ��� �̵��ߴ��� �����ؾ��� 
				if (dhistory[u][j] == 0) visited[y - 1][x] = 1, y--, dhistory[u][dcur[u]++] = 1;    //���� ������ 
				else if (dhistory[u][j] == 1)visited[y][x - 1] = 1, x--, dhistory[u][dcur[u]++] = 2;
				else if (dhistory[u][j] == 2)visited[y + 1][x] = 1, y++, dhistory[u][dcur[u]++] = 3;   //�Ʒ���
				else  visited[y][x + 1] = 1, x++, dhistory[u][dcur[u]++] = 0; //���������� ������ 
			}
		}

	}
	for (int i = 0; i < 400; i++)
		for (int j = 0; j < 400; j++)
			if (visited[i][j] == 1 && visited[i + 1][j] == 1 && visited[i][j + 1] == 1 && visited[i + 1][j + 1] == 1)
				cnt++;

	

	cout << cnt << '\n';
}