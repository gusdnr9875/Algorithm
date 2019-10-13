#include <stdio.h>

int n = 0, min_age = 0, max_age = 201;

int age[100001] = { 0 };
char name[100001][101];


int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %s", &age[i],name[i]);
		
		if (min_age > age[i]) min_age = age[i];
		if (max_age < age[i]) max_age = age[i];
	}
	
	for (int i = min_age; i < max_age; i++) {
		for (int j = 0; j < n; j++) {
			if (i != age[j]) continue;
			printf("%d %s\n", age[j], name[j]);
		}

	}
	
}