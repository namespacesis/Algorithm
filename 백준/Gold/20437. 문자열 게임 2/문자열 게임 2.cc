#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

int T;
vector<int> arr[26];

int main() {
    FastIO;

    cin >> T;

    while (T--) {
        string W;
        cin >> W;

        int K;
        cin >> K;

        int res1 = 1e9;
        int res2 = 0;

        for (int i = 0; i < 26; i++) arr[i].clear();
        for (int i = 0; i < W.size(); i++) {
            int idx = W[i] - 'a';
            arr[idx].push_back(i);
        }

        for (int i = 0; i < 26; i++) {
            int vLen = arr[i].size();
            if (vLen < K) continue;

            for (int j = 0; j <= vLen - K; j++) {
                res1 = min(res1, arr[i][j + K - 1] - arr[i][j] + 1);
                res2 = max(res2, arr[i][j + K - 1] - arr[i][j] + 1);
            }
        }

        if (res1 == 1e9 || res2 == 0) cout << -1 << "\n";
        else cout << res1 << " " << res2 << "\n";
    }

    return 0;
}