class MedianFinder {
public:
    priority_queue<int> minp;
    priority_queue<int, vector<int>, greater<int> > maxp;
    MedianFinder() {
    
    }
    
    void addNum(int num) {
        maxp.push(num);
        minp.push(maxp.top());
        maxp.pop();
        int n=minp.size(), m = maxp.size();
        if(n > m){
            maxp.push(minp.top());
            minp.pop();
        }
    }
    
    double findMedian() {
        int n=minp.size(), m = maxp.size();
        if(m>n) return maxp.top();
    
        double temp = (maxp.top() + minp.top())/2.0;
        
        return temp;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */