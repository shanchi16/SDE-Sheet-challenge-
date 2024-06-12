class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        // using binary search
        int left=0, right=nums.size()-1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(mid%2 == 1) mid--;
            if(nums[mid] == nums[mid+1]) left=mid+2;
            else right=mid;
        }

        // using XOR operation
        // int ans = 0;
        // for(int i=0; i<nums.size(); i++){
        //     ans^=nums[i];
        // }
        // return ans;

        return nums[left];
    }
};