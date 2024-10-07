#include <iostream>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int N, M;
int arr[1000][1000];
int dp[1000][1000];
int l2r[1000];
int r2l[1000];

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    dp[0][0] = arr[0][0];

    for (int i = 1; i < M; i++) {
        dp[0][i] = dp[0][i - 1] + arr[0][i];
    }

    for (int i = 1; i < N; i++) {
        l2r[0] = dp[i - 1][0] + arr[i][0];
        for (int j = 1; j < M; j++) {
            l2r[j] = max(l2r[j - 1], dp[i - 1][j]) + arr[i][j];
        }

        r2l[M - 1] = dp[i - 1][M - 1] + arr[i][M - 1];
        for (int j = M - 2; j >= 0; j--) {
            r2l[j] = max(r2l[j + 1], dp[i - 1][j]) + arr[i][j];
        }

        for (int j = 0; j < M; j++) {
            dp[i][j] = max(l2r[j], r2l[j]);
        }
    }

    int res = dp[N - 1][M - 1];

    cout << res << "\n";

    return 0;
}
