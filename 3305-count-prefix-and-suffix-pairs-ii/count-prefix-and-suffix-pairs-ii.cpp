class Solution {
public:
    struct TrieNode {
        unordered_map<int, TrieNode*> next;
        int count = 0;
    };

    long long countPrefixSuffixPairs(vector<string>& words) {

        TrieNode* root = new TrieNode();

        long long res = 0;

        for (const string& w : words) {

            TrieNode* x = root;
            int n = w.size();

            for (int i = 0; i < n; i++) {

                int key = w[i] * 128 + w[n - 1 - i];

                if (x->next.find(key) == x->next.end()) {
                    x->next[key] = new TrieNode();
                }

                x = x->next[key];

                res += x->count;
            }

            x->count++;
        }

        return res;
    }
};