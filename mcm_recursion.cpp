#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> arr,int i,int j){

    //base case
    if(i >= j){
        return 0;
    }
    int minCost = INT_MAX;

    for(int k = i;k <= j - 1;k++){

        int temp = solve(arr,i,k) + solve(arr,k+1,j) + (arr[i - 1] * arr[k] * arr[j]);

        minCost = min(minCost,temp);
    }
    return minCost;
}

int main(){
   
   vector<int> arr = {40,20,30,10,30};

   int i = 1, j = arr.size() - 1;

   int ans = solve(arr,i,j);

   cout<<ans<<endl;

    return 0;
}