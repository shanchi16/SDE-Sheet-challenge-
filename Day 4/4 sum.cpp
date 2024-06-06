// leetcode.com/problems/4sum/description/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4){
            return ans;
        }
        
        set<vector<int>> output;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size()-3; i++){
            for(int j = i+1; j<nums.size()-2; j++){
                int k = j+1, l=nums.size()-1 ;
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                while(k<l){
                    if(nums[k]+nums[l] == newTarget){
                        output.insert({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        l--;

                    }else if(nums[k]+nums[l] < newTarget){
                        k++;
                    }else{
                        l--;
                    }
                }
            }
        }
        for( auto it : output){
            ans.push_back(it);
        }
        return ans;
    }
};
