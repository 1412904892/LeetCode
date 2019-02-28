#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp[i][j]表示 i个1 j个0可以表示的字符串个数
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for (string str:strs){
            int zeros=0,ones=0;
            for (int i=0;i<str.size();i++) {
                if (str[i]=='0') zeros++;
                else ones++;
            }
            
            for (int i=m;i>=zeros;i--){
                for (int j=n;j>=ones;j--){
                    dp[i][j]=max(dp[i][j],dp[i-zeros][j-ones]+1);
                }
            }
        }
       
        return dp[m][n];
    }
};

int main(){

}