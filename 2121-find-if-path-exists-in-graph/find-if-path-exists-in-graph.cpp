class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)return true;
        unordered_map<int,vector<int>> adj;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        q.push(source);
        unordered_set<int> vis;
        while(!q.empty()){
            auto it = q.front();q.pop();
            for(auto it : adj[it]){
                if(it == destination)return true;
                if(vis.count(it) ==0){
                    vis.insert(it);
                    q.push(it);
                }
            }
        }
        return false;
    }
};