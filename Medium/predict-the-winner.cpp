#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int i = nums.size() - 1; i >= 0; i--) {
            // i为右边界，j为左边界
            for (int j = i + 1; j < nums.size(); j++) {
                // 表示取左边的情况，则要减去右边能取得的最大值
                int a = nums[i] - dp[i + 1][j];
                // 表示取右边的情况，则要减去左边能取得的最大值
                int b = nums[j] - dp[i][j - 1];
                dp[i][j] = max(a, b);
                printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
            }
        }
    return dp[0][nums.size() - 1] >= 0 ? true : false;
    }
};

int main(){
    vector<int> vec={1,4,10,5,3,2};
    Solution sol;
    sol.PredictTheWinner(vec);
}