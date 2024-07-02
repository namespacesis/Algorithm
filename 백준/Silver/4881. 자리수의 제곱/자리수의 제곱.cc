#include <iostream>
#include <unordered_map>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define MAX 1e9

int sumOfSquares(int a) {
    int result = 0;
    while (a > 0) {
        int digit = a % 10;
        result += digit * digit;
        a /= 10;
    }
    return result;
}

int main() {
    FastIO;

    int a, b;
    while (cin >> a >> b && (a != 0 || b != 0)) {
        cout << a << " " << b << " ";

        unordered_map<int, int> sequenceA, sequenceB;

        for (int i = 1; !sequenceA.count(a); i++) {
            sequenceA[a] = i;
            a = sumOfSquares(a);
        }

        for (int i = 1; !sequenceB.count(b); i++) {
            sequenceB[b] = i;
            b = sumOfSquares(b);
        }

        int result = MAX;

        for (const auto& [num, indexA] : sequenceA) {
            if (sequenceB.count(num)) {
                result = min(result, indexA + sequenceB[num]);
            }
        }

        if (result == MAX) {
            cout << "0\n";
        }
        else {
            cout << result << "\n";
        }
    }

    return 0;
}