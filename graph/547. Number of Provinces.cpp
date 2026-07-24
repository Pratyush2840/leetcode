class Solution {
public:
    void bfs(int i , vector<int> & vis  ,vector<vector<int>>&adj){
        vis[i] =1;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto gg : adj[node]){
                if(!vis[gg]){
                    vis[gg] =1;
                    q.push(gg);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0 ;i < n ; i++){
            for(int j = 0 ; j < n ; j ++){
                if(isConnected[i][j] == 1){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n , 0);
        int count =0;
        for(int i = 0 ; i< n ; i++){
            if(!vis[i]){
                count++;
                bfs(i , vis , adj);
            }
        }
        return count;
    }
};