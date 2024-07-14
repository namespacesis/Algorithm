#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
    int m, seed, x1, x2;
    int a = 0, c = 0, temp;

    scanf("%d %d %d %d", &m, &seed, &x1, &x2);

    for (a = 0; a < m; a++)
    {
        for (c = 0; c < m; c++)
        {
            if ((a * seed + c) % m == x1)
            {
                if ((a * x1 + c) % m == x2)
                {
                    printf("%d %d", a, c);
                    return 0;
                }
            }
        }
    }

    return 0;
}
