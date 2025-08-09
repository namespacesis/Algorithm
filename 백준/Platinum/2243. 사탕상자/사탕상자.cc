#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

const int MAX_TASTE = 1000001;
int N;
ll tree[4 * MAX_TASTE];

void update(int node, int start, int end, int idx, int diff) {
    if (idx < start || idx > end) return;

    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, idx, diff);
        update(node * 2 + 1, mid + 1, end, idx, diff);
    }
}

int query(int node, int start, int end, int rank) {
    if (start == end) {
        return start;
    }

    int mid = (start + end) / 2;
    ll left_sum = tree[node * 2];

    if (rank <= left_sum) {
        return query(node * 2, start, mid, rank);
    }
    else {
        return query(node * 2 + 1, mid + 1, end, rank - left_sum);
    }
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int A;
        cin >> A;

        if (A == 1) {
            int B;
            cin >> B;

            int taste = query(1, 1, MAX_TASTE - 1, B);
            cout << taste << endl;

            update(1, 1, MAX_TASTE - 1, taste, -1);
        } else {
            int B, C;
            cin >> B >> C;
            update(1, 1, MAX_TASTE - 1, B, C);
        }
    }

    return 0;
}