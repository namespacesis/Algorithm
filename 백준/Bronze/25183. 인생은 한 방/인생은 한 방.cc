#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) a > b ? a : b

int N;
char str[100000];

int main(void) {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %c", &str[i]);
	}

	int cnt = 1;
	int res = 0;

	for (int i = 1; i < N; i++) {
		if (str[i] == str[i - 1] + 1 || str[i] == str[i - 1] - 1) {
			cnt++;
			res = max(res, cnt);
		}
		else {
			cnt = 1;
		}
	}

	res >= 5 ? printf("YES") : printf("NO");

	return 0;
}
