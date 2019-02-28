#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int LCS(char str1[],char str2[]){
    int dp[strlen(str1)+1][strlen(str2)+1];
    memset(dp,0,sizeof dp);

    for (int i=1;i<=strlen(str1);i++){
        for (int j=1;j<=strlen(str2);j++){
            if (str1[i-1]==str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[strlen(str1)][strlen(str2)];
}

int main(){
    char str1[100];
    char str2[100];
    cin>>str1>>str2;
    int len=strlen(str2)-strlen(str1);
    int num1=0;
    int ans=__INT_MAX__;
    //在前面添加
    for (int i=0;i<=len;i++){
        num1=0;
        for (int ind=0;ind<strlen(str1);ind++){
            if (str1[ind]!=str2[ind+i]) num1++;
        }
        ans=min(ans,num1);
    }
    cout<<ans<<endl;
    return 0;
}