#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;
ll dp[91];

int main() {
	FastIO;

    cin >> N;

    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N] << endl;

    return 0;
}