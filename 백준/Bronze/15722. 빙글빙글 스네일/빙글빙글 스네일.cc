#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main() {
    FastIO;

    int n;
    
    cin >> n;

    int x = 0;
    int y = 0;
    int d = 0;
    int p = 1;
    int cnt = 2;
    int dir = 0;

    for (int i = 0; i < n; i++) {
        x += dx[dir];
        y += dy[dir];
        d++;
        if (d == p) {
            dir += 1;
            cnt--;
            d = 0;
        }
        if (dir == 4) dir = 0;
        if (cnt == 0) {
            cnt = 2;
            p++;
        }
    }

    cout << x << " " << y << endl;

    return 0;
}