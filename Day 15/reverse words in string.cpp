class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        stack<string> st;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' ' ){
                if(temp.size() > 0){
                    st.push(temp);
                    temp = "";  
                }else continue;
            }
            else {
                temp+=s[i];
            }
        }
        if(temp.length() > 0) st.push(temp);

        string ans="";
        while(!st.empty()){
            string t = st.top();
            st.pop();
            
            ans+=t;
            if(st.empty()) break;
            ans = ans + ' ';
        }

        return ans;
    }
};