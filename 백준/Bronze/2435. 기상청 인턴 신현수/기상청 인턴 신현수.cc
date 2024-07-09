#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int N, K;
int arr[100];
int sum[100];

int main(void) {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + arr[i - 1];
	}

    int res = INT_MIN;

    for (int i = 0; i <= N - K; i++) {
        int temp = sum[i + K] - sum[i];
        if (temp > res) {
            res = temp;
        }
    }

	printf("%d\n", res);

    return 0;
}
