#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N, K;
int arr[100][10];
bool visited[100][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    int num = arr[x][y];
    int cnt = 1;
    vector<pair<int, int>> v;
    v.push_back({ x, y });

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= 10) continue;
            if (arr[nx][ny] == num && !visited[nx][ny]) {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                v.push_back({ nx, ny });
                cnt++;
            }
        }
    }

    if (cnt >= K) {
        for (auto p : v) {
            arr[p.first][p.second] = 0;
        }
    }
}

int main() {
    FastIO;

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 10; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    bool flag = false;

    while (true) {
        flag = false;
        memset(visited, false, sizeof(visited));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 10; j++) {
                if (arr[i][j] != 0 && !visited[i][j]) {
                    bfs(i, j);
                    if (arr[i][j] == 0) {
                        flag = true;
                    }
                }
            }
        }

        if (!flag) break;

        for (int i = 0; i < 10; i++) {
			for (int j = N - 1; j >= 0; j--) {
				if (arr[j][i] == 0) {
					for (int k = j - 1; k >= 0; k--) {
						if (arr[k][i] != 0) {
							arr[j][i] = arr[k][i];
							arr[k][i] = 0;
							break;
						}
					}
				}
			}
		}
    }

    for (int i = 0; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}

    return 0;
}