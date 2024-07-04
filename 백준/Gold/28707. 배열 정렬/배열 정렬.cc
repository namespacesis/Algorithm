#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

struct Control {
    int l;
    int r;
    int c;
};

int N, M;

int main() {
    FastIO;

    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

    cin >> M;

    vector<Control> controls(M);

    for (int i = 0; i < M; i++) {
        int l, r, c;
        
        cin >> l >> r >> c;

        controls[i] = {l - 1, r - 1, c};
	}
    
    priority_queue<pair<int, vector<int>>> pq;
    map<vector<int>, int> dist;

    pq.push({0, A});

    while (!pq.empty()) {
        auto [cost, state] = pq.top();
        pq.pop();

        if (dist[state] >= -cost) {
            for (int i = 0; i < M; i++) {
                auto [l, r, c] = controls[i];

                swap(state[l], state[r]);

                if (!dist.count(state) || dist[state] > -cost + c) {
                    dist[state] = -cost + c;
                    pq.push({ cost - c, state });
                }

                swap(state[l], state[r]);
            }
        }
    }

    sort(A.begin(), A.end());

    cout << (dist.count(A) ? dist[A] : -1) << "\n";

    return 0;
}