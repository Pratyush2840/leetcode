class Solution {
public:
    vector<int> ans;
    unordered_map <int, vector<int>> adj;
    vector<int> dfs(int node , int n ,int parent, string & labels){
        vector<int> v(26,0);
        char cur = labels[node];

        for(auto it  :adj[node]){
            if(it == parent)continue;
            vector<int> temp = dfs(it,n, node,labels);
            for(int i = 0 ;i < 26 ;i++){
                v[i] += temp[i];
            }
        }
        v[cur - 'a']++;
        ans[node] = v[cur-'a'];
        return v;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.assign(n,0);
        adj.clear();
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> temp = dfs(0,n,-1,labels);
        return ans;
        
    }
};