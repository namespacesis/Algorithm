#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
unordered_map<string, int> um;
set<string> s;

int main() {
	FastIO;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		s.insert(str);
		um[str]++;
	}

	int cnt = 0;

	string res;

	for (auto& iter : s) {
		if (um[iter] > cnt) {
			cnt = um[iter];
			res = iter;
		}
	}

	cout << res << "\n";

	return 0;
}
