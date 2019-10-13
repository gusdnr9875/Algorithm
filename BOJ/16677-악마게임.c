#include <stdio.h>
typedef struct dict {
	char name[101];
	int g;
};
struct dict arr[100];
char m[101];
int n = 0;
char temp[101];
int temp1 = 0;
double resultval = -1;
int result = -1;

int main() {
	scanf("%s", m);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i].name);
		scanf("%d", &arr[i].g);
	}

	for (int i = 0; i < n; i++) {// 매번 가중치값이 얼마인지 확인할거자나
		int jud = 0;
		int wordcur = 0, other = 0;
		for (int j = 0; arr[i].name[j]; j++) {
			if (m[wordcur] == arr[i].name[j])
				wordcur++;
			else
				other++;
			if (m[wordcur] == NULL)
				jud = 1;

		}
		if (jud == 1) {
			double val = (double)arr[i].g / other;
			if (resultval < val) resultval = val, result = i;
		}
	}

	if (result == -1)
		printf("No Jam\n");
	else
		printf("%s\n", arr[result].name);

	return 0;
}