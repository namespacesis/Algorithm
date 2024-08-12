#include <iostream>
#include <unordered_set>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
unordered_set<string> us;

int main() {
	FastIO;

	cin >> N;

	int res = 0;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "ENTER") {
			res += us.size();
			us.clear();
		}
		else {
			us.insert(str);
		}
	}

	res += us.size();

	cout << res << "\n";

	return 0;
}
