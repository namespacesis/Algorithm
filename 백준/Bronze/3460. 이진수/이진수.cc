#include <iostream>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'

int T;

int main() {
    FastIO;

	cin >> T;

	int n;
	
	while (T--) {
		cin >> n;

		int cnt = 0;

		while (n != 0) {
			if (n % 2 == 1) {
				cout << cnt << " ";
			}

			n /= 2;
			cnt++;
		}
		cout << endl;
	}

	return 0;
}
