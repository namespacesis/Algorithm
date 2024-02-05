#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		if (i == N) { for (int i = 1; i <= 2 * N - 1; i++) cout << "*"; }
		else {
			for (int j = N - i; j > 0; j--) { cout << " "; }
			cout << "*";
			if (i != 1) {
				for (int j = 1; j <= (i - 1) * 2 - 1; j++) { cout << " "; }
				cout << "*";
			}
		}
		cout << "\n";
	}
	return 0;
}