#include <iostream>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int T;
int N, M;
unordered_map<int, bool> um;

int main() {
	FastIO;

	cin >> T;

	while (T--) {
		um.clear();

		cin >> N;

		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			um[num] = true;
		}

		cin >> M;

		for (int i = 0; i < M; i++) {
			int num;
			cin >> num;
			cout << um[num] << "\n";
		}
	}

	return 0;
}
