#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int numDecodings(string s){
    int dp[s.length()+1];
    memset(dp,0,sizeof dp);
    dp[0]=0;
    dp[1]=1;
    if (s[0]=='0') return 0;
    for (int i=2;i<=s.length();i++){
        if (s[i-1]!='0'){
            dp[i]=dp[i-1];
        }
        if (s[i-2]=='1'||s[i-2]=='2'&&s[i-1]<='6'){
            if (i==2) dp[i]=dp[i]+1;
            else dp[i]=dp[i]+dp[i-2];
        }
    }
    return dp[s.length()];
}
int main(){
    string str;
    getline(cin,str);
    cout<<numDecodings(str)<<endl;
    return 0;
}