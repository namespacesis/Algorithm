#include <bits/stdc++.h>

using namespace std;

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

int A, B, C;
int arr[101];

int main() {
    FastIO;

    cin >> A >> B >> C;

    int s1, s2;

    int res = 0;

    for (int i = 0; i < 3; i++) {
        cin >> s1 >> s2;
        for (int j = s1; j < s2; j++) {
            arr[j]++;
        }
    }

    for (int i = 1; i <= 100; i++) {
        if (arr[i] == 1) res += A;
        else if (arr[i] == 2) res += 2*B; 
        else if (arr[i] == 3) res += 3*C;
    }

    cout << res << endl;

    return 0;
}