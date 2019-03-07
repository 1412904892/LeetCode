#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int move[S.length()+1];
        memset(move,0,sizeof  move);

        int len_shift=shifts.size();

        for (int i=len_shift-1;i>=0;i--){
            move[i]=(move[i+1]+shifts[i])%26;
        }

        int len_S=S.length();
        for (int i=0;i<len_S;i++){
            S[i]=(S[i]-'a'+move[i])%26+'a';
        }
        return S;
    }
};
int main(){
    string S="ruu";
    vector<int> vec={26,9,17};
    Solution sol;
    cout<<sol.shiftingLetters(S,vec);
    return 0;
}
