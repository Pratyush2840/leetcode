class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(n + 1);

        for (auto it : dislikes) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n + 1, -1);
        for (int start = 1; start <= n; start++) {
            if (vis[start] != -1)
                continue;
            queue<int> q;
            q.push(start);
            vis[start] = 0;
            while (!q.empty()) {
                int num = q.front();
                q.pop();

                for (auto next : adj[num]) {
                    if (vis[next] == -1) {
                        vis[next] = 1 - vis[num];
                        q.push(next);
                    }
                    else if (vis[next] == vis[num]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};