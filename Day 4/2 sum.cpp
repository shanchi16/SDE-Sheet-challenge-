#include <bits/stdc++.h>
using namespace std;

vector<int> twoSumm(vector<int>& nums, int target) {
    vector<int> ans;
    for(int i = 0; i<nums.size(); i++){
        int sum = nums[i];
        for(int j = i+1; j<nums.size(); j++){
            sum = sum+nums[j];
            if(sum == target){
                ans.push_back(i);
                ans.push_back(j);
                break;
            }else{
                sum = nums[i];
            }
        }
    }
    return ans;

    // time complexity = O(n^2), space complexity = O(1)
}
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for(int i=0; i<nums.size(); i++){
        int temp = nums[i];
        int req = target-temp;
        if(mp.find(req) != mp.end()){
            return {i, mp[req]};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
    
    // time complexity = O(n), space complexity = O(n)
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(arr, target);
    cout << "This is the answer for optimised approach: " << ans[0] << " "<< ans[1] << endl;
    return 0;
}