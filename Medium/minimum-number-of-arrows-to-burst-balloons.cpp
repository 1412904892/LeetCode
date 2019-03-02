#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    static bool cmp(pair<int,int> &pa,pair<int,int> &pb){
        if (pa.second==pb.second) return pa.first<pb.first;
        return pa.second<pb.second;
    }
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(),points.end(),cmp);

        int shot_pos=__INT_MAX__;
        int ans=0;
        for (int i=0;i<points.size();i++){
            if (shot_pos!=__INT_MAX__ && points[i].first<=shot_pos){
                continue;
            }
            shot_pos=points[i].second;
            ans++;
        }
        return ans;
    }
};

int main()
{
    vector<pair<int, int>>vec;
    vec.push_back({ 10,16 });
    vec.push_back({ 2,8 });
    vec.push_back({ 1,6 });
    vec.push_back({ 7,12 });
    Solution sol;
    sol.findMinArrowShots(vec);
}

