class Solution {
public:
    void mergeSortedArrays(vector<int>& nums1, vector<int>& nums2, vector<int>& ans){
        int i =0, j=0;
        while(i<nums1.size() && j< nums2.size()){
            if(nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i < nums1.size()){
            ans.push_back(nums1[i]);
            i++;
        }
        while( j< nums2.size()){
            ans.push_back(nums2[j]);
            j++;
        }
    }


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        mergeSortedArrays(nums1, nums2, ans);
        int n = ans.size();
        double median=0;
        if(n%2 == 0){
            int i=n/2;
            median = ((double)ans[i-1]+(double)ans[i])/2;
        }else{
            int i=n/2;
            median = ans[i];
        }
        return median;
    }
};