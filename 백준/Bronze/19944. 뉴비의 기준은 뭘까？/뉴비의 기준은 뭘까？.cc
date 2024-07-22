#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M;
char *res;

int main(void) {
    scanf("%d %d", &N, &M);

    if (M == 1 || M == 2) {
        res = "NEWBIE!";
    }
    else if (M <= N) {
		res = "OLDBIE!";
	}
	else {
		res = "TLE!";
	}

	printf("%s", res);

	return 0;
}
