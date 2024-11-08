#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);

using namespace std;

struct Edge {
    int next;
    int length;
};

struct Node {
    int next;
    int total_length;
    int max_length;
};

int N, S, E;
vector<Edge> arr[100001];
bool visited[100001];

int bfs() {
    queue<Node> q;
    q.push({S, 0, 0});
    visited[S] = true;

    while (!q.empty()) {
        Node cur = q.front();
        q.pop();

        if (cur.next == E) {
            return cur.total_length - cur.max_length;
        }

        for (Edge e : arr[cur.next]) {
            if (visited[e.next]) continue;

            visited[e.next] = true;
            q.push({ e.next, cur.total_length + e.length, max(cur.max_length, e.length) });
        }
    }
}

int main() {
    FastIO;

    cin >> N >> S >> E;

    for (int i = 0; i < N - 1; i++) {
        int s, e, l;
        cin >> s >> e >> l;
        arr[s].push_back({e, l});
        arr[e].push_back({s, l});
    }

    int res = bfs();

    cout << res << "\n";

    return 0;
}
