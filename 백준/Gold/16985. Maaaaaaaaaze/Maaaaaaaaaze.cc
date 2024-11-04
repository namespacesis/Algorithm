#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x;
    int y;
    int z;
    int cnt;
};

int map[5][5][5];
int arr[5][5][5];
int arrTemp[5][5][5];
bool visited[5][5][5];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dz[2] = {1, -1};
int res = 1e9;

void rotate(int idx) {
    int temp[5][5];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			temp[i][j] = arr[idx][i][j];
		}
	}
    for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[idx][i][j] = temp[5 - j - 1][i];
		}
	}
}

void bfs() {
    queue<Node> q;
    if (arr[0][0][0] == 0) {
        return;
    }
    q.push({0, 0, 0, 0});
    visited[0][0][0] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == 4 && cur.y == 4 && cur.z == 4) {
            res = min(res, cur.cnt);
        }

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

            if (arr[cur.z][nx][ny] == 1 && !visited[cur.z][nx][ny]) {
                visited[cur.z][nx][ny] = true;
                q.push({ nx, ny, cur.z, cur.cnt + 1 });
            }
        }

        for (int i = 0; i < 2; i++) {
            int nz = cur.z + dz[i];

            if (nz < 0 || nz >= 5) continue;

            if (arr[nz][cur.x][cur.y] == 1 && !visited[nz][cur.x][cur.y]) {
                visited[nz][cur.x][cur.y] = true;
                q.push({ cur.x, cur.y, nz, cur.cnt + 1 });
            }
        }
    }
}

void dfs2(string check, int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    arrTemp[i][j][k] = arr[i][j][k];
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < (check[i] - '0'); j++) {
                rotate(i);
            }
        }
        memset(visited, false, sizeof(visited));
        bfs();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    arr[i][j][k] = arrTemp[i][j][k];
                }
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        dfs2(check + to_string(i), cnt + 1);
    }
}

void dfs(string check, int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    arr[i][j][k] = map[check[i] - '0'][j][k];
                }
            }
        }
        dfs2("", 0);
        return;
    }

    for (int i = 0; i < 5; i++) {
        bool flag = false;
        for (int j = 0; j < check.size(); j++) {
            if ((check[j] - '0') == i) {
                flag = true;
                break;
            }
        }
        if (flag) continue;
        dfs(check + to_string(i), cnt + 1);
    }
}

int main() {
    FastIO;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                cin >> map[i][j][k];
            }
        }
    }

    dfs("", 0);

    if (res == 1e9) cout << -1 << "\n";
	else cout << res << "\n";

	return 0;
}
