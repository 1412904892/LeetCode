#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if (sum%k!=0 || nums.size()<k) return false;
        int avg=sum/k;
        sort(nums.begin(),nums.end());
        nums.reserve(nums.size());
        vector<bool> vis(nums.size(),false); 
        return DFS(nums,0,avg,k,vis,0);
    }

    bool DFS(vector<int>& nums,int sum,int tar,int k,vector<bool> &vis,int star){
        if (sum==tar){
            return DFS(nums,0,tar,k-1,vis,0);
        }
        if (k==1){
            return true;
        }

        for (int i=star;i<nums.size();i++){
            if (vis[i]==false && nums[i]+sum<=tar){
                vis[i]=true;
                if (DFS(nums,nums[i]+sum,tar,k,vis,i+1)){
                    return true;
                }
                vis[i]=false;
            }
        }
        return false;
    }
};

int main(){
    vector<int> vec={4,5,3,2,5,5,5,1,5,5,5,5,3,5,5,2};
    Solution sol;
    cout<<sol.canPartitionKSubsets(vec,13)<<endl;
}
