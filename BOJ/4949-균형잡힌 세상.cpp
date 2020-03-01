#include <iostream>
#include <string>
using namespace std;

string arr;

int main() {

	while (1) {
		int	stacked[100] = { 0 };
		bool jud = true;
		int small_bracket = 0, big_bracket = 0, stack_index = 0;
		
		getline(cin, arr);
		if (arr[0] == '.'&& arr.size()==1)
			break;

		for (int i = 0; i < arr.size(); i++) {
			/*
			if (arr[i] == '.')
				break;
				*/
			if (arr[i] == '(') {
				small_bracket++;
				stacked[stack_index++] = 1; // 1이 small 2가 big
			}
			else if (arr[i] == '[') {
				big_bracket++;
				stacked[stack_index++] = 2; // 1이 small 2가 big
			}
			else if (arr[i] == ')') {
				if (small_bracket < 0) {
					jud = false;
					break;
				}
				if (stacked[stack_index-1] != 1) {
					jud = false;
					break;
				}
				else 
					stacked[--stack_index] = 0,small_bracket--;

			}

			else if (arr[i] == ']') {
				if (big_bracket < 0) {
					jud = false;
					break;
				}
				if (stacked[stack_index - 1] != 2) {
					jud = false;
					break;
				}
				else
					stacked[--stack_index] = 0, big_bracket--;

			}

		}

		if (small_bracket != 0 || big_bracket != 0)
			jud = false;

		if (jud == false)
			cout << "no" << endl;
		else
			cout << "yes" << endl;

	}
}