#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int N, K;
int dp[10001];
int arr[101];

void calc() {
    for (int i = 1; i <= N; i++) {
        if (arr[i] == arr[i - 1]) continue;

        if (arr[i] > K) break;

        for (int j = arr[i]; j <= K; j++) {
            dp[j] = min(dp[j], dp[j - arr[i]] + 1);
        }
    }
}

int main() {
    FastIO;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= K; i++) {
        dp[i] = 10001;
    }

    sort(arr + 1, arr + N + 1);

    calc();

    int res;
    res = dp[K] != 10001 ? dp[K] : -1;

    cout << res << endl;

    return 0;
}
