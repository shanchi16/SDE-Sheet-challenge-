int solve(vector<int>& arr, int pages){
    int stu=1, currPage=0;
    for(int i=0; i<arr.size(); i++){
        if(currPage + arr[i] <= pages) currPage+=arr[i];
        else stu++, currPage = arr[i];
    }
    return stu;
}

int Solution::books(vector<int> &A, int B) {
    int low=INT_MIN, high=0;
    int n = A.size();
    // if no of student > no of books available, return -1;
    if( B > n) return -1;
    for(int it:A){
        high+=it;
        if(it>low) low = it;
    }
    
    
    while(low <= high){
        int mid = low + (high-low)/2;
        int stu = solve(A, mid);
        if(stu <= B) high = mid-1;
        else low = mid+1;
    }
    return low;
}
