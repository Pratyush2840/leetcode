class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        stack<char>st;
        char temp1;
        char temp2;
        if(x>y){
            temp1= 'b';
            temp2='a';
        }
        else{
            temp1 = 'a';
            temp2 ='b';
        }
        int ans=0;
        int z = max(x,y);
        for(auto it : s){
            if(it != temp1){
                st.push(it);
            }
            else{
                if(!st.empty() && st.top() == temp2){
                    ans += z;
                    st.pop();
                }
                else{
                    st.push(it);
                }
            }
        }
        string update ="";
        while(!st.empty()){
            update += st.top();
            //cout<<st.top()<<endl;
            st.pop();
        }
        reverse(update.begin() , update.end());
        // for(auto it : update){
        //     cout<<it<<endl;
        // }
        for(auto it : update){
            if(it != temp2){
                st.push(it);
            }
            else{
                if(!st.empty() && st.top() == temp1){
                    ans += min(x,y);
                    st.pop();
                }
                else{
                    st.push(it);
                }
            }
        }
        return ans;
    }
};