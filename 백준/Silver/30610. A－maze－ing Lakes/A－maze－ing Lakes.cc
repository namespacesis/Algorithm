#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
int arr[1000][1000];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
vector<int> v;

int bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    arr[x][y] = 0;
    int cnt = 1;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (arr[nx][ny] == 0) continue;

            arr[nx][ny] = 0;
            cnt++;
            q.push({ nx, ny });
        }
    }

    return cnt;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    int res = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 1) {
                res++;
                int ret = bfs(i, j);
                v.push_back(ret);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << res << endl;

    if (v.size() > 0) {
        for (auto i : v) {
            cout << i << " ";
        }
    }

    return 0;
}