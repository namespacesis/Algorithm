#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
vector<int> adj[1001];
int preCnt[1001];
queue<pair<int, int>> q;
int res[1001];

int main() {
	FastIO;

    cin >> N >> M;

    int A, B;

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        adj[A].push_back(B);
        preCnt[B]++;
    }

    for (int i = 1; i <= N; i++) {
        if (preCnt[i] == 0) {
            q.push({i, 1});
            res[i] = 1;
        }
    }

    while (!q.empty()) {
        int curIdx = q.front().first;
        int curRet = q.front().second;
        q.pop();

        for (int i = 0; i < adj[curIdx].size(); i++) {
            int idx = adj[curIdx][i];
            preCnt[idx]--;

            if (preCnt[idx] == 0) {
                q.push({idx, curRet + 1});
                res[idx] = curRet + 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << res[i] << " ";
    }

    return 0;
}