class Solution {
public:
    bool pl(string& s,int i,int j){
        while(i < j){
            if(s[i] != s[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int sm = 0;
        int mlen = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(pl(s,i,j)){
                    int len = j-i+1;
                    if(len>mlen){
                        mlen = len;
                        sm = i;
                    }
                }
            }
        }

        return s.substr(sm,mlen);
    }
};