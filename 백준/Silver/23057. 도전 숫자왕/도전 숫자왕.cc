#include <iostream>
#include <vector>
#include <set>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;
vector<int> v;
set<int> s;
int M = 0;

int main() {
    FastIO;

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        M += num;
        v.push_back(num);

        for (int n : s) {
            v.push_back(n + num);
        }

        for (int n : v) {
			s.insert(n);
		}

        v.clear();
    }

    int res = M - s.size();

    cout << res << endl;

    return 0;
}