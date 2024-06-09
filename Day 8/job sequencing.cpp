struct Job + 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comp(Job a, Job b){
        return (a.profit > b.profit) ;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, comp);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, arr[i].dead);
        }
        vector<int> v(maxi+1, -1);
        int total = 0, jobs = 0;
        
        for(int i=0; i<n; i++){
            int deadline = arr[i].dead;
            for(int j=deadline; j>=1; j--){
                if(v[j] == -1){
                    total+=arr[i].profit;
                    v[j] = arr[i].id;
                    jobs++;
                    break;
                }
            }
        }
        
        
        
        return {jobs, total};
    } 
};