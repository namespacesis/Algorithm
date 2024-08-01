#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define min(x, y) ((x) < (y) ? (x) : (y))

int N;
int arr[10000];
int arr2[10000];
int arr3[10000];

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i < N; i++) {
        arr2[i] = min(arr[i], arr[i - 1]);
        arr[i] -= arr2[i];
        arr[i - 1] -= arr2[i];

        arr3[i] = min(arr[i], arr2[i - 1]);
        arr[i] -= arr3[i];
        arr2[i - 1] -= arr3[i];
    }

    int res = 0;

    for (int i = 0; i < N; i++) {
        res += arr[i] * 3 + arr2[i] * 5 + arr3[i] * 7;
    }

    printf("%d", res);

    return 0;
}
