#include <bits/stdc++.h>

using namespace std;

int knapsack(vector<int> weight,vector<int> value,int w,int n){
  //base case
  if(n == 0 || w == 0){
    return 0;
  }

  if(weight[n-1] <= w){
    int included = value[n-1] + knapsack(weight,value,w-weight[n-1],n-1);
    int notIncluded = knapsack(weight,value,w,n-1);

    return max(included,notIncluded);
  }
  else{
    return knapsack(weight,value,w,n-1);
  }
}

int main(){

    vector<int> weight = {10,20,5,90};
    vector<int> value = {5,50,6,9000};
    
    int w = 20;
    int n = weight.size();

    int ans = knapsack(weight,value,w,n);

    cout<<ans<<endl;

    return 0;
}