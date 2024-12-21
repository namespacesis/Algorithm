#include <iostream>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

struct Node {
    int D, H;
    int info;
    int idx;

    bool operator<(const Node& n) const {
        if (D == n.D) {
            if (H == n.H) {
                return idx > n.idx;
            }
            return H < n.H;
        }
        return D < n.D;
    }
};

int N, M, K;
queue<Node> q[100001];
priority_queue<Node> pq;

int main() {
    FastIO;

    cin >> N >> M >> K;

    int info = K + 1;

    for (int i = 1; i <= N; i++) {
        int D, H;
        cin >> D >> H;

        int idx = i % M;
        if (idx == 0) idx = M;

        q[idx].push({D, H, i, idx});
    }

    int res = 0;

    for (int i = 1; i <= M; i++) {
        if (q[i].empty()) continue;

        pq.push(q[i].front());
        q[i].pop();
    }

    while (true) {
        Node cur = pq.top();
        pq.pop();

        if (cur.info == info) {
            break;
        }

        res++;

        if (q[cur.idx].empty()) continue;
        pq.push(q[cur.idx].front());
        q[cur.idx].pop();
    }

    cout << res << endl;

    return 0;
}