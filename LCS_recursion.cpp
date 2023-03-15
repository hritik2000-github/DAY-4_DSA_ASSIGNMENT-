#include <bits/stdc++.h>

using namespace std;

int lcs(string s1,string s2,int i,int j){

    //base case
    if(i == 0 || j == 0)return 0;

    if(s1[i - 1] == s2[j - 1])return 1 + lcs(s1,s2,i-1,j-1);

    else{
         return max(lcs(s1,s2,i-1,j),lcs(s1,s2,i,j-1));
    }
}

int main(){

    string s1 = "ABCDGH";
    string s2 = "AEDFHR";
    
    int i = s1.size(), j = s2.size();
    int ans = lcs(s1,s2,i,j);

    cout<<ans<<endl;

    return 0;
}