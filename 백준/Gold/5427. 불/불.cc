#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int T;
int w, h;
int arr[1000][1000];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> lst;

void spreadFire() {
    vector<pair<int, int>> newFires;
    for (auto& p : lst) {
        int fx = p.first, fy = p.second;
        for (int i = 0; i < 4; ++i) {
            int nfx = fx + dx[i], nfy = fy + dy[i];
            if (0 <= nfx && nfx < h && 0 <= nfy && nfy < w && arr[nfx][nfy] == 0) {
                arr[nfx][nfy] = -1;
                newFires.push_back({ nfx, nfy });
            }
        }
    }
    lst = newFires;
}

int bfs(int x, int y) {
    queue<tuple<int, int>> q;
    q.push({ x, y });

    int cnt = 0;

    while (!q.empty()) {
        cnt++;
        int size = q.size();
        spreadFire();
        while (size--) {
            int cx, cy;
            tie(cx, cy) = q.front();
            q.pop();

            if (cx == 0 || cy == 0 || cx == h - 1 || cy == w - 1) return cnt;

            for (int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];

                if (0 <= nx && nx < h && 0 <= ny && ny < w) {
                    if (arr[nx][ny] == 0) {
                        arr[nx][ny] = 2;
                        q.push({ nx, ny });
                    }
                }
            }
        }
    }
    return -1;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        lst.clear();

        cin >> w >> h;

        char t;
        int si, sj;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> t;
                if (t == '#') arr[i][j] = 1;
                else if (t == '.') {
                    arr[i][j] = 0;
                }
                else if (t == '@') {
                    arr[i][j] = 2;
                    si = i;
                    sj = j;
                }
                else if (t == '*') {
                    arr[i][j] = -1;
                    lst.push_back({ i, j });
                }
            }
        }
        int res;
        res = bfs(si, sj);

        if (res != -1) {
            cout << res << "\n";
        }
        else cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}