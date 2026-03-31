#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int k;
int arr[5][8];
int rot[5];
vector<pair<int, int>> v;

void rotate_gear(int n, int r) {
    rot[n] += r;
    rot[n] %= 8;
}

int get_val(int n, int idx) {
    return arr[n][((idx - rot[n]) + 8) % 8];
}

int main() {
    FastIO;

    for (int i = 1; i <= 4; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            arr[i][j] = s[j] - '0';
        }
    }

    cin >> k;
    while (k--) {
        int n, r;
        cin >> n >> r;

        v.clear();
        v.push_back({n, r});

        int curr_r = r;
        for (int i = n; i > 1; --i) {
            if (get_val(i, 6) != get_val(i - 1, 2)) {
                curr_r = -curr_r;
                v.push_back({i - 1, curr_r});
            } else break;
        }

        curr_r = r;
        for (int i = n; i < 4; ++i) {
            if (get_val(i, 2) != get_val(i + 1, 6)) {
                curr_r = -curr_r;
                v.push_back({i + 1, curr_r});
            } else break;
        }

        for (auto c : v) {
            rotate_gear(c.first, c.second);
        }
    }

    int res = 0;

    for (int i = 1; i <= 4; ++i) {
        if (get_val(i, 0) == 1) {
            res += (1 << (i - 1));
        }
    }
    
    cout << res << endl;

    return 0;
}