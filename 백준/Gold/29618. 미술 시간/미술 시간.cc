#include <iostream>
#include <set>
#include <queue>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N, Q;
set<int> s;
queue<int> q;
int res[100001];

int main() {
    FastIO;

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
		s.insert(i);
	}

    while (Q--) {
        int a, b, x;
        cin >> a >> b >> x;

        auto it = s.lower_bound(a);

		while (it != s.end() && *it <= b) {
            res[*it] = x;
            q.push(*it);
            it++;
		}

        while (!q.empty()) {
            s.erase(q.front());
            q.pop();
        }
    }

    for (int i = 1; i <= N; i++) {
		cout << res[i] << " ";
	}

    return 0;
}
