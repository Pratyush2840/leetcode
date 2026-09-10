class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        if(node1 == node2) return node1;
        int n = edges.size();
        unordered_map<int,int> adj;
        for(int i = 0; i < n; i++){
            adj[i] = edges[i];
        }
        vector<int> visited(n, -1);
        vector<int> vis(n, -1);
        queue<int> q;
        q.push(node1);
        visited[node1] = 0;
        while(!q.empty()){
            int it = q.front();
            q.pop();
            int ad = adj[it];
            if(ad != -1 && visited[ad] == -1){
                visited[ad] = visited[it] + 1;
                q.push(ad);
            }
        }
        q.push(node2);
        vis[node2] = 0;
        while(!q.empty()){
            int it = q.front();
            q.pop();
            int ad = adj[it];
            if(ad != -1 && vis[ad] == -1){
                vis[ad] = vis[it] + 1;
                q.push(ad);
            }
        }
        int ans = -1;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(visited[i] != -1 && vis[i] != -1){
                int dist = max(visited[i], vis[i]);
                if(dist < mini){
                    mini = dist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};