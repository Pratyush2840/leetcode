class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = beginWord.size();
        unordered_set<string> wordbank;
        for(auto it : wordList){
            wordbank.insert(it);
        }
        queue<string> q;
        unordered_set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        int ans = 1;
        while(!q.empty()){
            int length = q.size();
            while(length--){
                auto cur = q.front();
                q.pop();
                for(char c = 'a' ; c <= 'z' ; c++){
                    for(int i = 0 ;i <n ; i++){
                        string temp = cur;
                        temp[i] = c;
                        if(wordbank.find(temp) != wordbank.end() && visited.find(temp) == visited.end()){
                            if(temp == endWord){
                                return ans+1;
                            }
                            visited.insert(temp);
                            q.push(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;

    }
};