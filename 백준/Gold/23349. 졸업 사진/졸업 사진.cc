#include <iostream>
#include <unordered_map>
#include <algorithm>

#define FastIO ios::sync_with_stdio(false), cin.tie(nullptr);
#define endl '\n'

using namespace std;

int N;
unordered_map<string, bool> um;
unordered_map<string, int> place2idx;
unordered_map<int, string> idx2place;
int arr[50000][10];
vector<string> names;

int main() {
    FastIO;

    cin >> N;

    int idx = 0;

    for (int i = 0; i < N; i++) {
        string name;
        string place;
        int t1, t2;

        cin >> name >> place >> t1 >> t2;
        if (um[name]) continue;

        um[name] = true;

        int id;
        
        if (place2idx.find(place) == place2idx.end()) {
            id = idx;
            place2idx[place] = idx;
            idx2place[idx] = place;
            idx++;
        }
        else {
            id = place2idx[place];
        }

        for (int i = t1; i < t2; i++) {
            arr[i][id]++;
        }
    }

    int maxCnt = 0;

    for (int i = 0; i < 50000; i++) {
        for (int j = 0; j < idx; j++) {
            if (arr[i][j] > maxCnt) {
                names.clear();
                names.push_back(idx2place[j]);
                maxCnt = arr[i][j];
            }
            else if (arr[i][j] == maxCnt) {
                bool flag = false;
                for (auto name : names) {
                    if (name == idx2place[j]) {
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    names.push_back(idx2place[j]);
                }
			}
        }
    }

    sort(names.begin(), names.end());

    string ans = names[0];

    int id = place2idx[ans];

    int ansT1 = -1;
    int ansT2 = -1;

    for (int i = 0; i < 50000; i++) {
		if (ansT1 == -1 && arr[i][id] == maxCnt) {
            ansT1 = i;
		}
        if (ansT1 != -1 && arr[i][id] != maxCnt) {
            ansT2 = i;
            break;
        }
	}

    cout << ans << " " << ansT1 << " " << ansT2 << endl;

    return 0;
}
