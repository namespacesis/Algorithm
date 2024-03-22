#include <iostream>

using namespace std;

int main() {
    int n;
    int res = 0;
    
    while (true) {
        cin >> n;
        if (n == -1) break;
        res += n;
    }
    
    cout << res << "\n";
    return 0;
}