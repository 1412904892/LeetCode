#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> m;
        m[0]=1;

        int sum=0,res=0;
        int len_num=nums.size();
        for (int i=0;i<len_num;i++){
            sum+=nums[i];
            if (m[sum-k]!=0){
                res+=m[sum-k];
            }
            m[sum]++;
        }
        return res;
    }

};


int main(){
    vector<int> vec={-1,-1,1};
    Solution sol;
    cout<<sol.subarraySum(vec,0);
}