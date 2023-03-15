#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> arr,int i,int j,vector<vector<int>>& dp){

    //base case
    if(i >= j){
        return 0;
    }
    if(dp[i][j] != -1)return dp[i][j];
    
     dp[i][j] = INT_MAX;

    for(int k = i;k <= j - 1;k++){

        int temp = solve(arr,i,k,dp) + solve(arr,k+1,j,dp) + (arr[i - 1] * arr[k] * arr[j]);

        dp[i][j] = min(dp[i][j],temp);
    }
    return dp[i][j];
}

int main(){
   
   vector<int> arr = {40,20,30,10,30};

   int i = 1, j = arr.size() - 1;

   vector<vector<int>> dp(j+1,vector<int>(j+1,-1));
   int ans = solve(arr,i,j,dp);

   cout<<ans<<endl;

    return 0;
}