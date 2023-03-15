#include <bits/stdc++.h>

using namespace std;

int lcs(string s1,string s2,int i,int j,vector<vector<int>>& dp){

    //base case
    if(i == 0 || j == 0)return 0;
    
    if(dp[i][j] != -1){
       return dp[i][j];
    }

    if(s1[i - 1] == s2[j - 1])return dp[i][j] = 1 + lcs(s1,s2,i-1,j-1,dp);

    else{
         return dp[i][j] = max(lcs(s1,s2,i-1,j,dp),lcs(s1,s2,i,j-1,dp));
    }
}

int main(){

    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    
   
    int i = s1.size(), j = s2.size();

    vector<vector<int>> dp(i+1,vector<int>(j+1,-1)); 
   
    int ans = lcs(s1,s2,i,j,dp);

    cout<<ans<<endl;

    return 0;
}