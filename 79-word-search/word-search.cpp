class Solution {
public:
    int n ,m;
    bool backtrack(int i ,int j ,int ind , vector<vector<char>>& board , string& word){
        if(i<0 || j<0 || i>= n || j >= m || board[i][j] == '$')return false;
        if(board[i][j] != word[ind])return false;
        if(board[i][j] == word[ind] && ind == word.size()-1)return true;

        int delrow[] = {0,1,0,-1};
        int delcol[] = {1,0,-1,0};
        int temp = board[i][j];
        board[i][j] ='$';
        for(int iter = 0 ;iter<4;iter++){
            int new_i = i + delrow[iter];
            int new_j = j + delcol[iter];
            if(new_i >=0 && new_i <n && new_j >=0 && new_j < m && board[new_i][new_j] != '$'){
                if(board[new_i][new_j] == word[ind+1]){
                    if(backtrack(new_i,new_j,ind+1 , board,word))return true;
                }
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    if(backtrack(i,j,0,board,word))return true;
                }
            }
        }
        return false;
    }
};