class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // using priority queue - heap
        priority_queue<int > pq(nums.begin(), nums.end());
        k--;
        while(k--) pq.pop();
        return pq.top();
    }
};