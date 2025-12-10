#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

const int MOD = 10007;
int N;
int dp[1001][10];

int main() {
	FastIO;

    cin >> N;

    for (int i = 0; i <= 9; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = j; k <= 9; ++k) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
            }
        }
    }

    int res = 0;

    for (int i = 0; i <= 9; ++i) {
        res = (res + dp[N][i]) % MOD;
    }

    cout << res << endl;

    return 0;
}