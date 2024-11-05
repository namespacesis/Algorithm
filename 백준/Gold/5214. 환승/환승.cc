#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Node {
    int x;
    int cnt;
};

int N, K, M;
vector<int> arr[100001];
bool visited[100001];
vector<int> hyperTube[1000];
bool visited2[1000];

int bfs() {
    queue<Node> q;
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.x == N) {
            return cur.cnt + 1;
        }

        for (int i = 0; i < arr[cur.x].size(); i++) {
            int tube = arr[cur.x][i];
            if (visited2[tube]) continue;
            visited2[tube] = true;
            for (int j = 0; j < hyperTube[tube].size(); j++) {
                int next = hyperTube[tube][j];
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({ next, cur.cnt + 1 });
                }
            }
        }
    }

    return -1;
}

int main() {
    FastIO;

    cin >> N >> K >> M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            hyperTube[i].push_back(x);
            arr[x].push_back(i);
        }
    }

    int res = bfs();

    cout << res << "\n";

    return 0;
}
