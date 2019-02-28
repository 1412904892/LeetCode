#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size()==0) return {};
        sort(nums.begin(),nums.end());
        int dp[nums.size()+1];
        for (int i=0;i<nums.size();i++) dp[i]=1;

        for (int i=1;i<nums.size();i++){
            int index=i-1;
            while (index>=0){
                if (nums[i]%nums[index]==0) {
                    dp[i]=max(dp[i],dp[index]+1);
                }
                index--;
            }
            
        }
        int max_nums=0;
        int max_time=0;
        for (int i=0;i<nums.size();i++) {
            if (dp[i]>max_time){
                max_time=dp[i];
                max_nums=nums[i];
            }
        }
        vector<int> vec;
        for (int i=nums.size()-1;i>=0;i--){
            if (max_nums%nums[i]==0 && max_time==dp[i]){
                vec.push_back(nums[i]);
                max_time--;
            }
            
        }
        return vec;
    }
};

int main(){
    vector<int> vec={4,8,10,240};
    Solution sol;
    vector<int> vecc=sol.largestDivisibleSubset(vec);
    for (int i=0;i<vecc.size();i++) cout<<vecc[i]<<endl;
    return 0;
}