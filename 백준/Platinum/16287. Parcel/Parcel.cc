#include <bits/stdc++.h>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

bool is_possible[800001]; 
int arr[5005];
int W, N;

int main() {
    FastIO;

    cin >> W >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int current_sum = arr[i] + arr[j];
            int remain = W - current_sum;

            if (remain >= 0 && remain <= 800000 && is_possible[remain]) {
                cout << "YES" << endl;
                return 0;
            }
        }
        
        for (int j = 0; j < i; j++) {
            int prev_sum = arr[i] + arr[j];
            if (prev_sum <= W) {
                is_possible[prev_sum] = true;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}