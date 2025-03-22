#include <iostream>
#include <algorithm>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int N;
int arr[10][10];
bool visited[10][10];
int res = 1e9;

int dx[5] = { 0, 1, -1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

bool canPlant(int x, int y) {
    for (int i = 0; i < 5; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny]) {
            return false;
        }
    }
    return true;
}

int plant(int x, int y) {
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = true;
        sum += arr[nx][ny];
    }
    return sum;
}

void remove(int x, int y) {
    for (int i = 0; i < 5; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        visited[nx][ny] = false;
    }
}

void dfs(int cnt, int total) {
    if (cnt == 3) {
        res = min(res, total);
        return;
    }

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            if (canPlant(i, j)) {
                int cost = plant(i, j);
                dfs(cnt + 1, total + cost);
                remove(i, j);
            }
        }
    }
}

int main() {
    FastIO;

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> arr[i][j];

    dfs(0, 0);
    cout << res << endl;
    return 0;
}
