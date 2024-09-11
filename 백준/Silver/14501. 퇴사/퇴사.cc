#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int arr[15][2];
int res = 0;

void dfs(int idx, int sum) {
    if (idx > N) return;

    if (idx == N) {
		if (res < sum) res = sum;
		return;
	}

    dfs(idx + arr[idx][0], sum + arr[idx][1]);
	dfs(idx + 1, sum);
}

int main(void) {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
    }

    dfs(0, 0);

    printf("%d\n", res);

    return 0;
}
