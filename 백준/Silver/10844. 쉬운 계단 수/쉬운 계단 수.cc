#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

const int MOD = 1000000000;
int N;
int dp[101][10];

int main() {
	FastIO;

    cin >> N;

    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }

    int res = 0;

    for (int i = 0; i <= 9; i++) {
        res = (res + dp[N][i]) % MOD;
    }

    cout << res << endl;

    return 0;
}