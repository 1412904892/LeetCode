#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int len1=nums1.size(),len2=nums2.size();
        int count=min(k,len1*len2);
        vector<int> index(len1,0);
        

        vector<pair<int,int>> res;

        while(count--){
            int sum=__INT_MAX__,pos=0;
            for (int i=0;i<len1;i++){
                if (index[i]<len2 && sum> nums1[i]+nums2[index[i]]){
                    sum=nums1[i]+nums2[index[i]];
                    pos=i;
                }
            }
            res.push_back(make_pair(nums1[pos],nums2[index[pos]]));
            index[pos]++;
        }
        return res;
    }
};