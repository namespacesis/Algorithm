#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x, y;
};

int N, M;
int arr[20][20];
bool visited[20][20];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<pair<int, int>> v;

int bfs(int x, int y) {
    queue<Node> q;
    q.push({ x, y });
    visited[x][y] = true;
    
    int cnt = 0;
    bool flag = false;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny]) continue;

            if (arr[nx][ny] == 0) {
                flag = true;
                continue;
            }

            if (arr[nx][ny] == 2) {
				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
        }
    }

    if (flag) return 0;
    else return cnt;
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                v.push_back({ i, j });
            }
        }
    }

    int res = 0;
    int temp = 0;

    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = i + 1; j < v.size(); j++) {
            arr[v[i].first][v[i].second] = 1;
            arr[v[j].first][v[j].second] = 1;
            memset(visited, false, sizeof(visited));
            for (int k = 0; k < N; k++) {
				for (int l = 0; l < M; l++) {
					if (arr[k][l] == 2 && !visited[k][l]) {
						temp += bfs(k, l);
					}
				}
			}
			res = max(res, temp);
			temp = 0;
        	arr[v[i].first][v[i].second] = 0;
			arr[v[j].first][v[j].second] = 0;
        }
    }

    cout << res << "\n";

    return 0;
}
