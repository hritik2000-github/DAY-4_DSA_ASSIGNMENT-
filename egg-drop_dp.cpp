#include <bits/stdc++.h>

using namespace std;

int solve(int n,int f,vector<vector<int>>& dp){

    //base case
    if(f == 0 || f == 1 || n == 1){
        return f;
    }

    if(dp[n][f] != -1)return dp[n][f];

    dp[n][f] = INT_MAX;

    for(int k = 1;k <= f;k++){
        int temp = max(solve(n-1,k-1,dp),solve(n,f-k,dp)) + 1;
        dp[n][f] = min(dp[n][f],temp);
    }
    return dp[n][f];
}

int main(){

    int n = 2;
    int f = 10;
    
    vector<vector<int>> dp(n+1,vector<int>(f+1,-1));

    int ans = solve(n,f,dp);

    cout<<ans<<endl;
}