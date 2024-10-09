#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end());
    
    vector<vector<int>> res;
    
    for (int i = 0; i < routes.size(); i++) {
        if (res.empty()) {
            res.push_back(routes[i]);
        }
        else {
            bool check = false;
            for (int j = 0; j < res.size(); j++) {
                if ((res[j][0] <= routes[i][0] && routes[i][0] <= res[j][1]) ||
                    (res[j][0] <= routes[i][1] && routes[i][1] <= res[j][1])) {
                    vector<int> v;
                    v.push_back(max(res[j][0], routes[i][0]));
                    v.push_back(min(res[j][1], routes[i][1]));
                    res[j] = v;
                    check = true;
                    break;
                }
            }
            if (!check) {
                res.push_back(routes[i]);
            }
        }
    }
    
    answer = res.size();
    
    return answer;
}