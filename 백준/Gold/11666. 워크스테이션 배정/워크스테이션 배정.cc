#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

struct Node {
    int a, s;

    bool operator<(const Node &n) const {
		return a < n.a;
	}
};

int N, M;
vector<Node> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    FastIO;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int a, s;
        cin >> a >> s;
        v.push_back({a, s});
    }

    sort(v.begin(), v.end());

    int res = 0;

    for (auto u : v) {
        while (!pq.empty() && pq.top() + M < u.a) {
            pq.pop();
        }

        if (!pq.empty() && pq.top() <= u.a) {
            pq.pop();
            res++;
        }

        pq.push(u.a + u.s);
    }

    cout << res << endl;

    return 0;
}
