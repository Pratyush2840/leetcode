class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = s.size();

        vector<long long> diff_arr(n + 1, 0);

        for(int i = 0; i < n; i++) {
            diff_arr[0] += shifts[i];
            diff_arr[i + 1] -= shifts[i];
        }

        long long curr = 0;

        for(int i = 0; i < n; i++) {
            curr += diff_arr[i];
            curr %= 26;

            if(curr < 0)
                curr += 26;

            int letter = s[i] - 'a';

            letter = (letter + curr) % 26;

            s[i] = letter + 'a';
        }

        return s;
    }
};