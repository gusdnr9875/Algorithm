#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct info {
	string name;
	int korean;
	int english;
	int math;
};

info arr[100001];
int n = 0;

/*
���� ������ �����ϴ� ������
���� ������ ������ ���� ������ �����ϴ� ������
���� ������ ���� ������ ������ ���� ������ �����ϴ� ������
��� ������ ������ �̸��� ���� ������ �����ϴ� ������ (��, �ƽ�Ű �ڵ忡�� �빮�ڴ� �ҹ��ں��� �����Ƿ� ���������� �տ� �´�.)
*/
bool cmp(info a, info b) {
	if (a.korean > b.korean)  //1
		return true;
	else if(a.korean == b.korean){
		if (a.english < b.english) return true; //2
		else if(a.english == b.english){
			if (a.math > b.math) return true; //3
			else if(a.math == b.math) {
				if (a.name < b.name)return true; //4
			}
		}
	}

	return false;
}
int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i].name >> arr[i].korean >> arr[i].english >> arr[i].math;

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
		cout << arr[i].name <<'\n';

}