class Solution {
public:
    struct trienode{
        int count;
        trienode* children[26];
    };
    trienode* root ;
    Solution() {
        root = new trienode();
    }
    trienode* getnode(){
        trienode* node = new trienode();
        node->count  = 1;
        for(int i=0;i<26;i++){
            node->children[i] = NULL;
        }
        return node;
    }
    
    void insert(string word) {
        trienode*  crawler = root;
        int ind;
        for(auto it : word){
            ind = it - 'a';
            if(crawler->children[ind] == NULL){
                crawler->children[ind] = getnode();
                crawler = crawler->children[ind];
            }
            else{
                crawler = crawler->children[ind];
                crawler->count++;
            } 
        }
    }

    int search(string word) {
        trienode*  crawler = root;
        int ind;
        for(auto it : word){
            ind = it - 'a';
            if(crawler->children[ind] == NULL){
                return 0;
            }
            else{
                crawler = crawler->children[ind];
            }
        }
        return crawler->count;
    }
    int prefixCount(vector<string>& words, string pref) {
        for(auto it : words){
            insert(it);
        }
        int ans = search(pref);
        return ans;
    }
};