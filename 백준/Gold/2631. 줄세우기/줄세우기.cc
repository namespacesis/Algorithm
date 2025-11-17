#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int N;
int arr[201];
int dp[201];

int main() {
	FastIO;

	cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    int L = 0;

    for (int i = 1; i <= N; i++) {
        dp[i] = 1;

        for (int j = 1; j <= i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }

        if (L < dp[i]) L = dp[i];
    }

    cout << N - L << endl;

    return 0;
}