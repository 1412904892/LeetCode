#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        map<int,int> times;
        
        int hand_len=hand.size();
        if (hand_len%W!=0) return false;
        sort(hand.begin(),hand.end());

        for (int i=0;i<hand_len;i++){
            times[hand[i]]++;
        }

        for (auto it:times){
            if (it.second>0){
                for (int k=W-1;k>=1;k--){
                    times[it.first+k]-=times[it.first];
                    if (times[it.first+k]<0) return false;
                }
            }
        }
        return true;
    }
};

