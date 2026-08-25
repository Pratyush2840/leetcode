class Solution {
public:  
    int n;
    void backtrack(string tiles,int idx,unordered_set<string>&result,vector<bool>&used,string &cur){
        result.insert(cur);
        for(int i=0;i<n;i++){
          if(used[i])continue;
          used[i]=true;
          cur.push_back(tiles[i]);
          backtrack(tiles,idx+1,result,used,cur);
          used[i]=false;
          cur.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        n=tiles.size();
        string cur="";
        unordered_set<string>result;
        vector<bool>used(n,false);
        backtrack(tiles,0,result,used,cur);
        return result.size()-1;
    }
};