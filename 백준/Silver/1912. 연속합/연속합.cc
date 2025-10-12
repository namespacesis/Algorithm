#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int N;
int arr[100000];
int dp[100000];

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    dp[0] = arr[0];

    int res = dp[0];

    for (int i = 1; i < N; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        res = max(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}