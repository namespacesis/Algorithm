#include <iostream>

using namespace std;

int arr[10];

int main() {
	for (int i = 0; i < 5; i++) {
		int a;
		cin >> a;

		arr[a]++;
	}

	for (int i = 0; i < 10; i++) {
		if (arr[i] % 2 == 1) {
			cout << i << "\n";
			break;
		}
	}

	return 0;
}
