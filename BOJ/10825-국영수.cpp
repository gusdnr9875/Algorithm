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
국어 점수가 감소하는 순서로
국어 점수가 같으면 영어 점수가 증가하는 순서로
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
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