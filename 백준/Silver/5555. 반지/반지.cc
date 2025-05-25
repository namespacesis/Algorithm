#include <iostream>
#include <string>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

string s;
int N;

int main() {
    FastIO;

	cin >> s;

	int l = s.length();

	cin >> N;

	int res = 0;

	for (int i = 0; i < N; i++) {
		string t;
		cin >> t;

		int tl = t.length();

		t += t;

		for (int j = 0; j < tl; j++) {
			if (t.substr(j, l) == s) {
				res++;
				break;
			}
		}
	}

	cout << res << endl;

	return 0;
}
