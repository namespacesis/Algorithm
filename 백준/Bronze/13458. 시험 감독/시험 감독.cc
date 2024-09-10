#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[1000000];
int B, C;

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &B, &C);

    long long res = 0;

    for (int i = 0; i < N; i++) {
		arr[i] -= B;
		res++;
		if (arr[i] > 0) {
			res += arr[i] / C;
			if (arr[i] % C != 0) {
				res++;
			}
		}
	}

	printf("%lld\n", res);

	return 0;
}
