class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> vis(n , 0);
        vis[0] =1;
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        queue<int> q;
        q.push(0);
        int ans= 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it : adj[node]){
                int next = it.first;
                int cost = it.second;

                if(!vis[next]) {
                    vis[next] = 1;
                    q.push(next);

                    ans += cost;
                }
            }
        }
        return ans;
    }
};