#include <iostream>
#include <queue>
#include <cstring>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x;
    int y;
};

int N, M, K;
int arr[20][20];
bool visited[20][20];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int rotateR[4] = { 2, 3, 1, 0 };
int rotateL[4] = { 3, 2, 0, 1 };
int dice[6] = { 1, 6, 2, 5, 3, 4 }; // 위, 아래, 앞, 뒤, 왼쪽, 오른쪽
int diceRotate[4][4] = {
    {0, 4, 1, 5},  // 동쪽 회전 (위 -> 왼쪽 -> 아래 -> 오른쪽)
    {0, 5, 1, 4},  // 서쪽 회전 (위 -> 오른쪽 -> 아래 -> 왼쪽)
    {0, 3, 1, 2},  // 남쪽 회전 (위 -> 뒤 -> 아래 -> 앞)
    {0, 2, 1, 3}   // 북쪽 회전 (위 -> 앞 -> 아래 -> 뒤)
};


int bfs(int x, int y) {
    int val = arr[x][y];
    queue<Node> q;
    q.push({ x, y });
    visited[x][y] = true;

    int ret = 0;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();
        
        ret++;

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            if (visited[nx][ny]) continue;

            if (arr[nx][ny] != val) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
    
    return ret;
}

int main() {
    FastIO;

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    int x = 0;
    int y = 0;
    int dir = 0;
    int res = 0;

    for (int i = 0; i < K; i++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
            if (dir % 2 == 0) {
                dir++;
            }
            else {
				dir--;
            }
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        int temp = dice[diceRotate[dir][0]];
        dice[diceRotate[dir][0]] = dice[diceRotate[dir][3]];
        dice[diceRotate[dir][3]] = dice[diceRotate[dir][2]];
        dice[diceRotate[dir][2]] = dice[diceRotate[dir][1]];
        dice[diceRotate[dir][1]] = temp;

        int cur = dice[1];
        x = nx;
        y = ny;

        memset(visited, false, sizeof(visited));
        res += arr[x][y] * bfs(x, y);

        if (cur > arr[x][y]) {
            dir = rotateR[dir];
        }
        else if (cur < arr[x][y]) {
            dir = rotateL[dir];
        }
    }

    cout << res << "\n";
    
    return 0;
}