#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

int arr[10][10];
int paper[6] = { 0, 0, 0, 0, 0, 0 };
int res = INT_MAX;

int check(int x, int y, int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (!arr[x + i][y + j]) {
                return 0;
            }
        }
    }
    return 1;
}

void change(int x, int y, int k, int val) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            arr[x + i][y + j] = val;
        }
    }
}

void dfs(int x, int y, int cnt) {
    if (cnt >= res) return;

    if (x == 10) {
        if (cnt < res) res = cnt;
        return;
    }

    if (y == 10) {
        dfs(x + 1, 0, cnt);
        return;
    }

    if (arr[x][y] == 0) {
        dfs(x, y + 1, cnt);
        return;
    }

    for (int k = 5; k >= 1; k--) {
        if (paper[k] == 5 || x + k > 10 || y + k > 10 || !check(x, y, k)) {
            continue;
        }

        change(x, y, k, 0);
        paper[k]++;
        dfs(x, y + k, cnt + 1);
        change(x, y, k, 1);
        paper[k]--;
    }
}

int main(void) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    dfs(0, 0, 0);

    if (res == INT_MAX) {
        printf("-1\n");
    }
    else {
        printf("%d\n", res);
    }

    return 0;
}
