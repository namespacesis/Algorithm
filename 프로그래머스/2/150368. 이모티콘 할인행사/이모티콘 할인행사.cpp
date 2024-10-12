#include <string>
#include <vector>

using namespace std;

int combiSize;
int res1 = 0;
int res2 = 0;
double discount[4] = {0.9, 0.8, 0.7, 0.6};
int dispercent[4] = {10, 20, 30, 40};
vector<string> v;

void combi(string idx) {
    if (idx.size() == combiSize) {
        v.push_back(idx);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        combi(idx + to_string(i));
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    combiSize = emoticons.size();
    
    combi("");
    
    for (int i = 0; i < v.size(); i++) {
        int temp1 = 0;
        int temp2 = 0;
        for (int u = 0; u < users.size(); u++) {
            int temp3 = 0;
            for (int j = 0; j < combiSize; j++) {
                int idx = v[i][j] - '0';
                double price = discount[idx] * emoticons[j];
                if (users[u][0] <= dispercent[idx]) {
                    temp3 += price;
                    if (temp3 >= users[u][1]) {
                        temp3 = 0;
                        temp1++;
                        break;
                    }
                }
            }
            if (temp3 < users[u][1]) {
                temp2 += temp3;
            }
        }
        if (temp1 >= res1) {
            if (temp1 > res1) {
                res2 = temp2;
            }
            res1 = temp1;
            if (temp2 >= res2) {
                res2 = temp2;
            }
        }
    }
    
    answer.push_back(res1);
    answer.push_back(res2);
    
    return answer;
}