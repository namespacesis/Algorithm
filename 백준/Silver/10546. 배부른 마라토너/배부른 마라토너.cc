#include <iostream>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
unordered_map<string, int> um;

int main() {
	FastIO;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		um[str]++;
	}

	for (int i = 0; i < N - 1; i++) {
		string str;
		cin >> str;
		um[str]--;
	}

	for (auto& iter : um) {
		if (iter.second != 0) {
			cout << iter.first << "\n";
			break;
		}
	}

	return 0;
}
