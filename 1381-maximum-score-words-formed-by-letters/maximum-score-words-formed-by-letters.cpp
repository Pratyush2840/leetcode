class Solution {
public:
    map<string,int> points;
    map<char,int> mp;
    int ans =0;
    int n;

    void solve(int ind , int temp ,vector<string>& words, vector<char>& letters, vector<int>& score ){
        if(ind  == n){
            ans  = max(ans,temp);
            return;
        }
        //nottake
        solve(ind+1 , temp , words,letters,score);
        int flag= 0;
        int index=0;
        for(int iter = 0 ; iter < words[ind].size() ;iter++){
            if(mp[words[ind][iter]] <1){
                flag=1;
                break;
            } 
            index++;
            mp[words[ind][iter]]--;
        }
        for(int iter =0 ;iter < index ; iter++){
            mp[words[ind][iter]]++;
        }
        //take
        if(!flag){
            for(auto it : words[ind]){
                mp[it]--;
            }
            solve(ind+1 , temp + points[words[ind]] , words,letters,score);
            //revert
            for(auto it : words[ind]){
                mp[it]++;
            }
        }
        
        return;
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        for(auto it : letters){
            mp[it]++;
        }
        for(auto it : words){
            int point =0;
            for(auto c: it){
                point += score[c - 'a'];
            }
            points[it] = point;
        }
        int temp =0;
        solve(0,temp,words,letters,score);
        return ans;

    }
};