#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[50][2];

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]) {
				rank++;
			}
		}
		printf("%d ", rank);
	}

	return 0;
}
