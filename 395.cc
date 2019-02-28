#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size()==0 || k<0) return 0;
        int times[26];
        memset(times,0,sizeof times);
        for (int i=0;i<s.length();i++){
            times[s[i]-'a']++;
        }

        int split_pos=-1;
        for (int i=0;i<s.length();i++){
            if (times[s[i]-'a']<k){
                split_pos=i;
            }
        }

        if (split_pos==-1) return s.length();
        int maxLen=0;
        
        maxLen=max(longestSubstring(s.substr(0,split_pos),k) ,longestSubstring(s.substr(split_pos+1,s.length() ),k));
        return maxLen;
    }
};

int main(){
    string s="ababbc";
    Solution sol;
    sol.longestSubstring(s,2);
}