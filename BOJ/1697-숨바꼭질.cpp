#include <iostream>
using namespace std;
int mini = 100000;
int visited[100001] = { 0 }; //0~100000
int n = 0, k = 0;

void bfs() {


}



int main() {
	cin >> n >> k;

	if (n < k)
		mini = k - n;
	else
		mini = n - k;






}