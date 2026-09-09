class Solution {
public:
    int n;
    unordered_map<int, vector<int>> adj;
    int dfs(int node, string &s, vector<int> &arr) {
        int longest1 = 0;
        int longest2 = 0;
        for (auto child : adj[node]) {
            int childPath = dfs(child, s, arr);
            if (s[child] == s[node])
                continue;

            if (childPath > longest1) {
                longest2 = longest1;
                longest1 = childPath;
            }
            else if (childPath > longest2) {
                longest2 = childPath;
            }
        }
        arr[node] = 1 + longest1 + longest2;
        return 1 + longest1;
    }
    int longestPath(vector<int>& parent, string s) {
        n = parent.size();
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }
        vector<int> arr(n, 0);
        dfs(0, s, arr);
        return *max_element(arr.begin(), arr.end());
    }
};