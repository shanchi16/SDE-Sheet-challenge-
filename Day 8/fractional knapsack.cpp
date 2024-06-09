// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    bool static comp(Item a, Item b){
        double temp1 = (double)a.value / (double)a.weight;
        double temp2 = (double)b.value / (double)b.weight;
        return temp1> temp2;
    }
    double fractionalKnapsack(int w, Item arr[], int n) {
        vector<pair<double, double>> mp;
        sort(arr, arr+n, comp); 
        int W = w;
        // mapping the value per weight then sort them in decreasing order
        
        double ans = 0;
        for(int i = 0; i < n; i++){
            if(W > arr[i].weight){
                double temp = (double)arr[i].value ;
                ans+=temp;
                W-= arr[i].weight;
            }
            else if(W>0 ){
                double temp = ((double)arr[i].value / (double)arr[i].weight) * W;
                ans+=temp;
                W=0;
                break;
            }
        }
        
        return ans;
    }
};