#include <iostream>
using namespace std;

typedef struct pos {
	int x;
	int y;
	int dir; //���Ⱚ�� ����

}posit;
typedef struct ar {
	int a;
	int stack[10];
	int sized; //������ ����� 

}ar;

int n = 0, k = 0;
posit pos[10];
ar arr[14][14]= { 0 };
int stack[14][14][10];


void build_stack_white(int x, int y, int post_x, int post_y, int j) {
	
	int currentsize = 0;
	for (int i = 0; i < arr[y][x].sized; i++)
		if (arr[y][x].stack[i] == j + 1) {
			currentsize = i; //���ÿ� �ִ� ��ġ�� ����մϴ�. 
		}

	for (int k = currentsize; k < arr[y][x].sized; k++) {//������ġ���� �������͵��� �׾��ַ��� 
		arr[post_y][post_x].stack[arr[post_y][post_x].sized++] = arr[y][x].stack[k]; //�־��ָ鼭 size������
		arr[y][x].stack[k] = 0;
		int asd = arr[y][x].stack[k] - 1;
		pos[asd].x = post_x, pos[asd].y = post_y;
		cout << n << endl;
	
		cout << post_y << endl;
	}
	arr[y][x].sized = currentsize; //���� ������ ����� �پ���� 

}

void build_stack_red(int x, int y, int post_x, int post_y, int j) {

	int currentsize = 0, len = arr[y][x].sized;
	for (int i = 0; i < arr[y][x].sized; i++)
		if (arr[y][x].stack[i] == j + 1) {
			currentsize = i; //���ÿ� �ִ� ��ġ�� ����մϴ�. 
		}

	for (int k = currentsize; k < arr[y][x].sized; k++) {//������ġ���� �������͵��� �׾��ַ��� 
		arr[post_y][post_x].stack[arr[post_y][post_x].sized++] = arr[y][x].stack[len-k-1]; //�־��ָ鼭 size������
		arr[y][x].stack[len - k - 1] = 0;
		pos[arr[y][x].stack[k] - 1].x = post_x;
		pos[arr[y][x].stack[k] - 1].y = post_y;
	}
	arr[y][x].sized = currentsize; //���� ������ ����� �پ���� 

}


void build_stack_blue(int x, int y, int j) {
	int direc = pos[j].dir;
	int post_x; int post_y;
	int currentsize = 0;
	bool isitblue = false; //�����������ΰ��� ������  �Ķ��̴�?
	if (direc == 1) { //> �϶� <�� 
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
			currentsize = i; //���ÿ� �ִ� ��ġ�� ����մϴ�. 
		}

	for (int k = currentsize; k < arr[y][x].sized; k++) {//������ġ���� �������͵��� �׾��ַ��� 
		arr[post_y][post_x].stack[arr[post_y][post_x].sized++] = arr[y][x].stack[k]; //�־��ָ鼭 size������
		arr[y][x].stack[k] = 0;
		pos[arr[y][x].stack[k] - 1].x = post_x;
		pos[arr[y][x].stack[k] - 1].y = post_y;
	}
	arr[y][x].sized = currentsize; //���� ������ ����� �پ���� 
	

}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j].a;

	for (int i = 0; i < k; i++) {
		cin >> pos[i].y >> pos[i].x >> pos[i].dir; //���Ⱚ���� �Է¹ް�
		arr[pos[i].y][pos[i].x].stack[0] = i + 1 ; //1���� �ش� ���ÿ� ���� �־��ִ� ���� 
		arr[pos[i].y][pos[i].x].sized++; //����� �÷��ִ� ���� 
	}

	for (int i = 0; i <= n + 1; i++) { //�׵θ��� �Ķ������� �����ְ� 
		arr[0][i].a = 2, arr[n + 1][i].a = 2;
		arr[i][0].a = 2, arr[i][n + 1].a = 2;
	}
	
	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 0; j < k; j++) { //k�� �ݺ��Ұž� j+1 �� ��ȣ�� �ǹ��մϴ�.
			int x = pos[j].x, y = pos[j].y; //��ǥ�� �޾ƿ´� 
			if (pos[j].dir == 1 &&arr[y][x].sized>0) { //->�����϶�
				if (arr[y][ x + 1].a == 0 && (x + 1) <= n) //�̵��Ϸ��°��� ����϶�
					build_stack_white(x, y, x + 1, y, j);  //������ �ű�� �ڷ� �ٽ� ���̴����� 
				else if (arr[y][ x + 1].a = 1 && (x + 1) <= n) //�������϶�
					build_stack_red(x, y, x + 1, y, j);
				else
					build_stack_blue(x, y, j);

			}
			else if (pos[j].dir == 2 && arr[y][x].sized>0) {//<-�����϶�
				if (arr[y][x - 1].a == 0 && (x - 1) >= 1) //�̵��Ϸ��� ���� ����϶�
					build_stack_white(x, y, x - 1, y, j);
				else if (arr[y][x - 1].a == 1 && (x - 1) >= 1)
					build_stack_red(x, y, x - 1, y, j);
				else
					build_stack_blue(x, y, j);
			}
			else if (pos[j].dir == 3 && arr[y][x].sized>0) { // ^�����϶�
				if (arr[y - 1][x].a == 0 && (y - 1) >= 1) //�̵��Ϸ��� ���� ����϶�
					build_stack_white(x, y, x, y - 1, j);
				else if (arr[y - 1][x].a == 1 && (y - 1) >= 1)
					build_stack_red(x, y, x, y - 1, j);
				else
					build_stack_blue(x, y, j);
			}
			else if(pos[j].dir == 4 && arr[y][x].sized>0) {  //�Ʒ������϶� 
				if (arr[y + 1][x].a == 0 && (y + 1) <= n) //�̵��Ϸ��� ���� ����϶�
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
		// �̵��� ������ ���� 4�� �̻� �׿����� �˻� ���ִ� �ܰ� 
	}

	cout << -1 << endl;
	return 0;
}