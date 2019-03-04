#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        int len_pattern=pattern.length();
        
        for (auto word:words){
            if (word.length()!=len_pattern) continue;
            vector<char> is_visit(26,'*');

            int i;
            for (i=0;i<len_pattern;i++){
                if (is_visit[pattern[i]-'a']=='*'){
                    if (find(is_visit.begin(),is_visit.end(),word[i])!=is_visit.end()) break;
                    else is_visit[pattern[i]-'a']=word[i];
                }
                else if(is_visit[pattern[i]-'a']!=word[i]) break;
            }
            if (i==len_pattern) res.push_back(word);
        }
        return res;
    }
};