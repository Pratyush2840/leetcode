class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n = expression.size();
        stack <char> st;
        stack<int> opt;
        int i = 0;
        while(i < n){
            char it = expression[i];
            if(it == '&' || it == '|' || it == '!'){
                opt.push(it); 
            }
            else if(it == 't'){
                st.push(1);
            }
            else if(it == 'f'){
                st.push(0);
            }
            else if(it == '('){
                st.push(-1);
            }
            else if( it == ','){
                
            }
            else{
                int ans = 0;
                char operation = opt.top();
                opt.pop();
                char cur = st.top();
                st.pop();
                //negation
                if(operation == '!'){
                    st.pop();
                    st.push((cur ^ 1));
                    i++;
                    continue;
                }
                ans = cur;
                while(!st.empty() && st.top() != -1){
                    if(operation == '&'){
                        ans = ans & st.top();
                        st.pop();
                    }
                    else{
                        ans = ans | st.top();
                        st.pop();
                    }
                }
                st.pop();
                st.push(ans);
            }
            i++;
        }
        return st.top();
    }
};