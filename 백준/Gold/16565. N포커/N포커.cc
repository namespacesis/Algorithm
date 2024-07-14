#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MOD 10007

int comb[53][53];

int main(void) {
    int i, j;

    for (i = 0; i <= 52; i++) comb[i][0] = 1;

    for (i = 1; i <= 52; i++) {
        for (j = 1; j <= 52; j++) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }
        
    int N, res = 0;

    scanf("%d", &N);

    for (i = 1; i <= 13 && N - 4 * i >= 0; i++) {
        if (i % 2 == 1) res = (res + comb[52 - 4 * i][N - 4 * i] * comb[13][i]) % MOD;
        else res = (res - (comb[52 - 4 * i][N - 4 * i] * comb[13][i]) % MOD + MOD) % MOD;
    }

    printf("%d\n", res);

    return 0;
}
