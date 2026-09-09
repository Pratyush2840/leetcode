class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        for(auto it : s){
            if(it == '['){
                st.push(it);
            }
            else{
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    st.push(it);
                }
            }
        }
        if(st.empty())return 0;
        int size = st.size();
        // while(!st.empty()){
        //     cout<<st.top()<<' ';
        //     st.pop();
        // }
        if(size == 2)return 1;
        if(size%4 == 0)return size/4;
        return (size+4)/4;
    }
};