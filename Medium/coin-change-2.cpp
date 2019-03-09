#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int len=coins.size();
        int dp[len+1];
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for (int i=0;i<len;i++){
            for (int j=amount;j>=coins[i];j--){
                dp[j]=dp[j]+dp[j-coins[i]];
            }
        }        
        return dp[amount];
    }
};

