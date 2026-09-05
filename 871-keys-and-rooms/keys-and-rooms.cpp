class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_map<int,vector<int>> adj;
        for(int i=0;i<n;i++){
            for(auto it : rooms[i]){
                adj[i].push_back(it);
            }
        }
        queue<int>q;
        q.push(0);
        unordered_set<int> vis;
        vis.insert(0);
        while(!q.empty()){
            auto it = q.front();q.pop();
            for(auto it : adj[it]){
                if(vis.find(it) == vis.end()){
                    q.push(it);
                    vis.insert(it);
                }
            }
        }
        if(vis.size() == n)return true;
        return false;
        
    }
};