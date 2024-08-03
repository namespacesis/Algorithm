#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int A, B;
int K, X;

int main(void) {
    scanf("%d %d", &A, &B);
    scanf("%d %d", &K, &X);

    int res = 0;

    for (int i = K - X; i <= K + X; i++) {
        if (i < A || i > B) continue;
        res++;
    }

    res == 0 ? printf("IMPOSSIBLE\n") : printf("%d\n", res);

    return 0;
}
