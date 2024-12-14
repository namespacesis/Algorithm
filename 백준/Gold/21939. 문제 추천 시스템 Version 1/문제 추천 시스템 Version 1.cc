#include <iostream>
#include <unordered_map>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

struct Node {
    int P;
    int L;

    bool operator<(const Node& n) const {
        if (L == n.L) return P < n.P;
        return L < n.L;
    }
};

struct Node2 {
    int P;
    int L;

    bool operator<(const Node2& n) const {
        if (L == n.L) return P > n.P;
        return L > n.L;
    }
};

int N;
int M;
unordered_map<int, int> um;
priority_queue<Node> pq1;
priority_queue<Node2> pq2;

int main() {
    FastIO;

    cin >> N;

    int P, L;
    for (int i = 0; i < N; i++) {
        cin >> P >> L;
        pq1.push({P, L});
        pq2.push({P, L});
        um[P] = L;
    }

    cin >> M;

    string query;
    for (int i = 0; i < M; i++) {
        cin >> query;

        if (query == "add") {
			cin >> P >> L;
			pq1.push({P, L});
			pq2.push({P, L});
			um[P] = L;
		} else if (query == "recommend") {
			cin >> L;

			if (L == 1) {
                while (true) {
                    Node n = pq1.top();
                    pq1.pop();
                    if (um[n.P] == n.L) {
                        pq1.push(n);
                        cout << n.P << endl;
                        break;
                    }
                }
			} else {
                while (true) {
                	Node2 n = pq2.top();
					pq2.pop();
                    if (um[n.P] == n.L) {
                        pq2.push(n);
                        cout << n.P << endl;
                        break;
                    }
                }
			}
		} else {
			cin >> P;
			um[P] = -1;
		}
    }

    return 0;
}
