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

int solve(string s,int index){

    //base case
    if(index == s.size() || isPalindrome(s,index,s.size()-1)){
        return 0;
    }
    int ans = INT_MAX;
    int count = 0;
    for(int i = index;i < s.size();i++){
        if(isPalindrome(s,index,i)){
          count = 1 + solve(s,i+1);
        }
        ans = min(ans,count);
    }
    return ans;
}

int main(){

  string s = "aaba";

  int i = 0, j = s.size() - 1;

  int ans = solve(s,i);

  cout<<ans<<endl;

    return 0;
}