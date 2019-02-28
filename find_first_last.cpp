#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        //寻找第一次出现的位置
        int first=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if (mid==0 && nums[mid]==target){ 
                first=mid; 
                break;
            }
            else if (nums[mid]==target && nums[mid-1]!=target) {
                first=mid;
                break;
            }
            else if (nums[mid]>=target) high=mid-1;
            else if (nums[mid]<=target) low=mid+1;
        }

        int last=-1;
        low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            //cout<<"mid="<<mid<<endl;
            if (mid==nums.size()-1 && nums[mid]==target){
               // cout<<"first\n";
                last=mid;
                break;
            }
            else if (nums[mid]==target && nums[mid+1]!=target){
                last=mid;
                //cout<<"second\n";
                break;
            }
            else if (nums[mid]<=target) low=mid+1;
            else if (nums[mid]>=target) high=mid-1;
        }
        vector<int> vec;
        vec.push_back(first);
        vec.push_back(last);
       // cout<<first<<' '<<last<<endl;
        return vec;
    }
};

int main(){
    vector<int> vec={3};
    Solution sol;
    sol.searchRange(vec,3);
}