class Solution {
public:
    typedef long long ll;
    long long wonderfulSubstrings(string word) {
        unordered_map<ll,ll> mp;
        mp[0] = 1;
        int cum_xor = 0;
        ll result = 0;

        for(char &ch : word){
            int shift = ch - 'a';
            cum_xor  ^= (1<<shift);
            result += mp[cum_xor];
            for(char c = 'a' ; c <= 'j' ; c++){
                shift = c -'a';
                ll check_xor = (cum_xor ^ ( 1<< shift));
                result += mp[check_xor];
            }
            mp[cum_xor]++;
        }
        return result;
    }
};