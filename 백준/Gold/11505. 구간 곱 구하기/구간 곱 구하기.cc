#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

const int MOD = 1000000007;
int N, M, K;
vector<ll> arr;
vector<ll> tree;

ll build(int node, int start, int end) {
    if (start == end) {
        return tree[node] = arr[start];
    }

    int mid = (start + end) / 2;
    ll left_product = build(node * 2, start, mid);
    ll right_product = build(node * 2 + 1, mid + 1, end);
    
    return tree[node] = (left_product * right_product) % MOD;
}

void update(int node, int start, int end, int index, ll val) {
    if (start == end) {
        tree[node] = val;
        return;
    }

    int mid = (start + end) / 2;
    if (index <= mid) {
        update(node * 2, start, mid, index, val);
    } else {
        update(node * 2 + 1, mid + 1, end, index, val);
    }

    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

ll query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
        return 1;
    }

    if (left <= start && end <= right) {
        return tree[node];
    }
    
    int mid = (start + end) / 2;
    ll left_product = query(node * 2, start, mid, left, right);
    ll right_product = query(node * 2 + 1, mid + 1, end, left, right);
    
    return (left_product * right_product) % MOD;
}

int main() {
    FastIO;

    cin >> N >> M >> K;

    arr.resize(N + 1);
    tree.resize(N * 4);

    for (int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }

    build(1, 1, N);

    int total_queries = M + K;
    while (total_queries--) {
        int a, b;
        ll c;
        cin >> a >> b >> c;

        if (a == 1) {
            update(1, 1, N, b, c);
            arr[b] = c;
        } else if (a == 2) {
            cout << query(1, 1, N, b, c) << endl;
        }
    }

    return 0;
}