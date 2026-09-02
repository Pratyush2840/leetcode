class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int ind =0;
        stack<int> st;
        vector<string>ans;
        for(int i =1 ; i<= n ; i++){
            if(ind >= target.size()){
                break;
            }
            st.push(i);
            ans.push_back("Push");
            if(target[ind] != i){
                st.pop();
                ans.push_back("Pop");
            }
            else{
                ind++;
            }
        }
        return ans;
    }
};