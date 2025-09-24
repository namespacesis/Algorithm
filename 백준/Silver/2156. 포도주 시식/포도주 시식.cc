#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int N;
int arr[10001];
int dp[10001];

int main() {
    FastIO;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int res = arr[1] + arr[2];

    if (N > 2) {
        dp[1] = arr[1];
        dp[2] = arr[1] + arr[2];

        for (int i = 3; i <= N; i++) {
            dp[i] = max(max(dp[i - 1], dp[i - 2] + arr[i]), dp[i - 3] + arr[i - 1] + arr[i]);
            res = max(res, dp[i]);
        }
    }

    cout << res << endl;

    return 0;
}