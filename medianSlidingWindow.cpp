#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        if (k>nums.size()||k==0) return result;

        multiset<int> left,right;
        for (int i=0;i<k;i++){
            left.insert(nums[i]);
        }
        while (left.size()>(k+1)/2){
            right.insert(*left.rbegin());
            left.erase(left.find(*left.rbegin()));
        }

        //left 中的元素 多于 right中的元素
        if (k%2==1)
            result.push_back(*left.rbegin());
        else 
            result.push_back((*left.rbegin()*1.0+*right.begin()*1.0)/2);

        for (int i=k;i<nums.size();i++){
            if (nums[i-k]>result.back()) right.erase(right.find(nums[i-k]));
            else left.erase(left.find(nums[i-k]));

            if (!left.empty() && nums[i]<=*left.rbegin()) left.insert(nums[i]);
            else right.insert(nums[i]);

            while (left.size()<(k+1)/2){
                left.insert(*right.begin());
                right.erase(right.begin());
            }

            while (left.size()>(k+1)/2){
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }

            if (k%2==1)
            result.push_back(*left.rbegin());
            else 
            result.push_back((*left.rbegin()*1.0+*right.begin()*1.0)/2);
        }
        return result;
    }
};

int main(){

}