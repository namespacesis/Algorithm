#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

struct Node {
    int idx;
    int time;
    vector<pair<int, int>> arr;

    bool operator<(const Node n) const{
        return this->time > n.time;
    }
};

struct Node2 {
    int idx;
    int time;

    bool operator<(const Node2 n) const{
        return this->time > n.time;
    }
};

int N, M;
vector<pair<int, int>> adj[1001];
int visited[1001];
map<pair<int, int>, bool> um;

int makeHash(int a, int b) {
    return a * 10000 + b;
}

void dijkstra() {
    priority_queue<Node> pq;
    vector<pair<int, int>> tmp;
    pq.push({1, 0, tmp});
    visited[1] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.idx == N) {
            for (auto a: cur.arr) {
                um[{a.first, a.second}] = true;
            }
            return;
        }

        for (auto a : adj[cur.idx]) {
            if (visited[a.first] < cur.time + a.second) continue;
            
            int hash = makeHash(cur.idx, a.first);
            vector<pair<int, int>> newTmp = cur.arr;
            newTmp.push_back({hash, a.second});

            pq.push({a.first, cur.time + a.second, newTmp});
            visited[a.first] = cur.time + a.second;
        }
    }
}

int dijkstra2() {
    priority_queue<Node2> pq;
    pq.push({1, 0});
    visited[1] = 0;

    int ret = 1e9;

    while (!pq.empty()) {
        Node2 cur = pq.top();
        pq.pop();

        if (cur.idx == N) {
            ret = min(ret, cur.time);
        }

        for (auto a : adj[cur.idx]) {
            int hash = makeHash(cur.idx, a.first);

            if (um[{hash, a.second}] == true) continue;

            if (visited[a.first] < cur.time + a.second) continue;
            
            pq.push({a.first, cur.time + a.second});
            visited[a.first] = cur.time + a.second;
        }
    }

    return ret;
}

int main() {
	FastIO;

    cin >> N >> M;

    int a, b, c;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    for (int i = 1; i <= N; i++) {
        visited[i] = 1e9;
    }

    dijkstra();

    for (int i = 1; i <= N; i++) {
        visited[i] = 1e9;
    }

    int res = dijkstra2();

    cout << res << endl;

    return 0;
}