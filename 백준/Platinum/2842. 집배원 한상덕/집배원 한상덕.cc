#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x, y;
    int maxH;
    int minH;
};

int N;
char arr[50][50];
int height[50][50];
bool visited[50][50];
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int sr, sc;
int totalCnt = 0;
vector<int> v;

bool bfs(int low, int high) {
    if (height[sr][sc] < low || height[sr][sc] > high) return false;

    memset(visited, false, sizeof(visited));
    queue<Node> q;
    q.push({ sr, sc, height[sr][sc], height[sr][sc] });
    visited[sr][sc] = true;
    int cnt = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;

            if (visited[nx][ny] || height[nx][ny] < low || height[nx][ny] > high) continue;

            if (arr[nx][ny] == 'K') {
                cnt++;
            }

            if (cnt == totalCnt) return true;

            visited[nx][ny] = true;
            q.push({ nx, ny, max(cur.maxH, height[nx][ny]), min(cur.minH, height[nx][ny]) });
        }
    }

    return false;
}

int main() {
    FastIO;

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 'P') {
                sr = i;
                sc = j;
            }
            else if (arr[i][j] == 'K') {
                totalCnt++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> height[i][j];
            v.push_back(height[i][j]);
        }
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int res = 1e9;
    int start = 0, end = 0;
    int len = v.size();

    while (end < len) {
        int low = v[start];
        int high = v[end];

        if (bfs(low, high)) {
            res = min(res, high - low);
            start++;
        }
        else {
            end++;
        }
    }

    cout << res << "\n";
    return 0;
}
