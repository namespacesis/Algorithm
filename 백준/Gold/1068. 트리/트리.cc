#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;
vector<int> arr[50];
int root;
int delNode;
bool visited[50];
int res = 0;

void dfs(int idx) {
    visited[idx] = true;

    bool flag = false;

    for (int i = 0; i < arr[idx].size(); ++i) {
        int nxtNode = arr[idx][i];
        if (visited[nxtNode]) continue;

        flag = true;
        visited[nxtNode] = true;
        dfs(nxtNode);
    }

    if (!flag) res++;
}

int main() {
    FastIO;

    cin >> N;

    int p;

    for (int i = 0; i < N; ++i) {
        cin >> p;
        if (p == -1) {
            root = i;
            continue;
        }
        arr[p].push_back(i);
    }

    cin >> delNode;

    visited[delNode] = true;

    if (!visited[root]) {
        dfs(root);
    }

    cout << res << endl;
    
    return 0;
}