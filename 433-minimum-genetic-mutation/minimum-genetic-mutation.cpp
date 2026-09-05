class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n =  startGene.size();
        unordered_set<string> bankset;
        for(int i = 0 ; i < bank.size() ; i++){
            bankset.insert(bank[i]);
        }
        unordered_set<string> visited;
        queue<string> q;
        q.push(startGene);
        int ans = 0;
        visited.insert(startGene);
        while(!q.empty()){
            int length = q.size();

            while(length--){
                auto cur = q.front();
                q.pop();
                visited.insert(cur);
                for(auto c: "ACGT"){
                    for(int i = 0 ; i < 8 ; i++){
                        string temp = cur;
                        temp[i] = c;
                        if(bankset.find(temp) != bankset.end() && visited.find(temp) == visited.end()){
                            if(temp == endGene){
                                return ans+1;
                            }
                            q.push(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};