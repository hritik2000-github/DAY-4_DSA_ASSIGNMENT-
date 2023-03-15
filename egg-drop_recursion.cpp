#include <bits/stdc++.h>

using namespace std;

int solve(int n,int f){

    //base case
    if(f == 0 || f == 1 || n == 1){
        return f;
    }
    int mini = INT_MAX;

    for(int k = 1;k <= f;k++){
        int temp = max(solve(n-1,k-1),solve(n,f-k)) + 1;
        mini = min(mini,temp);
    }
    return mini;
}

int main(){

    int n = 2;
    int f = 10;

    int ans = solve(n,f);

    cout<<ans<<endl;
}