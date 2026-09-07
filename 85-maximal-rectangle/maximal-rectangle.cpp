class Solution {
public:
    vector<int> next;
    vector<int> previous;
    int n,m;
    void pse(int ind , stack<pair<int,int>> & st, vector<vector<int>>& matrix ){
        //pse
        previous[0] = -1;
        st.push({0 , matrix[ind][0]});
        for(int i = 1; i < m ; i++){
            while(!st.empty() && matrix[ind][i] <= st.top().second){
                st.pop();
            }
            if(st.empty()){
                previous[i] = -1;
            }
            else{
                previous[i] = st.top().first;
            }
            st.push({i , matrix[ind][i]});
        }
        return;
    }
    void nse(int ind ,stack<pair<int,int>> &st ,vector<vector<int>>& matrix ){
        //nse
        next[m-1] = m;
        st.push({m-1,matrix[ind][m-1]});
        for(int i = m-2 ; i >= 0 ; i--){
            while(!st.empty() && matrix[ind][i] <= st.top().second){
                st.pop();
            }
            if(st.empty()){
                next[i] = m;
            }
            else{
                next[i] = st.top().first;
            }
            st.push({i , matrix[ind][i]});
        }
        return;
    }
    int solve(int ind ,vector<vector<int>>& matrix ){
        stack<pair<int,int>> st;
        next.resize(m);
        previous.resize(m);
        pse(ind, st,matrix);
        while(!st.empty()) {
            st.pop();
        }
        nse(ind ,st,matrix);
        int ans = 0;
        for(int i = 0; i <  m ; i++){
            ans = max(ans , (next[i] - previous[i] - 1) * matrix[ind][i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        n =  matrix.size();
        m = matrix[0].size();
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int j = 0 ; j < m;j++){
            arr[0][j] = matrix[0][j] - '0';
        }
        
        for(int i = 1 ;i  <n ; i++){
            for(int j = 0 ; j < m;j++){
                if(matrix[i][j] == '1')arr[i][j] = arr[i-1][j] + 1;
                else{
                    arr[i][j] =0;
                }
            }
        }
        int ans =0 ;
        for(int i = 0 ; i < n ; i++){
            ans = max(ans, solve(i , arr));
        }
        // for(int i = 0 ;i  <n ; i++){
        //     for(int j = 0 ; j < m;j++){
        //         cout<<arr[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }
        
        return ans;
    }
};