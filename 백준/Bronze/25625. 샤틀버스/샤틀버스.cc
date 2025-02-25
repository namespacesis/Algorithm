#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int x, y;

int main(void) {
    scanf("%d %d", &x, &y);

    int temp = y;

    int res = x + y;

    if (y >= x) {
        temp = y % x;
        res = temp;
    }

    printf("%d\n", res);

    return 0;
}
