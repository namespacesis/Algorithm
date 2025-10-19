#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

string S;
int dp[5001];

int main() {
    FastIO;

    cin >> S;

    dp[0] = 1;
    
    for (int i = 1; i <= S.size(); i++) {
        int n = S[i - 1] - '0';
        if (n >= 1 && n <= 9) {
            dp[i] = dp[i - 1] % 1000000;
        }

        n = (S[i - 2]- '0') * 10 + (S[i - 1] - '0');
        if (n >= 10 && n <= 26) {
            dp[i] = (dp[i] + dp[i - 2]) % 1000000;
        }
    }

    cout << dp[S.size()] << endl;

    return 0;
}
