#include <iostream>
#include <vector>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;

int main() {
    FastIO;

    cin >> N;

    vector<int> v;
    
    int n;
    cin >> n;
    v.push_back(n);

    for (int i = 1; i < N; i++) {
        cin >> n;
        
        if (v.back() < n) {
            v.push_back(n);
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), n);
            *it = n;
        }
    }

    int res = v.size();

    cout << res << endl;

    return 0;
}