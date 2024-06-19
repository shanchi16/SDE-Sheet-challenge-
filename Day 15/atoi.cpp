class Solution {
public:
    int myAtoi(string s) {
        long ans = 0; bool flag = true;
        int i=0, n=s.length();
        while(i<n && s[i] == ' ') i++;
        if(i<n && s[i] == '-') flag = false, i++;
        else if(i<n && s[i] == '+') flag = true, i++;
        for(i; i<n; i++){
            if(s[i] >= '0' && s[i] <='9') {
                ans*=10;
                int t = s[i] - '0';
                ans+=t;
                if(ans > INT_MAX && flag) return INT_MAX;
                else if(ans > INT_MAX && !flag) return INT_MIN;
            }
            else break;
        }
        if(!flag) ans = -ans;
        return ans;
    }
};