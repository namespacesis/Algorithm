#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int dp[4001][4001];

int main() {
    FastIO;

    string s1, s2;

    cin >> s1 >> s2;

    int res = 0;

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                res = max(res, dp[i][j]);
            }
        }
    }

    cout << res << "\n";

    return 0;
}