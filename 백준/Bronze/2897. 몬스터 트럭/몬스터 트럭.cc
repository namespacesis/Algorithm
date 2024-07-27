#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int R, C;
char arr[50][50];
int dx[4] = { 0, 0, 1, 1 };
int dy[4] = { 0, 1, 1, 0 };

int main(void) {
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    int res[5] = {0};

    for (int i = 0; i < R - 1; i++) {
        for (int j = 0; j < C - 1; j++) {
            int cnt = 0;

            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (arr[nx][ny] == '#') {
                    cnt = -1;
                    break;
				}
                else if (arr[nx][ny] == 'X') {
					cnt++;
				}
            }
            
            if (cnt != -1) {
                res[cnt]++;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        printf("%d\n", res[i]);
    }

    return 0;
}
