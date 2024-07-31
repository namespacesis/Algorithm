#include <iostream>
#include <string>
#include <unordered_map>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

using namespace std;

int N;
string arr[1000];
unordered_map<string, bool> check;
int res = 0;

int main() {
    FastIO;

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        check[arr[i]] = false;
    }

    int idx = 0;

    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        while (check[arr[idx]] == true) {
			idx++;
		}

        if (arr[idx] != temp) {
            res++;
        }

        if (arr[idx] == temp) {
            idx++;
        }

        check[temp] = true;
    }

    cout << res << "\n";

    return 0;
}
