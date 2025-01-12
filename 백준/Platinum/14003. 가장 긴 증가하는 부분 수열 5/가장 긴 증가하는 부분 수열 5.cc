#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    vector<long long> v;
    vector<int> idx(N);
    vector<int> parent(N, -1);

    v.push_back(A[0]);
    idx[0] = 0;
    int length = 1;

    for(int i = 1; i < N; i++){
        if(A[i] > v.back()){
            parent[i] = idx[length - 1];
            v.push_back(A[i]);
            idx[length] = i;
            length++;
        }
        else {
            auto it = lower_bound(v.begin(), v.end(), A[i]);
            int pos = it - v.begin();

            *it = A[i];
            idx[pos] = i;

            if(pos > 0){
                parent[i] = idx[pos - 1];
            }
        }
    }

    cout << length << "\n";
    
    vector<long long> ans;
    int cur = idx[length - 1];
    while(cur != -1){
        ans.push_back(A[cur]);
        cur = parent[cur];
    }
    reverse(ans.begin(), ans.end());

    for(auto &x : ans){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
