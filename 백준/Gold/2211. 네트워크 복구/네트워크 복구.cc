#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1e9

using namespace std;

struct Node {
    int dist, idx;
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

int N, M;
vector<pair<int, int>> graph[1001];
int d[1001];
int prevNode[1001];

void dijkstra(int start) {
    priority_queue<Node> pq;
    pq.push({ 0, start });

    d[start] = 0;

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int now = node.idx;
        int dist = node.dist;

        if (d[now] < dist) continue;

        for (auto& p : graph[now]) {
            int next = p.first;
            int nextDist = dist + p.second;

            if (nextDist < d[next]) {
                d[next] = nextDist;
                pq.push({ nextDist, next });
                prevNode[next] = now;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    fill(d, d + N + 1, INF);


    dijkstra(1);

    cout << N - 1 << "\n";

    for (int i = 2; i <= N; i++) {
        cout << prevNode[i] << " " << i << "\n";
    }

    return 0;
}
