#include <iostream>
#include <string>
#include <deque>
using namespace std;
deque <int> arr[4];
int k = 0, a = 0, b = 0;
int result = 0;


void one_c() {//��

	if (arr[0][2] != arr[1][6]) { // �ݴ�
		if (arr[1][2] != arr[2][6] ) { //��
			if (arr[2][2] != arr[3][6] ) {//�ݴ�
				int temp = arr[3].front(); //�ݴ� 
				arr[3].pop_front();
				arr[3].push_back(temp);
			}
			int temp = arr[2].back(); //������
			arr[2].pop_back();
			arr[2].push_front(temp);
		}
		int temp = arr[1].front(); //�ݴ� 
		arr[1].pop_front();
		arr[1].push_back(temp);

	}
	int temp = arr[0].back(); //������
	arr[0].pop_back();
	arr[0].push_front(temp);

}
void one_k() {//��

	if (arr[0][2] != arr[1][6]) { // ��
		if (arr[1][2] != arr[2][6]) { // ��
			if (arr[2][2] != arr[3][6]) {//��
				int temp = arr[3].back(); //�� 
				arr[3].pop_back();
				arr[3].push_front(temp);
			}
			int temp = arr[2].front(); //��
			arr[2].pop_front();
			arr[2].push_back(temp);
		}
		int temp = arr[1].back(); //��
		arr[1].pop_back();
		arr[1].push_front(temp);

	}
	int temp = arr[0].front(); //��
	arr[0].pop_front();
	arr[0].push_back(temp);
}

void two_c() { //��
	
	if (arr[0][2] != arr[1][6]) { //��
		int temp = arr[0].front(); //��
		arr[0].pop_front();
		arr[0].push_back(temp);
	}
	if (arr[1][2] != arr[2][6]) { //�� 
		if (arr[2][2] != arr[3][6]) {//��
			int temp = arr[3].back(); //�� 
			arr[3].pop_back();
			arr[3].push_front(temp);

		}
		int temp = arr[2].front(); //��
		arr[2].pop_front();
		arr[2].push_back(temp);
	}

	int temp = arr[1].back(); //��
	arr[1].pop_back();
	arr[1].push_front(temp);

}
void two_k() { //��
	if (arr[0][2] != arr[1][6]) { //��
		int temp = arr[0].back(); //��
		arr[0].pop_back();
		arr[0].push_front(temp);
	}
	if (arr[1][2] != arr[2][6]) { //�� 
		if (arr[2][2] != arr[3][6]) {//��
			int temp = arr[3].front(); //�� 
			arr[3].pop_front();
			arr[3].push_back(temp);

		}
		int temp = arr[2].back(); //��
		arr[2].pop_back();
		arr[2].push_front(temp);
	}

	int temp = arr[1].front(); //��
	arr[1].pop_front();
	arr[1].push_back(temp);
}
void three_c() { //��
	if (arr[2][2] != arr[3][6]) { //��
		int temp = arr[3].front(); //�� 
		arr[3].pop_front();
		arr[3].push_back(temp);
	}
	if (arr[1][2] != arr[2][6]) { //�� 
		if (arr[0][2] != arr[1][6]) { //�� 
			int temp = arr[0].back(); //��
			arr[0].pop_back();
			arr[0].push_front(temp);
		}
		int temp = arr[1].front(); //��
		arr[1].pop_front();
		arr[1].push_back(temp);
	}

	int temp = arr[2].back(); //��
	arr[2].pop_back();
	arr[2].push_front(temp);
}
void three_k() { //��
	if (arr[2][2] != arr[3][6]) { //��
		int temp = arr[3].back(); //�� 
		arr[3].pop_back();
		arr[3].push_front(temp);
	}
	if (arr[1][2] != arr[2][6]) { //�� 
		if (arr[0][2] != arr[1][6]) { //�� 
			int temp = arr[0].front(); //��
			arr[0].pop_front();
			arr[0].push_back(temp);
		}
		int temp = arr[1].back(); //��
		arr[1].pop_back();
		arr[1].push_front(temp);
	}

	int temp = arr[2].front(); //��
	arr[2].pop_front();
	arr[2].push_back(temp);
}

void four_c() { //��
	if (arr[2][2] != arr[3][6]) { // �ݴ�

		if (arr[1][2] != arr[2][6]) { //��
			if (arr[0][2] != arr[1][6]) {//�ݴ�
				int temp = arr[0].front(); //�ݴ� 
				arr[0].pop_front();
				arr[0].push_back(temp);
			}
			int temp = arr[1].back(); //������
			arr[1].pop_back();
			arr[1].push_front(temp);
		}

		int temp = arr[2].front(); //�ݴ� 
		arr[2].pop_front();
		arr[2].push_back(temp);

	}
	int temp = arr[3].back(); //������
	arr[3].pop_back();
	arr[3].push_front(temp);

}


void four_k() { //��
	if (arr[2][2] != arr[3][6]) { // ��
		if (arr[1][2] != arr[2][6]) { //��
			if (arr[0][2] != arr[1][6]) {//��
				int temp = arr[0].back(); //�� 
				arr[0].pop_back();
				arr[0].push_front(temp);
			}
			int temp = arr[1].front(); //��
			arr[1].pop_front();
			arr[1].push_back(temp);
		}
		int temp = arr[2].back(); //��
		arr[2].pop_back();
		arr[2].push_front(temp);

	}
	int temp = arr[3].front(); //��
	arr[3].pop_front();
	arr[3].push_back(temp);

}


int main() {

	for (int i = 0; i < 4; i++) {
		string num;
		cin >> num;
		for (int j = 0; j < 8; j++)
			arr[i].push_back(num[j]- '0');
	}
	cin >> k;

	while (k--) {
		cin >> a >> b;
		if (a == 1 && b == 1)
			one_c();
		else if (a == 1 && b == -1)
			one_k();
		else if (a == 2 && b == 1)
			two_c();
		else if (a == 2 && b == -1)
			two_k();
		else if (a == 3 && b == 1)
			three_c();
		else if (a == 3 && b == -1)
			three_k();
		else if (a == 4 && b == 1)
			four_c();
		else if (a == 4 && b == -1) 
			four_k();
		
	}
	if (arr[0].front() == 1)
		result += 1;
	if (arr[1].front() == 1)
		result += 2;
	if (arr[2].front() == 1)
		result += 4;	
	if (arr[3].front() == 1)
		result += 8;


	cout << result << endl;
	
}