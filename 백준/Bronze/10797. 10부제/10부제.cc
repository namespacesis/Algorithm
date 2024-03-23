#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int res = 0;
    
    for (int i = 0; i < 5; i++) {
        int a;
        cin >> a;
        
        if (a == n) res++;
    }
    
    cout << res << "\n";
    return 0;
}