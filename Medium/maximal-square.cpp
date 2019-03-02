#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0) return 0;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        int ans=0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                if(matrix[i-1][j-1]=='1'){
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};