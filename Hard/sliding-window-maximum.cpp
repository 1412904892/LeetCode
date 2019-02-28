#include <deque>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res; //保存最终的结果
        deque<int> que; //存放每个元素的下标 而不是这个元素本身

        for(int i=0;i<nums.size();i++){
            if (!que.empty() && i>=que.front()+k){
                que.pop_front();
            }

            while (!que.empty() && nums[i]>=nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);

            if (i+1>=k){
                res.push_back(nums[que.front()]);
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> vec={2,3,4,2,6,2,5,1};
    vector<int> ans=sol.maxSlidingWindow(vec,3);
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
}