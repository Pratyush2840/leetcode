class DisjointSet {
public:
    vector<long long> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        DisjointSet ds(n);
        unordered_map<int, vector<int>> adj;
        for (vector<int>& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int, vector<int>> val_to_nodes;
        for (int i = 0; i < n; i++) {
            val_to_nodes[vals[i]].push_back(i);
        }
        int result = n;
        vector<bool> is_active(n, false);
        for (auto& it : val_to_nodes) {
            vector<int> nodes = it.second;
            for (int u : nodes) {
                for (int v : adj[u]) {
                    if (is_active[v]) {
                        ds.unionBySize(u, v);
                    }
                }
                is_active[u] = true;
            }
            vector<int> parents;
            for (int u : nodes) {
                parents.push_back(ds.findUPar(u));
            }
            sort(parents.begin(), parents.end());
            int sz = parents.size();
            for (int j = 0; j < sz; j++) {
                long long count = 0;
                int cur_parent = parents[j];
                while (j < sz && parents[j] == cur_parent) {
                    count++;
                    j++;
                }
                j--;
                result += (count * (count - 1)) / 2;
            }
        }
        return result;
    }
};