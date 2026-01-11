#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

const int INF = 2000000000;
int N, M;
int arr[100005];
pair<int, int> tree[400005];

pair<int, int> min_node(pair<int, int> a, pair<int, int> b) {
    if (a.first < b.first) return a;
    if (a.first > b.first) return b;
    return (a.second < b.second) ? a : b;
}

pair<int, int> init(int node, int start, int end) {
    if (start == end) {
        return tree[node] = {arr[start], start};
    }
    int mid = (start + end) / 2;
    return tree[node] = min_node(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

pair<int, int> update(int node, int start, int end, int index, int val) {
    if (index < start || index > end) return tree[node];
    if (start == end) {
        return tree[node] = {val, index};
    }
    int mid = (start + end) / 2;
    return tree[node] = min_node(update(node * 2, start, mid, index, val),
                                 update(node * 2 + 1, mid + 1, end, index, val));
}

pair<int, int> query(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return {INF, INF};
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return min_node(query(node * 2, start, mid, left, right),
                    query(node * 2 + 1, mid + 1, end, left, right));
}

int main() {
    FastIO;

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    init(1, 1, N);

    cin >> M;
    while (M--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            update(1, 1, N, a, b);
        } else {
            cout << query(1, 1, N, a, b).second << endl;
        }
    }

    return 0;
}