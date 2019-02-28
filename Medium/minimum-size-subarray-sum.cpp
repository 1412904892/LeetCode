#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int pre=__INT_MAX__;
        if (nums.size()==0) return 0;
        int sum[nums.size()+1];
        memset(sum,0,sizeof sum);
        int len=nums.size();
        for (int i=0;i<len;i++){
            sum[i+1]=sum[i]+nums[i];
        }

        for (int i=1;i<=len;i++){
            cout<<sum[i]<<' ';
        }
        cout<<endl;

        int num=0;
        for (int k=0;k<len;k++){
            for (int i=1;i<=len-k;i++){
                num=sum[i+k]-sum[i-1];
                if (num>=s) return k+1;
            }
        }
        return 0;
    }
};
int main(){
    vector<int> vec={2,3,1,2,4,3};
    Solution sol;
    cout<<sol.minSubArrayLen(7,vec);
    return 0;
}