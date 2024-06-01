
#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int l=0, m=0, h=nums.size()-1;
    while(m <= h){
        if(nums[m] == 2){
            swap(nums[m], nums[h]);
            h--;
        }else if(nums[m] == 0){
            swap(nums[m], nums[l]);
            l++;
            m++;
        }else m++;
    }
}

int main()
{
    int n = 6;
    vector<int> nums = {0, 2, 1, 2, 0, 1};
    sortColors(nums, n);
    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}

