#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;


int A, B;
int N;
int arr[5];

int main() {
    FastIO;

    cin >> A >> B;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    
    int res = 0;

    int tmp = abs(B - A);

    for (int i = 0; i < N; ++i) {
        int tmp2 = abs(B - arr[i]);

        if (tmp2 < tmp) {
            res = 1;
            tmp = tmp2;
        }
    }

    res += tmp;

    cout << res << endl;

    return 0;
}