#include <iostream>
#include <queue>

using namespace std;

struct File {
	long long x;

	bool operator < (const File& t) const {
		return x > t.x;
	}
};

int T, K;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> K;

		priority_queue<File> pq;
		
		int f;
		for (int i = 0; i < K; i++) {
			cin >> f;
			pq.push({ f });
		}

		long long res = 0;
		
		while (!pq.empty()) {
			if (pq.size() == 1) {
				cout << res << "\n";
				break;
			}

			File cur = pq.top();
			pq.pop();

			File cur2 = pq.top();
			pq.pop();

			res += (cur.x + cur2.x);
			pq.push({ cur.x + cur2.x });
		}
	}

	return 0;
}