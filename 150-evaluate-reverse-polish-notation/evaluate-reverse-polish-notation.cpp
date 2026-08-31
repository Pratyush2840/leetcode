class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans  = 0;
        for(auto it  :tokens){
            if(it == "+"){
                int one = st.top();
                st.pop();
                int two  = st.top();
                st.pop();
                st.push(two + one);
            }
            else if(it == "-"){
                int one = st.top();
                st.pop();
                int two  = st.top();
                st.pop();
                st.push(two - one);
            }
            else if(it == "*"){
                int one = st.top();
                st.pop();
                int two  = st.top();
                st.pop();
                st.push(two * one);
            }
            else if(it == "/"){
                int one = st.top();
                st.pop();
                int two  = st.top();
                st.pop();
                st.push(two/one);
            }
            else{
                int number = stoi(it);
                st.push(number);
            }
            ans = st.top();
        }
        return ans;
    }
};