#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
char str[100000];

int main(void) {
	scanf("%d", &N);

	scanf("%s", str);

	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (str[i] == str[i - 1] + 1 || str[i] == str[i - 1] - 1) {
			cnt++;
            if (cnt == 5) {
                printf("YES");
                return 0;
            }
		}
		else {
			cnt = 1;
		}
	}

	printf("NO");

	return 0;
}
