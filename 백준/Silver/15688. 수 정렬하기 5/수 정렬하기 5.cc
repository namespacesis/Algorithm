#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr)
#define endl '\n'
#define ll long long

using namespace std;

int N;
vector<int> arr;

int main() {
    FastIO;

    cin >> N;

    arr.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}