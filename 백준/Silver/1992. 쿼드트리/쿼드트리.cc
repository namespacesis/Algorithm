#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

using namespace std;

int N;
char arr[64][64];
string res = "";

void divide(int x, int y, int s) {
    char v = arr[x][y];
    for (int i = x; i < x + s; i++) {
        for (int j = y; j < y + s; j++) {
            if (arr[i][j] != v) {
                res += "(";
                divide(x, y, s / 2);
                divide(x, y + s / 2, s / 2);
                divide(x + s /2, y, s / 2);
                divide(x + s / 2, y + s / 2, s / 2);
                res += ")";
                return;
            }
        }
    }

    res += v;
    return;
}

int main() {
    FastIO;

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    divide(0, 0, N);

    cout << res << endl;

    return 0;
}
