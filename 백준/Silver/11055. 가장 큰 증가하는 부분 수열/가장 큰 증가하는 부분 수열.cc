#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;
int arr[1001];
int dp[1001];

int main() {
	FastIO;

    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    for (int i = 1; i <= N; ++i) {
        dp[i] = arr[i];
        for (int j = 1; j < i; ++j) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= N; ++i) {
        res = max(res, dp[i]);
    }

    cout << res << endl;

    return 0;
}