#include <iostream>
using namespace std;
int f, s, g, u, d;
int que[1000001];
int start=0, ended=0;
int visited[1000001] = { 0 };

void bfs() {

	que[ended++] = s;

	while (start != ended) {

		int current = que[start++];

		if (current + u <= f && !visited[current + u]&& u!=0) {
			visited[current + u] = visited[current] + 1;
			que[ended++] = current + u;
		}
		if (current - d > 0 && !visited[current - d] && d!=0) {
			visited[current - d] = visited[current] + 1;
			que[ended++] = current - d;
		}

	}
}

int main() {
	cin >> f >> s >> g >> u >> d;

	bfs();

	if (!visited[g] && f != s)
		cout << "use the stairs" << endl;
	else
		cout << visited[g] << endl;;
}