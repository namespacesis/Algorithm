#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))

long long N;
int B, C;
long long arr[1000000];
long long arr2[1000000];
long long arr3[1000000];

int main(void) {
    scanf("%d %d %d", &N, &B, &C);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    if (B > C) {
        for (int i = 1; i < N; i++) {

            arr2[i] = min(arr[i], arr[i - 1]);
            arr[i] -= arr2[i];
            arr[i - 1] -= arr2[i];

            arr3[i] = min(arr[i], arr2[i - 1]);
            arr[i] -= arr3[i];
            arr2[i - 1] -= arr3[i];
        }
    }
    
    long long res = 0;

    for (int i = 0; i < N; i++) {
        res += arr[i] * B + arr2[i] * (B + C) + arr3[i] * (B + 2 * C);
    }

    printf("%lld", res);

    return 0;
}
