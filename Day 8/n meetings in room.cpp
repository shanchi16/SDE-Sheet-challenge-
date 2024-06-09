class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[end[i]] = start[i];
        }
        
        int cnt = 0; int last = 0;
        
        for(auto i:mp){
            if(i.second > last) {
                cnt++;
                last = i.first;
            }
        }
        
        return cnt;
    }
};