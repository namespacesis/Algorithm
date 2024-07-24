#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
long long res;

int main(void) {
    scanf("%d %d", &N, &M);

	long long A = 0, B = 1;
	int temp;

	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		A += temp;
	}

	for (int j = 0; j < M; j++) {
		scanf("%d", &temp);
		if (temp != 0) {
			B *= temp;
		}
	}

	res = A * B;

	printf("%lld", res);

	return 0;
}
