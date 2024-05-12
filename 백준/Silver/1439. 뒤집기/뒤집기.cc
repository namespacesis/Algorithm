#include <iostream>

using namespace std;

string S;
int res = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> S;

	for (int i = 0; i < S.size(); i++) {
		if (S[i] != S[i + 1]) {
			res++;
		}
	}

	if (res) {
		res /= 2;
	}

	cout << res << "\n";

	return 0;
}