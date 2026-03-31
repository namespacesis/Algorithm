#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int k;
int arr[5][8];
int rot[5];
vector<pair<int, int>> v;

void rotate(int n, int r) {
    rot[n] += r;
    rot[n] %= 8;
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

    int n, r;

    for (int i = 0; i < k; ++i) {

        for (auto c : v) {
            rotate(c.first, c.second);
        }
        v.clear();

        cin >> n >> r;

        if (n == 1) {
            v.push_back({1, r});

            if (arr[1][((2 - rot[1]) + 8) % 8] == arr[2][((6 - rot[2]) + 8) % 8]) continue;
            v.push_back({2, -r});

            if (arr[2][((2 - rot[2]) + 8) % 8] == arr[3][((6 - rot[3]) + 8) % 8]) continue;
            v.push_back({3, r});

            if (arr[3][((2 - rot[3]) + 8) % 8] == arr[4][((6 - rot[4]) + 8) % 8]) continue;
            v.push_back({4, -r});
        }
        else if (n == 2) {
            v.push_back({2, r});

            if (arr[2][((6 - rot[2]) + 8) % 8] != arr[1][((2 - rot[1]) + 8) % 8]) {
                v.push_back({1, -r});
            }

            if (arr[2][((2 - rot[2]) + 8) % 8] != arr[3][((6 - rot[3]) + 8) % 8]) {
                v.push_back({3, -r});
            }
            else continue;

            if (arr[3][((2 - rot[3]) + 8) % 8] == arr[4][((6 - rot[4]) + 8) % 8]) continue;
            v.push_back({4, r});
        }
        else if (n == 3) {
            v.push_back({3, r});
            
            if (arr[3][((2 - rot[3]) + 8) % 8] != arr[4][((6 - rot[4]) + 8) % 8]) {
                v.push_back({4, -r});
            }

            if (arr[3][((6 - rot[3]) + 8) % 8] != arr[2][((2 - rot[2]) + 8) % 8]) {
                v.push_back({2, -r});
            }
            else continue;

            if (arr[2][((6 - rot[2]) + 8) % 8] == arr[1][((2 - rot[1]) + 8) % 8]) continue;
            v.push_back({1, r});
        }
        else if (n == 4) {
            v.push_back({4, r});

            if (arr[3][((2 - rot[3]) + 8) % 8] == arr[4][((6 - rot[4]) + 8) % 8]) continue;
            v.push_back({3, -r});

            if (arr[2][((2 - rot[2]) + 8) % 8] == arr[3][((6 - rot[3]) + 8) % 8]) continue;
            v.push_back({2, r});

            if (arr[1][((2 - rot[1]) + 8) % 8] == arr[2][((6 - rot[2]) + 8) % 8]) continue;
            v.push_back({1, -r});
        }
    }

    for (auto c : v) {
        rotate(c.first, c.second);
    }

    int res = 0;

    res += arr[1][((0 - rot[1]) + 8) % 8];
    res += arr[2][((0 - rot[2]) + 8) % 8] * 2;
    res += arr[3][((0 - rot[3]) + 8) % 8] * 4;
    res += arr[4][((0 - rot[4]) + 8) % 8] * 8;
    
    cout << res << endl;

    return 0;
}