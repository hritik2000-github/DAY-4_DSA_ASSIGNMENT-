#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> weight,vector<int> value,int w,int n,vector<vector<int>>& dp){
  //base case
  if(n == 0 || w == 0){
    return 0;
  }
  
  if(dp[n][w] != -1)return dp[n][w];

  if(weight[n-1] <= w){
    int included = value[n-1] + knapsack(weight,value,w-weight[n-1],n-1,dp);
    int notIncluded = knapsack(weight,value,w,n-1,dp);

    return dp[n][w] = max(included,notIncluded);
  }
  else{
    return dp[n][w] = knapsack(weight,value,w,n-1,dp);
  }
}

int main(){

    vector<int> weight = {10,20,5,90};
    vector<int> value = {5,50,6,9000};
    
    int w = 20;
    int n = weight.size();
    
    vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    int ans = knapsack(weight,value,w,n,dp);

    cout<<ans<<endl;

    return 0;
}