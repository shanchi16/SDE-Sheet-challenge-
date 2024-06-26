
#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int ind=-1, n=nums.size();
    for(int i=n-2; i>=0; i--){
        if(nums[i] < nums[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i=n-1; i>=ind; i--){
        if(nums[i] > nums[ind]){
            swap(nums[i], nums[ind]);
            break;
        }
    }

    sort(nums.begin()+ind+1, nums.end());
}

int main()
{
    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    nextGreaterPermutation(A);

    cout << "The next permutation is: [";
    for (auto it : A) {
        cout << it << " ";
    }
    cout << "]n";
    return 0;
}

