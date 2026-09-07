class Solution {
public:
    vector<int> next;
    vector<int> previous;
    int n;
    void pse(stack<pair<int,int>> & st, vector<int>& heights){
        //pse
        previous[0] = -1;
        st.push({0 , heights[0]});
        for(int i = 1; i < n ; i++){
            while(!st.empty() && heights[i] <= st.top().second){
                st.pop();
            }
            if(st.empty()){
                previous[i] = -1;
            }
            else{
                previous[i] = st.top().first;
            }
            st.push({i , heights[i]});
        }
        return;
    }
    void nse(stack<pair<int,int>> &st ,vector<int>& heights){
        //nse
        next[n-1] = n;
        st.push({n-1,heights[n-1]});
        for(int i = n-2 ; i >= 0 ; i--){
            while(!st.empty() && heights[i] <= st.top().second){
                st.pop();
            }
            if(st.empty()){
                next[i] = n;
            }
            else{
                next[i] = st.top().first;
            }
            st.push({i , heights[i]});
        }
        return;
    }
    int largestRectangleArea(vector<int>& heights) {
        n = heights.size();
        stack<pair<int,int>> st;
        next.resize(n);
        previous.resize(n);
        pse(st,heights);
        while(!st.empty()) {
            st.pop();
        }
        nse(st,heights);
        int ans = 0;
        for(int i = 0; i < n ; i++){
            ans = max(ans , (next[i] - previous[i] - 1) * heights[i]);
        }
        return ans;
    }
};