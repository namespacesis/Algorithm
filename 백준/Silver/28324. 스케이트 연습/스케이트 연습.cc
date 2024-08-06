#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[500000];

int main(void) {
    scanf("%d", &N);

    for (int i = N - 1; i >= 0; i--) {
        scanf("%d", &arr[i]);
    }

    long long res = 1;

    int cnt = 1;

    for (int i = 1; i < N; i++) {
        if (cnt < arr[i]) {
            cnt++;
        }
        else {
            cnt = arr[i];
        }
        res += cnt;
    }

    printf("%lld\n", res);

    return 0;
}
