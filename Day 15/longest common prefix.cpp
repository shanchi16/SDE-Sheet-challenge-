class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int  len = strs[0].size();
        int j = 0; bool flag = true;
        while(j<len){
            
            for( int i = 0; i<strs.size()-1; i++){
                if(strs[i][j] != strs[i+1][j]){
                    flag = false;
                    break;
                }else{
                    flag = true;
                }
            }
            if(flag){
                j++;
            }else{
                break;
            }
        
        }

        return strs[0].substr(0,j);
        
    }
};