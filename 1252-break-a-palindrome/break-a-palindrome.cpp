class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();
        if(n<=1)return "";
        int first = -1;
        int last =-1;
        for(int i = 0 ; i < n ; i++){
            if(palindrome[i] > 'a'){
                if(first == -1){
                    first = i;
                    last = i;
                }
                else if(last == first){
                    last =i;
                }
            }
        }
        if(first == -1){
            palindrome[n-1] = 'b';
            return palindrome;
        }
        if(n % 2 == 1 && first == n/2){
            if(last == first){
                palindrome[n-1] = 'b';
            }
            else{
                palindrome[last] = 'a';
            }
            return palindrome;
        }
        palindrome[first] = 'a';
        return palindrome;

        
    }
};