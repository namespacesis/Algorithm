#include <iostream>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int A, B;
unordered_map<int, int> um;

int main() {
	FastIO;

	cin >> A >> B;

	for (int i = 0; i < A; i++) {
		int num;
		cin >> num;
		um[num]++;
	}

	for (int i = 0; i < B; i++) {
		int num;
		cin >> num;
		um[num]++;
	}

	int res = 0;

	for (auto& i : um) {
		if (i.second == 1) {
			res++;
		}
	}

	cout << res << "\n";

	return 0;
}
