#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s,int i,int j){

    while(i <= j){
        if(s[i] != s[j])return false;

        i++;
        j--;
    }
   return true;
}

int solve(string s,int index,vector<int>& dp){

    //base case
    if(index == s.size() || isPalindrome(s,index,s.size()-1)){
        return 0;
    }
    if(dp[index] != -1)return dp[index];

    dp[index] = INT_MAX;
    int count = 0;
    for(int i = index;i < s.size();i++){
        if(isPalindrome(s,index,i)){
          count = 1 + solve(s,i+1,dp);
        }
        dp[index] = min(dp[index],count);
    }
    return dp[index];
}

int main(){

  string s = "ababbbabbababa";

  int i = 0, j = s.size() - 1;
  int n = s.size();
  vector<int> dp(n,-1);
  int ans = solve(s,i,dp);

  cout<<ans<<endl;

    return 0;
}