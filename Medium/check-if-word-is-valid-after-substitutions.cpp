#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isValid(string S) {
        if (S.length()<=2) return false;

        stack<char> sta;

        int len=S.length();
        for (int i=0;i<len;i++){
            if (S[i]!='c'){
                sta.push(S[i]);
            }
            else{
                if (sta.size()<2) return false;
                char is_b=sta.top();
                sta.pop();
                char is_a=sta.top();
                sta.pop();
                if (is_a=='a'&&is_b=='b') continue;
                else return false;
            }
        }
        if (sta.size()) return false;
        return true;
    }
};