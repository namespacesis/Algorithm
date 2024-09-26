#include <iostream>
#include <vector>
#include <queue>
#include <set>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
vector<int> graph[100001];
bool visited[100001];

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    vector<int> order(N);
    for (int i = 0; i < N; i++) {
        cin >> order[i];
    }

    if (order[0] != 1) {
        cout << 0 << "\n";
        return 0;
    }

    queue<int> q;
    q.push(1);
    visited[1] = 1;

    int idx = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        set<int> nextNodes;
        for (int next : graph[cur]) {
            if (!visited[next]) {
                nextNodes.insert(next);
            }
        }

        for (int i = 0; i < nextNodes.size(); i++) {
            if (nextNodes.find(order[idx]) == nextNodes.end()) {
                cout << 0 << "\n";
                return 0;
            }

            visited[order[idx]] = true;
            q.push(order[idx]);
            idx++;
        }
    }

    cout << 1 << "\n";
    return 0;
}
