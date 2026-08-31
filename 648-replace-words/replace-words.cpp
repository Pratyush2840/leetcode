class Solution {
public:
    struct trienode{
        bool isend;
        trienode* children[26];
    };
    trienode* root ;
    Solution() {
        root = new trienode();
    }
    trienode* getnode(){
        trienode* node = new trienode();
        node->isend = false;
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
            } 
        }
        crawler->isend = true;
    }

    string search(string word) {
        trienode*  crawler = root;
        int ind;
        string ans = "";
        for(auto it : word){
            ind = it - 'a';
            if(crawler->children[ind] == NULL){
                break;
            }
            else{
                crawler= crawler->children[ind];
                ans += it;
                if(crawler->isend == true)return ans;
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        for(auto it :  dictionary){
            insert(it);
        }
        string temp ="";
        string ans = "";
        for(auto it : sentence){
            if(it != ' '){
                temp += it;
            }
            else{
                ans += search(temp);
                ans += " ";
                temp = "";
            }
        }
        ans += search(temp);

        return ans;
    }
};