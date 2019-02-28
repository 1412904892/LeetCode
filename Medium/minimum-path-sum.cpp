#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size()==0) return 0;
        int dp[grid.size()][grid[0].size()];
        memset(dp,0,sizeof dp);
        dp[0][0]=grid[0][0];
        for (int i=1;i<grid[0].size();i++) dp[0][i]=grid[0][i]+dp[0][i-1];
        for (int i=1;i<grid.size();i++) dp[i][0]=dp[i-1][0]+grid[i][0];
        /*
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        */

        for (int i=1;i<grid.size();i++){
            for (int j=1;j<grid[0].size();j++){
                dp[i][j]=min(dp[i-1][j]+grid[i][j],dp[i][j-1]+grid[i][j]);
            }
        }
        /*
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        */
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main(){
    vector<vector<int>> vec;
    vec.push_back({1,3,1});
    vec.push_back({1,5,1});
    vec.push_back({4,2,1});
    Solution sol;
    sol.minPathSum(vec);
    return 0;
}