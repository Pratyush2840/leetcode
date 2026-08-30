class Solution {
public:
    struct trienode{
        trienode* children[10];
    };
    trienode* root ;
    Solution() {
        root = new trienode();
    }
    trienode* getnode(){
        trienode* node = new trienode();
        for(int i=0;i<10;i++){
            node->children[i] = NULL;
        }
        return node;
    }
    
    void insert(int n) {
        string word  = to_string(n);
        trienode*  crawler = root;
        int ind;
        for(auto it : word){
            ind = it - '0';
            if(crawler->children[ind] == NULL){
                crawler->children[ind] = getnode();
            }
            crawler = crawler->children[ind];
        }
    }
    
    int search(int n) {
        string word  = to_string(n);
        trienode*  crawler = root;
        int ind;
        int ans =0;
        for(auto it : word){
            ind = it - '0';
            if(crawler->children[ind] == NULL){
                return ans;
            }
            crawler = crawler->children[ind];
            ans++;
        }
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n  = arr1.size();
        int m = arr2.size();
        int ans = INT_MIN;
        for(auto it : arr1){
            insert(it);
        }
        for(auto it : arr2){
            ans = max(ans,search(it));
        }
        return ans;
    }
};