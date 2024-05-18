#include <iostream>

using namespace std;

int main() {
    string N;
    cin >> N;
    if (N[0] == N[1] && N[1] == N[2] && N[0] == '5') {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
    return 0;
}