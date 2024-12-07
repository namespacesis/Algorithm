#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N;
vector<int> arrP;
vector<int> arrM;
int idx = 0;
long long res = 0;

void solve() {
    sort(arrM.begin(), arrM.end());
    sort(arrP.begin(), arrP.end(), greater<int>());

    while (arrP.size() && arrM.size()) {
        int p = arrP.back() - idx;
        int m = idx - arrM.back();

        if (m <= p) {
            idx = arrM.back();
            res += m;
            arrM.pop_back();
        }
        else {
            idx = arrP.back();
            res += p;
            arrP.pop_back();
        }
    }

    while (arrP.size()) {
        int p = arrP.back() - idx;
        idx = arrP.back();
        res += p;
        arrP.pop_back();
    }

    while (arrM.size()) {
        int m = idx - arrM.back();
        idx = arrM.back();
        res += m;
        arrM.pop_back();
    }
}

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int q;
        cin >> q;

        if (q == 1) {
            int n;
            cin >> n;

            if (n >= idx) {
                arrP.push_back(n);
            }
            else {
                arrM.push_back(n);
            }
        }
        else {
            solve();
        }
    }

    cout << res << endl;

    return 0;
}
