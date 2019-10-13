#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
struct {
	int x;
	int y;
}cl[2];

struct q_v {
	int x;
	int y;
	int value;
};
int ans;
int r, c, t;
int temp_v0[51];
int temp_v1[51];
int room[51][51];
int room_sum[51][51];
int p_x[4] = { 1,-1,0,0 };
int p_y[4] = { 0,0,1,-1 };
queue<q_v> q;

void move_m() {
	int temp1_c0 = 0; int temp2_c0 = 0;
	int temp1_c1 = 0; int temp2_c1 = 0;

	for (int a = 2; a <= c; a++) {
		temp2_c0 = room[cl[0].y][a];
		temp2_c1 = room[cl[1].y][a];
		room[cl[0].y][a] = temp1_c0; room[cl[1].y][a] = temp1_c1;
		temp1_c0 = temp2_c0; temp1_c1 = temp2_c1;
	}//----> 이방향

	for (int a = cl[0].y - 1; a > 0; a--) {
		temp2_c0 = room[a][c];
		room[a][c] = temp1_c0;
		temp1_c0 = temp2_c0;
	}// 오른쪽 끝에서 cl0의 움직임

	for (int a = cl[1].y + 1; a <= r; a++) {
		temp2_c1 = room[a][c];
		room[a][c] = temp1_c1;
		temp1_c1 = temp2_c1;
	}// 오른쪽 끝에서 cl1의 움직임

	for (int a = c - 1; a > 1; a--) {
		temp2_c0 = room[1][a];
		temp2_c1 = room[r][a];
		room[1][a] = temp1_c0; room[r][a] = temp1_c1;
		temp1_c0 = temp2_c0; temp1_c1 = temp2_c1;
	}// <----- 이방향

	for (int a = 1; a < cl[0].y; a++) {
		temp2_c0 = room[a][1];
		room[a][1] = temp1_c0;
		temp1_c0 = temp2_c0;
	}// 왼쪽 끝에서 cl0의 움직임

	for (int a = r; a > cl[1].y; a--) {
		temp2_c1 = room[a][1];
		room[a][1] = temp1_c1;
		temp1_c1 = temp2_c1;
	}// 왼쪽 끝에서 cl1의 움직임

}

void sp() {
	while (t--) { // 입력으로 들어온 t초만큼만 돌려줌
		while (!q.empty()) {
			q_v now_ = q.front();
			q.pop();
			if (now_.value / 5 == 0) continue;
			int summ = now_.value / 5;
			for (int dis = 0; dis < 4; dis++) {
				int nx = now_.x + p_x[dis];
				int ny = now_.y + p_y[dis];
				if (nx > 0 && nx < c + 1 && ny>0 && ny < r + 1 && room[ny][nx] != -1) {

					room_sum[ny][nx] += summ;
					room[now_.y][now_.x] -= summ;
				}
			} //4방향
		}//while
		for (int y = 1; y <= r; y++) {
			for (int x = 1; x <= c; x++) {
				room[y][x] += room_sum[y][x];
			}
		}
		move_m();//공기청정기가 돌아가는 부분
		for (int y = 1; y <= r; y++) {
			for (int x = 1; x <= c; x++) {
				if (room[y][x] != 0) {
					q_v n;
					n.x = x;
					n.y = y;
					n.value = room[y][x];
					q.push(n);
				}
			}
		}

		memset(room_sum, 0, sizeof(room_sum));

	}
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			ans += room[y][x];
		}
	}

}

int main() {

	cin >> r >> c >> t;
	int aa = 0; q_v temp; memset(room_sum, 0, sizeof(room_sum));
	for (int y = 1; y <= r; y++) {
		for (int x = 1; x <= c; x++) {
			cin >> room[y][x];
			if (room[y][x] == -1) {
				cl[aa].x = x;
				cl[aa].y = y;
				aa++;
			} //공기청정기 저장
			if (room[y][x] != -1 && room[y][x] != 0) {
				temp.x = x;
				temp.y = y;
				temp.value = room[y][x];
				q.push(temp);
			}//미세먼지 저장
		}
	}
	sp();
	cout << ans + 2;
}