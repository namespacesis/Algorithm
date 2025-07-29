#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int N;
char arr[1000][1000];
int res[1000][1000];
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

void work(int a, int x, int y) {
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 > nx || N <= nx || 0 > ny || N <= ny) continue;

        if (res[nx][ny] == -1) continue;

        res[nx][ny] += a;
    }
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] != '.') {
                int a = arr[i][j] - '0';
                res[i][j] = -1;
                work(a, i, j);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (res[i][j] == -1) {
                cout << '*';
            }
            else if (res[i][j] >= 10) {
                cout << 'M';
            }
            else {
                cout << res[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}