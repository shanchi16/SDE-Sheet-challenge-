bool solve(vector<int>& stalls, int dis, int n, int k){
    int cow = 1, l = stalls[0];
    for(int i=1; i<n; i++){
        if(stalls[i]-l >= dis) {
            l=stalls[i];
            cow++;
        }
    }
    return cow>=k ? true : false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n=stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 0, high = stalls[n-1]-stalls[0];
    while(low<=high) {
        int mid = low + (high-low)/2;
        if(solve(stalls, mid, n, k) == true) {
            low = mid+1;
        }
        else high = mid-1;
        
    }
    return high;
}