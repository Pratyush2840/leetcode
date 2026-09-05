class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<pair<char,int>> st;
        for(int i = 0 ; i <n;i++){
            if(s[i] == '('){
                st.push({'(' , i});
            }
            else if(s[i] == ')'){
                if(!st.empty() && st.top().first == '('){
                    st.pop();
                }
                else{
                    st.push({')' , i});
                }
            }
        }
        while(!st.empty()){
            auto node = st.top();
            st.pop();
            s.erase(node.second,1);
        }
        return s;
    }
};