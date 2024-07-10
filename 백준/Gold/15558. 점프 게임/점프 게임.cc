#include <iostream>
#include <queue>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

int N, k;
int arr[2][100001];
bool visited[2][100001];

struct Node {
    int x, y, t;
};

bool bfs() {
    queue<Node> q;
    q.push({ 0, 0, 0 });
    visited[0][0] = true;

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        int cx = current.x;
        int cy = current.y;
        int ct = current.t;

        if (cy + 1 >= N || cy + k >= N) {
            return true;
        }

        if (cy + 1 < N && arr[cx][cy + 1] == 1 && !visited[cx][cy + 1]) {
            visited[cx][cy + 1] = true;
            q.push({ cx, cy + 1, ct + 1 });
        }
        if (cy - 1 > ct && arr[cx][cy - 1] == 1 && !visited[cx][cy - 1]) {
            visited[cx][cy - 1] = true;
            q.push({ cx, cy - 1, ct + 1 });
        }
        if (arr[1 - cx][cy + k] == 1 && !visited[1 - cx][cy + k]) {
            visited[1 - cx][cy + k] = true;
            q.push({ 1 - cx, cy + k, ct + 1 });
        }
    }

    return false;
}

int main() {
    FastIO;

    cin >> N >> k;
    for (int i = 0; i < 2; ++i) {
        string line;
        cin >> line;
        for (int j = 0; j < N; ++j) {
            arr[i][j] = line[j] - '0';
        }
    }

    if (bfs()) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }

    return 0;
}
