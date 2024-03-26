#include <iostream>

using namespace std;

int main() {
	int N;
	
	string star = "*";
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cout << star;
		}
		cout << "\n";
	}
	for (int j = N - 1; j > 0; j--) {
		for (int i = j; i >= 1; i--) {
			cout << star;
		}
		cout << "\n";
	}

	return 0;
}