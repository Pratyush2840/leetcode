class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int,vector<int>>> q;
        q.push({0 , {0}});
        vector<vector<int>> ans;
        //unordered_set<int> vis;
        //vis.insert(0);
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            //vis.insert(node);
            vector<int> temp = it.second;
            if(node == n-1){
                ans.push_back(temp);
            }
            else{
                for(auto iter : graph[node]){
                    int newnode= iter;
                    temp.push_back(newnode);
                    q.push({newnode , temp});
                    temp.pop_back();
                    
                }

            }
            
        }
        return ans;
    }
};