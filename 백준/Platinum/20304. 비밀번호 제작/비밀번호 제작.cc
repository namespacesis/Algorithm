#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
int arr[100000];
int dist[1000001];
int k;

int bfs() {
    queue<int> q;

    int ret = 0;
    
    for (int i = 0; i < M; i++) {
        q.push({arr[i]});
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        ret = max(ret, dist[cur]);

        for (int i = 0; i < k; i++) {
            int next = cur ^ (1 << i);

            if (next > N) continue;

            if (dist[cur] + 1 < dist[next]) {
                dist[next] = dist[cur] + 1;
                q.push({next});
            }
        }
    }

    return ret;
}

int main() {
	FastIO;

    cin >> N >> M;

    k = log2(N) + 1;

    for (int i = 0; i <= N; i++) {
        dist[i] = 1e9;
    }

    for (int i = 0; i < M; i++) {
        cin >> arr[i];
        dist[arr[i]] = 0;
    }

    int res = bfs();

    cout << res << endl;

    return 0;
}