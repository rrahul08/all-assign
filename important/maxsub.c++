#include<iostream>
#include<vector>
using namespace std;

int maxsubarray(vector<int> arr,int n){
    int sum=0;
    int maxi=INT_MIN;

    for(auto it:arr){
        sum += it;
        maxi=max(sum,maxi);
        if(sum<0) sum=0;
    }

    return maxi;
}

int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = maxsubarray(arr, n);

    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}