#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define MAXN 1001

using namespace std;

int N, M;
vector<pair<int, int>> arr[MAXN];
bool visited[MAXN];

int bfs(int a, int b) {
    queue<pair<int, int>> q;
    q.push({ a, 0 });
    visited[a] = true;

    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();

        if (cur.first == b) {
            return cur.second;
        }

        for (pair<int, int> next : arr[cur.first]) {
            if (!visited[next.first]) {
                visited[next.first] = true;
                q.push({ next.first, cur.second + next.second });
            }
        }
    }
}

int main() {
    fastIO;

    cin >> N >> M;

    for (int i = 0; i < N - 1; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        arr[a].push_back({ b, d });
        arr[b].push_back({ a, d });
    }

    for (int i = 0; i < M; i++) {
        int na, nb;
        cin >> na >> nb;

        memset(visited, 0, sizeof(visited));
        cout << bfs(na, nb) << "\n";
    }
    return 0;
}
