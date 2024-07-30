#include<iostream>

using namespace std;

int N, M;
int arr[4][4];
int visited[4][4];
pair<int, int> goal[16];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int res;

void dfs(pair<int, int> cur, int nextIdx) {
    if (cur == goal[nextIdx]) {
        if (nextIdx == M - 1) {
            res++;
            return;
        }
        nextIdx++;
    }

    int x = cur.first;
    int y = cur.second;

    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < N && 0 <= ny && ny < N && !visited[nx][ny] && arr[nx][ny] == 0) {
            dfs({nx, ny}, nextIdx);
        }
    }
    visited[x][y] = false;
    return;
}

int main(int argc, char** argv)
{
    cin >> N >> M;

    int tmp = 1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        goal[i] = {x - 1, y - 1};
    }

    dfs(goal[0], 1);

    cout << res << "\n";
    
    return 0;
}