#include <iostream>
#include <set>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
set<string> s;

int main() {
	FastIO;

	cin >> N;

	int res = 0;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "ENTER") {
			res += s.size();
			s.clear();
		}
		else {
			s.insert(str);
		}
	}

	res += s.size();

	cout << res << "\n";

	return 0;
}
