class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
        int len = 0;
        int n = nums.size();
        int total = accumulate(begin(nums), end(nums), 0);
        int sum=0;  
        unordered_map<int,int> presum;
        presum[0] = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            presum[sum] = i;
        }
        int k = total - x;
        if(k < 0 ||  x>total) return -1;
        if(k == 0) return nums.size();

        // now get the longest subarray sum equal k then (n-len) is required ans 
        sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            int val = sum-k;
            if(presum.find(val) != presum.end()){
                if(val == 0) len = max(len, i-presum[val]+1);
                else len = max(len, i-presum[val]);
            }
        }

        return len==0 ? (k==0 ?n :-1) : n-len;
    }
};