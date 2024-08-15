#include <iostream>
#include <set>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int A, B;
set<int> s;

int main() {
	FastIO;

	cin >> A >> B;

	for (int i = 0; i < A; i++) {
		int num;
		cin >> num;
		s.insert(num);
	}

	for (int i = 0; i < B; i++) {
		int num;
		cin >> num;
		s.erase(num);
	}

	if (s.empty()) {
		cout << "0\n";
	}
	else {
		cout << s.size() << "\n";
		for (auto i : s) {
			cout << i << " ";
		}
	}

	return 0;
}
