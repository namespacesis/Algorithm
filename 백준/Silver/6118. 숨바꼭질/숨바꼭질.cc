#include <iostream>
#include <vector>
#include <queue>
#define fastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define MAXN 20001

using namespace std;

int N, M;
vector<int> arr[MAXN];
bool visited[MAXN];
int dist[MAXN];

void bfs() {
    queue<int> q;
    q.push({ 1 });
    visited[1] = true;
    dist[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : arr[cur]) {
            if (!visited[next]) {
                q.push({ next });
                visited[next] = true;
                dist[next] = dist[cur] + 1;
            }
        }
    }
}

int main() {
    fastIO;

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int Ai, Bi;
        cin >> Ai >> Bi;
        arr[Ai].push_back(Bi);
        arr[Bi].push_back(Ai);
    }

    bfs();

    int res2 = 0;

    for (int i = 1; i <= N; i++) {
        res2 = max(res2, dist[i]);
    }

    int res1 = 0;
    int res3 = 0;
    bool check = false;

    for (int i = 1; i <= N; i++) {
        if (res2 == dist[i]) {
            if (!check) check = true, res1 = i;
            res3++;
        }
    }

    cout << res1 << " " << res2 << " " << res3 << "\n";
    return 0;
}
