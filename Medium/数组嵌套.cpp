#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        bool visited[nums.size()];
        int max_len=1;

        int len_num=nums.size();
        for (int i=0;i<len_num;i++){
            if (max_len>len_num/2) return max_len;

            if (visited[i]==true) continue;

            visited[i]=true;
            int cur_max=1;
            int cur_pos=i;
            while (nums[cur_pos]!=i){
                visited[nums[cur_pos]]=true;
                cur_pos=nums[cur_pos];
                cur_max++;
            }
            max_len=max(cur_max,max_len);
        }
        return max_len;
    }
};