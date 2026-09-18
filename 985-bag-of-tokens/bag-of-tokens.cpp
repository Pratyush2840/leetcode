class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin() , tokens.end());
        int i = 0 ;
        int j = tokens.size() -1;
        int score = 0;
        while(i <= j){
            if(power >= tokens[i]){
                score++;
                power -= tokens[i];
                i++;
            }
            else{
                if(i!= j && score > 0){
                    score--;
                    power += tokens[j];
                }
                j--;
            }
        }
        return score;
    }
};