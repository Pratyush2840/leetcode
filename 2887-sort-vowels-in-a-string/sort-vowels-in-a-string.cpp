class Solution {
public:
    string sortVowels(string s) {
        multiset<char> st;
        for(auto it : s){
            if( it == 'A' || it == 'E'|| it == 'I'|| it == 'O'|| it == 'U'|| it == 'a'|| it == 'e'|| it == 'i'|| it == 'o'|| it == 'u'){
                st.insert(it);
            }
        }
        string ans = "";
        for(auto it : s){
            if( it == 'A' || it == 'E'|| it == 'I'|| it == 'O'|| it == 'U'|| it == 'a'|| it == 'e'|| it == 'i'|| it == 'o'|| it == 'u'){
                ans += *st.begin();
                st.erase(st.begin());
            }
            else{
                ans += it;
            }
        }
        return ans;
    }
};