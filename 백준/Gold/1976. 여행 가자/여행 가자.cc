#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N, M;
int parent[201];

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (a < b) parent[b] = a;
        else parent[a] = b;
    }
}

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int connected;
            cin >> connected;
            if (connected == 1) {
                unite(i, j);
            }
        }
    }

    int start_city;
    cin >> start_city;
    int root = find(start_city);

    bool possible = true;
    for (int i = 1; i < M; i++) {
        int next_city;
        cin >> next_city;
        
        if (root != find(next_city)) {
            possible = false;
            break;
        }
    }

    if (possible) cout << "YES" << "\n";
    else cout << "NO" << "\n";

    return 0;
}