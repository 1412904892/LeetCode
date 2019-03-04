#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
这个方法时间复杂度为O(logN)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0,high=nums.size()-1;
        cout<<"lkdsngkjhg\n";
        while (low<high){
            int mid=(low+high)/2;

            if (mid%2==0){
                if (nums[mid]==nums[mid+1]){
                    low=mid+2;
                }
                else if (nums[mid]==nums[mid-1]){
                    high=mid-2;
                }
                else return nums[mid];
            }
            else{
                if (nums[mid]==nums[mid+1]){
                    high=mid-1;
                }
                else if (nums[mid]==nums[mid-1]){
                    low=mid+1;
                }
                else return nums[mid];
            }
        }
        return nums[low];
    }
};
*/
//虽然这种方法是O(N)的时间复杂度，但是通过的时间却比上面的那种要少
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res=0;
        int len=nums.size();
        for (int i=0;i<len;i++){
            res^=nums[i];
        }
        return res;
    }
};
int main(){
    vector<int> vec={1,1,2,3,3,4,4,5,5};
    Solution sol;
    cout<<sol.singleNonDuplicate(vec);
    return 0;
}