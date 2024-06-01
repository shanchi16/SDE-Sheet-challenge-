#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int buy = prices[0], sell=-1, profit=0;
    for(int i=1; i<prices.size(); i++){
        if(prices[i] < buy) buy = prices[i];
        profit = max(profit, prices[i]-buy);
    }
    return profit;
}

int main() {
    vector<int> arr = {7,1,5,3,6,4};
    int maxPro = maxProfit(arr);
    cout << "Max profit is: " << maxPro << endl;
}

