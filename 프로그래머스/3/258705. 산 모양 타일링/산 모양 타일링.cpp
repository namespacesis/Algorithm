#include <string>
#include <vector>
#define MOD 10007
using namespace std;

int dp[100001][2];

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    dp[0][1] = 1;
    
    for (int i = 0; i < n; i++) {
        int top = tops[i];
        int idx = i + 1;
        dp[idx][0] = (dp[i][0] + dp[i][1]) % MOD;
        
        if (top == 0) {
            dp[idx][1] = (dp[i][0] + dp[i][1] * 2) % MOD;
        }
        else {
            dp[idx][1] = (dp[i][0] * 2 + dp[i][1] * 3) % MOD;
        }
    }
    
    answer = (dp[n][0] + dp[n][1]) % MOD;
        
    return answer;
}