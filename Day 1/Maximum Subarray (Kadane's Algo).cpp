#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long longans= 0;

    for(int i=0; i<nums.size(); i++){
        ans+=nums[i];
        maxi = max(ans, maxi);
        if(ans < 0) ans = 0;
    }
    return maxi;
    if (maxi < 0) maxi = 0;

    return maxi;
}

int main()
{
    int arr[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarrayansis: " << maxSum << endl;
    return 0;
}

