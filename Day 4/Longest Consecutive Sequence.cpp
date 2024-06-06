#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if(n <= 1) return n;
    int maxi = INT_MIN, cnt=1;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i+1] - nums[i] == 1){
            cnt++;
        }
        else if(nums[i+1] - nums[i] == 0) ;
        else cnt = 1; 

        maxi = max(cnt, maxi);
    }
    return maxi;
    // time complexity: O(nlogn), space complexity: O(1)
}
int main(){
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}
