#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int T;

int main(void) {
    scanf("%d", &T);

    int res = 0;

    for (int i = 0; i < 5; i++) {
        int n;
        scanf("%d", &n);

        if (n == T) res++;
    }

    printf("%d\n", res);

    return 0;
}
