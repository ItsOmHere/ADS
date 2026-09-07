#include<iostream>
#include<vector>
using namespace std;

bool subsetSum(vector<int>& arr, int n, int sum, vector<int>& subset){
    if(sum == 0) return true;

    if(n == 0) return false;

    if(arr[n-1] <= sum){
        subset.push_back(arr[n-1]);

        if(subsetSum(arr, n - 1, sum - arr[n-1], subset)) return true;

        subset.pop_back();
    }

    return subsetSum(arr,n-1,sum,subset);
}

int main(){
    vector<int> arr = {3,34,4,12,5,2};
    int sum = 9;

    vector<int> subset;
    subsetSum(arr, arr.size(), sum, subset);

    cout<<"Subset: ";

    for(int x: subset)
        cout<<x<<" ";
    
    return 0;
   
}