class Solution {
public:
    string orderlyQueue(string s, int k) {

        if (k >= 2) {
            sort(s.begin(), s.end());
            return s;
        }

        string ans = s;

        for (int i = 1; i < s.size(); i++) {
            string temp = s.substr(i) + s.substr(0, i);

            if (temp < ans) {
                ans = temp;
            }
        }

        return ans;
    }
};