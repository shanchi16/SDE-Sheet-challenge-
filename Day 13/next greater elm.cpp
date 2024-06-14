class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        st.push(-1);
        unordered_map<int, int> mp;
        for(int i=nums2.size()-1; i>=0; i--){
            if(nums2[i] < st.top()) {
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
            else{
                while(st.top() != -1 && st.top()<nums2[i]){
                    st.pop();
                }
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
        }
        for(auto [it, i]:mp) cout<<it<< " "<<i<<endl;

        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};