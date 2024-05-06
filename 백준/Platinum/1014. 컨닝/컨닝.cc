#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int T, N, M, cache[10][1 << 10];
int m[10];

int solve(int r, int state) {
    if (r == N) return 0;

    int& ret = cache[r][state];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < (1 << M); j++) {
            if (j & m[r]) continue;
            bool sw = false;
            for (int k = 0; k < M; k++) {
                if (j & (1 << k)) {
                    if (k > 0 && j & (1 << (k - 1)) || k < M - 1 && j & (1 << (k + 1))) {
                        sw = true;
                        break;
                    }

                    if (k > 0 && state & (1 << (k - 1)) || k < M - 1 && state & (1 << (k + 1))) {
                        sw = true;
                        break;
                    }
                }
            }
            if (!sw) ret = max(ret, solve(r + 1, j) + __builtin_popcount(j));
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    while (T--) {
        cin >> N >> M;
        memset(m, 0, sizeof(m));
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                char x;
                cin >> x;
                if (x == 'x') m[i] |= (1 << j);
            }
        }
        cout << solve(0, 0) << "\n";
    }

    return 0;
}