#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
string S;
int dp[1510][1510];

int solve(int l, int r, char prev) {
    if (l > r) return 0;
    int& ret = dp[l][r];
    if (ret != -1) return ret;

    ret = 0;
    if ((S[l] == 'B' && (prev == ' ' || prev == 'D')) ||
        (S[l] == 'L' && prev == 'B') ||
        (S[l] == 'D' && prev == 'L')) {
        ret = max(ret, solve(l + 1, r, S[l]) + 1);
    }
    if ((S[r] == 'B' && (prev == ' ' || prev == 'D')) ||
        (S[r] == 'L' && prev == 'B') ||
        (S[r] == 'D' && prev == 'L')) {
        ret = max(ret, solve(l, r - 1, S[r]) + 1);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> S;

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 3 * N - 1, ' ') << "\n";
    return 0;
}
