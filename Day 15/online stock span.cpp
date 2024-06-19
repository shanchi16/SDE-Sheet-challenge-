class StockSpanner {
public:
    stack<pair<int,int> > st;
    StockSpanner() {
    }

    int next(int price) {
        // using stack
        int span = 1;
        while(!st.empty() && st.top().first <= price){
            span+=st.top().second;
            st.pop();
        }
        st.push({price, span});
        return span;
    }

    // using array 
    // vector<int> arr;
    // StockSpanner() {
        
    // }
    
    // int next(int price) {
    //     arr.push_back(price);
    //     int cnt=0, n=arr.size();
    //     for(int i=n-1; i>=0; i--){
    //         if(arr[i] <= price) cnt++;
    //         else break;
    //     }
    //     return cnt;
    // }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */