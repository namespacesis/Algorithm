#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int N, K;
int dp[201][201];
const int MOD = 1000000000;

int main() {
    FastIO;

    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= K; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
        }
    }

    cout << dp[K][N] << endl;

    return 0;
}
