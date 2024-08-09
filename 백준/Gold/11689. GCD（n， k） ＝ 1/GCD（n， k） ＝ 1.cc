#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long N;

int main(void) {
	scanf("%lld", &N);

	long long res = N;

	for (long long i = 2; i * i <= N; i++) {
		if (N % i == 0) {
			res -= res / i;
			while (N % i == 0) {
				N /= i;
			}
		}
	}

	if (N > 1) {
		res -= res / N;
	}

	printf("%lld\n", res);

	return 0;
}
