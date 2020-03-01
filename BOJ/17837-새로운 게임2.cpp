#include <iostream>
using namespace std;

typedef struct pos {
	int x;
	int y;
	int dir; //방향값을 저장

}posit;
typedef struct ar {
	int a;
	int stack[10];
	int sized; //스택의 사이즈를 

}ar;

int n = 0, k = 0;
posit pos[10];
ar arr[14][14]= { 0 };
int stack[14][14][10];


void build_stack_white(int x, int y, int post_x, int post_y, int j) {
	
	int currentsize = 0;
	for (int i = 0; i < arr[y][x].sized; i++)
		if (arr[y][x].stack[i] == j + 1) {
			currentsize = i; //스택에 있는 위치를 기억합니다. 
		}

	for (int k = currentsize; k < arr[y][x].sized; k++) {//스택위치부터 그위에것들을 쌓아주려고 
		arr[post_y][post_x].stack[arr[post_y][post_x].sized++] = arr[y][x].stack[k]; //넣어주면서 size를증가
		arr[y][x].stack[k] = 0;
		int asd = arr[y][x].stack[k] - 1;
		pos[asd].x = post_x, pos[asd].y = post_y;
		cout << n << endl;
	
		cout << post_y << endl;
	}
	arr[y][x].sized = currentsize; //원래 스택을 사이즈가 줄어들지 

}

void build_stack_red(int x, int y, int post_x, int post_y, int j) {

	int currentsize = 0, len = arr[y][x].sized;
	for (int i = 0; i < arr[y][x].sized; i++)
		if (arr[y][x].stack[i] == j + 1) {
			currentsize = i; //스택에 있는 위치를 기억합니다. 
		}

	for (int k = currentsize; k < arr[y][x].sized; k++) {//스택위치부터 그위에것들을 쌓아주려고 
		arr[post_y][post_x].stack[arr[post_y][post_x].sized++] = arr[y][x].stack[len-k-1]; //넣어주면서 size를증가
		arr[y][x].stack[len - k - 1] = 0;
		pos[arr[y][x].stack[k] - 1].x = post_x;
		pos[arr[y][x].stack[k] - 1].y = post_y;
	}
	arr[y][x].sized = currentsize; //원래 스택을 사이즈가 줄어들지 

}


void build_stack_blue(int x, int y, int j) {
	int direc = pos[j].dir;
	int post_x; int post_y;
	int currentsize = 0;
	bool isitblue = false; //다음방향으로갈때 색깔이  파랑이니?
	if (direc == 1) { //> 일때 <로 
		pos[j].dir = 2;
		if (arr[y][x - 1].a == 2)
			isitblue = true;
		else
			post_x = x - 1, post_y = y;
	}

	else if (direc == 2) {
		pos[j].dir = 1;
		if (arr[y][x + 1].a == 2)
			isitblue = true;
		else
			post_x = x + 1, post_y = y;
	}
	else if (direc == 3) {
		pos[j].dir = 4;
		if (arr[y + 1][x].a == 2)
			isitblue = true;
		else
			post_x = x , post_y = y + 1;
	}
	else if (direc == 4) {
		pos[j].dir = 3;
		if (arr[y - 1][x].a == 2)
			isitblue = true;
		else
			post_x = x, post_y = y - 1;
	}
	if (isitblue == true)
		return;


	for (int i = 0; i < arr[y][x].sized; i++)
		if (arr[y][x].stack[i] == j + 1) {
			currentsize = i; //스택에 있는 위치를 기억합니다. 
		}

	for (int k = currentsize; k < arr[y][x].sized; k++) {//스택위치부터 그위에것들을 쌓아주려고 
		arr[post_y][post_x].stack[arr[post_y][post_x].sized++] = arr[y][x].stack[k]; //넣어주면서 size를증가
		arr[y][x].stack[k] = 0;
		pos[arr[y][x].stack[k] - 1].x = post_x;
		pos[arr[y][x].stack[k] - 1].y = post_y;
	}
	arr[y][x].sized = currentsize; //원래 스택을 사이즈가 줄어들지 
	

}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j].a;

	for (int i = 0; i < k; i++) {
		cin >> pos[i].y >> pos[i].x >> pos[i].dir; //방향값까지 입력받고
		arr[pos[i].y][pos[i].x].stack[0] = i + 1 ; //1부터 해당 스택에 값을 넣어주는 행위 
		arr[pos[i].y][pos[i].x].sized++; //사이즈를 올려주는 행위 
	}

	for (int i = 0; i <= n + 1; i++) { //테두리를 파랑색으로 만들주고 
		arr[0][i].a = 2, arr[n + 1][i].a = 2;
		arr[i][0].a = 2, arr[i][n + 1].a = 2;
	}
	
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 0; j < k; j++) { //k번 반복할거야 j+1 이 번호를 의미합니다.
			int x = pos[j].x, y = pos[j].y; //좌표를 받아온다 
			if (pos[j].dir == 1 &&arr[y][x].sized>0) { //->방향일때
				if (arr[y][ x + 1].a == 0 && (x + 1) <= n) //이동하려는곳이 흰색일때
					build_stack_white(x, y, x + 1, y, j);  //스택을 옮기고 뒤로 다시 붙이는행위 
				else if (arr[y][ x + 1].a = 1 && (x + 1) <= n) //빨간색일때
					build_stack_red(x, y, x + 1, y, j);
				else
					build_stack_blue(x, y, j);

			}
			else if (pos[j].dir == 2 && arr[y][x].sized>0) {//<-방향일때
				if (arr[y][x - 1].a == 0 && (x - 1) >= 1) //이동하려는 곳이 흰색일때
					build_stack_white(x, y, x - 1, y, j);
				else if (arr[y][x - 1].a == 1 && (x - 1) >= 1)
					build_stack_red(x, y, x - 1, y, j);
				else
					build_stack_blue(x, y, j);
			}
			else if (pos[j].dir == 3 && arr[y][x].sized>0) { // ^방향일때
				if (arr[y - 1][x].a == 0 && (y - 1) >= 1) //이동하려는 곳이 흰색일때
					build_stack_white(x, y, x, y - 1, j);
				else if (arr[y - 1][x].a == 1 && (y - 1) >= 1)
					build_stack_red(x, y, x, y - 1, j);
				else
					build_stack_blue(x, y, j);
			}
			else if(pos[j].dir == 4 && arr[y][x].sized>0) {  //아래방향일때 
				if (arr[y + 1][x].a == 0 && (y + 1) <= n) //이동하려는 곳이 흰색일때
					build_stack_white(x, y, x, y + 1, j);
				else if (arr[y + 1][x].a == 1 && (y + 1) <= n) 
					build_stack_red(x, y, x, y + 1, j);
				else
					build_stack_blue(x, y, j);
			}


		}
		

		for (int k = 1; k <= n; k++)
			for (int m = 1; m <= n; m++)
				if (arr[k][m].sized >= 4) {
					cout << i << endl;
					return 0;
				}
		// 이동을 끝낸후 말이 4개 이상 쌓였는지 검사 해주는 단계 
	}

	cout << -1 << endl;
	return 0;
}