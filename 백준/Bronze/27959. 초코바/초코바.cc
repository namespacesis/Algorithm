#include <iostream>

using namespace std;

int N, M;

int main() {
	cin >> N >> M;
	if (N * 100 >= M) cout << "Yes" << "\n";
	else cout << "No" << "\n";
    return 0;
}