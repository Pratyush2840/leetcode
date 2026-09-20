class Solution {
public:
    void dfs(int node , unordered_map<int,vector<pair<int,int>>> &adj , int & result , unordered_set<int> & vis){
        vis.insert(node);
        for(auto it : adj[node]){
            auto adj_node = it.first;
            int dis = it.second;
            if(!vis.count(adj_node)){
                dfs(adj_node , adj,result,vis);
            }
            result = min(result,dis);
        }
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        int result = INT_MAX;
        unordered_set<int> vis;
        dfs(1 , adj , result , vis);
        return result;
    }
};