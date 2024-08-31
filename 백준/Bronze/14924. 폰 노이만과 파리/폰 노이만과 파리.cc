#include <iostream>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int S, T, D;

int main() {
    FastIO;

    cin >> S >> T >> D;

    cout << D / (S * 2) * T << "\n";

    return 0;
}
