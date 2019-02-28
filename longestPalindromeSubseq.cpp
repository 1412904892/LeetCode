#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[s.length()][s.length()];
        memset(dp,0,sizeof dp);
        int len=s.length();
        for (int i=len-1;i>=0;i--){
            dp[i][i]=1;
            for (int j=i+1;j<len;j++){
                if (s[i]==s[j]){
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][len-1];
    }
};

class MyClass{
    public:
        MyClass(int i=0){cout<<1;}
        MyClass(const MyClass&x){cout<<2;}
        MyClass& operator=(const MyClass&x){cout<<3; return*this;}
        ~MyClass(){cout<<4;}
};
int main(){
    MyClass obj1(1),obj2(2);
    return 0;
}